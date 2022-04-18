from setuptools.command.sdist import sdist as SDistOriginal
from distutils.command.build import build as BuildOriginal
from distutils.command.clean import clean as CleanOriginal
from setuptools import setup, Command
from multiprocessing import cpu_count
from contextlib import contextmanager
from hashlib import sha256
from enum import Enum
from tqdm import tqdm
from glob import glob
import subprocess
import requests
import platform
import tempfile
import string
import shutil
import sys
import os
import re

# Shared libraries
import z3


# TODO: pycache is not excluded?
# TODO: I think our sdists are GPL3?


######################################################################
#                              Globals                               #
######################################################################


# Paths
claripy = os.path.dirname(os.path.abspath(__file__))
native = os.path.join(claripy, "native")

with open(os.path.join(claripy, "VERSION")) as f:
    version = f.read().strip()

# Claricpp library names; these should be in MANIFEST.in
claricpp = "claricpp"


######################################################################
#                              Helpers                               #
######################################################################


class JDict(dict):
    """
    A read-only dict that allows . semantics
    """

    __getattr__ = dict.get
    __setattr__ = None
    __delattr__ = None


@contextmanager
def chdir(new):
    """
    Current working directory context manager
    """
    old = os.getcwd()
    new = os.path.abspath(new)
    try:
        print("cd " + new)
        os.chdir(new)
        yield
    finally:
        print("cd " + old)
        os.chdir(old)


def find_exe(name):
    """
    Akin to bash's which function
    """
    exe = shutil.which(name, mode=os.X_OK)
    if exe is None:
        raise RuntimeError("Cannot find " + name)
    return exe


def cname(x):
    """
    Return the class name of x
    """
    return x.__class__.__name__


class BuiltLib:
    """
    A shared or static library
    """

    install_dir = os.path.join(claripy, "claripy/claricpp")

    def __init__(self, name, build_dir, *, permit_shared, permit_static):
        self.name = name
        self._lic = os.path.join(self.install_dir, "LICENSE." + name.replace(" ", "_"))
        self.build_dir = build_dir
        # Determine extensions
        self._permit_shared = permit_shared
        self._permit_static = permit_static
        self._licensed = False

    def init_license(self, installer, cleaner):
        """
        Install license handling functions
        """
        self._lic_installer = installer
        self._lic_cleaner = cleaner

    def _find_ext(self, where, ext):
        exact = os.path.realpath(os.path.join(where, self.name + ext))
        if os.path.exists(exact):
            return exact
        files = glob(os.path.join(where, self.name) + ".*")
        # Check ext after glob b/c .'s can overlap
        files = [i for i in files if i.endswith(ext)]
        if len(files) == 1:
            return files[0]
        if len(files) > 1:
            print("Found: " + str(files))
            raise RuntimeError(
                "Multiple "
                + self.name
                + " libraries in "
                + where
                + " with the same extension: "
                + ext
                + ": "
                + str(files)
            )

    def _find(self, where):
        """
        Tries to find a library within the directory where
        Will prefer the native file extension type but may permit others
        Static libraries have the lowest preference
        """
        exts = []
        if self._permit_shared:
            ops = platform.system()
            if ops == "Darwin":
                exts.extend([".dylib", ".so"])
            elif ops == "Windows":
                exts.extend([".dll", ".so"])
            else:
                exts.extend([".so", ".dll", ".dylib"])
        if self._permit_static:
            exts.append(".a")
        found = [self._find_ext(where, i) for i in exts]
        found = [i for i in found if i is not None] + [None]
        return found[0]

    def find_installed(self):
        """
        Look for the library in the installation directory
        """
        return self._find(self.install_dir)

    def find_built(self):
        """
        Look for the library in the build directory
        """
        return self._find(self.build_dir)

    def licensed(self, b):
        self._licensed = b

    def install(self):
        """
        Copies the library from build dir to install dir
        """
        assert self._licensed is not None, "Will not install without a license"
        p = self.find_built()
        assert p is not None, "Cannot install a non-built library"
        shutil.copy2(p, self.install_dir)

    def _clean(self, x):
        if x:
            os.remove(x)

    def clean_build(self):
        self._clean(self.find_built())

    def clean_install(self):
        self._clean(self.find_installed())


class SharedLib(BuiltLib):
    """
    A shared library
    """

    def __init__(self, name: str, build_dir: str):
        super().__init__(name, build_dir, permit_shared=True, permit_static=False)


class StaticLib(BuiltLib):
    """
    A shared library
    """

    def __init__(self, name: str, build_dir: str):
        super().__init__(name, build_dir, permit_shared=False, permit_static=True)


def run_cmd_no_fail(*args, **kwargs):
    """
    A wrapper around subprocess.run that errors on subprocess failure
    Returns subprocess.run(args, **kwargs
    """
    args = list(args)
    print("Running command: " + str(args))
    rc = subprocess.run(args, **kwargs)
    if rc.returncode != 0:
        if rc.stdout:
            print(rc.stdout)
        if rc.stderr:
            print(rc.stderr, file=sys.stderr)
        what = os.path.basename(args[0])
        raise RuntimeError(what + " failed with return code: " + str(rc.returncode))
    return rc


def extract(d, f, ext):
    """
    Extract f into d given, the compression is assumed from the extension (ext)
    No leading period is allowed in ext
    """
    if ".tar" in ext:
        import tarfile

        with tarfile.open(f) as z:
            z.extractall(d)
    elif ext == "zip":
        from zipfile import ZipFile

        with ZipFile(f) as z:
            z.extractall(d)
    else:
        raise RuntimeError("Compression type not supported: " + ext)


def build_cmake_target(target, *args):
    """
    Build the target with multiple jobs
    Extra args may be passed to the generator via args
    Run this from the same directory you would the generator
    """
    cmake = [find_exe("cmake"), "--build", "."]
    j = "-j" + str(max(cpu_count() - 1, 1))
    return run_cmd_no_fail(*cmake, j, "--target", target, "--", *args)


def download_checksum_extract(name, where, url, sha, ext):
    """
    Download a file from url, checksum it, then extract it into a temp dir
    Return the temp dir and the files within it
    """
    print("Downloading and hash-verifying " + name + "...")
    hasher = sha256()
    prefix = re.sub(r"\s+", "_", name) + "-"
    fd, comp_f = tempfile.mkstemp(dir=where, prefix=prefix, suffix=ext)
    with os.fdopen(fd, "wb") as f:
        with requests.get(url, allow_redirects=True, stream=True) as r:
            r.raise_for_status()
            as_bytes = {"unit": "B", "unit_scale": True, "unit_divisor": 1024}
            with tqdm(total=int(r.headers["Content-length"]), **as_bytes) as prog:
                chunk_size = 2**16
                for block in r.iter_content(chunk_size=chunk_size):
                    hasher.update(block)
                    f.write(block)
                    prog.update(chunk_size)
    if hasher.hexdigest() != sha:
        raise RuntimeError("Downloaded " + name + " hash failure!")
    # Extract
    raw = tempfile.mkdtemp(dir=where, prefix=prefix + "dir-", suffix=".tmp")
    print("Extracting " + name + " to: " + raw)
    extract(raw, comp_f, ext)
    os.remove(comp_f)
    return raw, glob(os.path.join(raw, "*"))


class CleanLevel(Enum):
    """
    Higher clean levels imply lower clean levels
    Values will be incremented by 1 between levels
    Non-whole values are allowed but may only be referenced in clean functions
    """

    INSTALL = 1
    LICENSE = 2
    BUILT_LIBS = 2.5
    BUILD = 3
    BUILD_DEPS = 3.5
    GET = 4


# 'Member functions' of CleanLevel
setattr(type(CleanLevel.GET), "implies", lambda self, o: self.value >= o.value)
setattr(type(CleanLevel.GET), "inc", lambda self: CleanLevel(self.value + 1))


######################################################################
#                         Dependency Classes                         #
######################################################################


class Library:
    """
    Native dependencies should derive from this
    Subclasses may want to override _get, _build, _install, and _clean
    """

    def __init__(self, get_chk, build_chk, install_chk, *dependencies):
        """
        get_chk, build_chk, and install_chk are dicts to given to _body
        When call .get(), self._done(*i) will be called for i in get_chk
        If all return true, the get stage will be skipped
        Likewise this is true for build_chk/install_chk stages build/install
        Note: If any values in the chk dicts are BuiltLibs, they will be swapped
        for the the .find_built / .find_installed functions as needed
        Subclasses must override _license
        Will only call _get, _build, _license, and _install once
        """
        self._done_set = set()
        self._dependencies = dependencies
        assert self._dep_check(type(self)), "Cyclical dependency found on: " + str(
            type(self)
        )
        # Done check lists
        self._get_chk = dict(get_chk)
        self._build_chk = self._fix_chk(build_chk, "find_built")
        self._install_chk = self._fix_chk(install_chk, "find_installed")

    @staticmethod
    def _fix_chk(d, name):
        """
        Update replace BuiltLib values in d with their name functions
        """
        fix = lambda x: getattr(x, name) if isinstance(x, BuiltLib) else x
        return {i: fix(k) for i, k in d.items()}

    def _dep_check(self, t):
        """
        Return true iff t is not a dependency recursively
        """
        return all([(type(i) != t and i._dep_check(t)) for i in self._dependencies])

    def _done(self, name, path):
        """
        If path is a function, path = path()
        If path exists, note it will be reused and return True
        This will only warn once per path!
        path may be None
        """
        if callable(path):
            path = path()
        ret = False if path is None else os.path.exists(path)
        if path in self._done_set:
            assert ret, path + " used to exist but now does not"
        elif ret:
            print("Reusing existing " + name + ": " + path)
            self._done_set.add(path)
        return ret

    def _call_format(self, x, n):
        return cname(x) + "." + n + "()"

    def _call(self, origin, obj, fn, force, called):
        what = self._call_format(obj, fn)
        if what not in called:
            called.add(what)
            me = self._call_format(self, origin)
            print(me + " invoking " + what)
            getattr(obj, fn)(force, called)
            print("Resuming " + me)

    def _body(self, force, lvl, chk, called):
        """
        A helper function used to automate the logic of invoking dependencies and body
        Note: for lvl = license, license files are force cleaned!
        @param force: True if old files should be purged instead of possibly reused
        @param lvl: The clean level to be used for this
        @param chk: A dict where each entry contains the arguments to give to _done
        @param called: The set of already called methods
        If all calls to self._done pass, skip this stage
        If chk is empty, this stage will not be skipped
        """
        # Clean if needed
        if force:
            self.clean(lvl)
        # Skip if everything is done
        elif len(chk) and all([self._done(*i) for i in chk.items()]):
            return
        # Call dependent levels
        next = None
        lvl_name = lvl.name.lower()
        try:
            next = lvl.inc().name.lower()
        except ValueError:
            pass
        if next is not None:
            self._call(lvl_name, self, next, force, called)
        # Call current level dependencies
        for obj in self._dependencies:
            self._call(lvl_name, obj, lvl_name, force, called)
        getattr(self, "_" + lvl_name)()
        me = self._call_format(self, lvl_name)
        called.add(me)

    def get(self, force, called=None):
        """
        Acquire source files for this class and dependencies
        If force: ignores existing files, else may reuse existing files
        """
        called = set() if called is None else called
        self._body(force, CleanLevel.GET, self._get_chk, called)

    def build(self, force, called=None):
        """
        Build libraries for this class and dependencies
        If force: ignores existing files, else may reuse existing files
        """
        called = set() if called is None else called
        self._body(force, CleanLevel.BUILD, self._build_chk, called)

    def license(self, force, called=None):
        """
        Install library licenses; will call ._license if it has not been called
        If force: ignores existing files, else may reuse existing files
        """
        called = set() if called is None else called
        self._body(force, CleanLevel.LICENSE, {}, called)

    def install(self, force, called=None):
        """
        Install libraries and source files for this class and dependencies
        If force: ignores existing files, else may reuse existing files
        """
        called = set() if called is None else called
        self._body(force, CleanLevel.INSTALL, self._install_chk, called)

    def clean(self, level: CleanLevel):
        """
        Cleans up after the library
        """
        p = lambda x: x.__class__.__name__ + ".clean(" + level.name + ")"
        for i in self._dependencies:
            print(p(self) + " invoking " + p(i))
            i.clean(level)
        self._clean(level)

    def _get(self):
        """
        A function subclasses should override to get source files
        No need to handle dependencies in this
        """
        pass

    def _build(self):
        """
        A function subclasses should override to build libraries
        No need to handle dependencies in this
        """
        pass

    def _license(self):
        """
        A function subclasses must override to install licenses
        No need to handle dependencies in this
        """
        raise RuntimeError("No licenses installed")

    def _install(self):
        """
        A function subclasses should override to install libaries
        No need to handle dependencies in this
        """
        pass

    def _clean(self, level):
        """
        A function subclasses should override to clean up
        No need to handle dependencies in this
        """
        pass


class GMP(Library):
    """
    A class to manage GMP
    """

    _url = "https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.xz"
    _root = os.path.join(native, "gmp")
    _source = os.path.join(_root, "src")
    _build_dir = os.path.join(_root, "build")
    include_dir = os.path.join(_root, "include")
    lib_dir = os.path.join(_build_dir, ".libs")
    # We are ok with either static or shared, but we prefer shared
    _lib_default = BuiltLib("libgmp", lib_dir, permit_static=True, permit_shared=True)
    _lic_d = os.path.join(BuiltLib.install_dir, "LICENSE.GMP")
    _lib = _lib_default

    def __init__(self):
        get_chk = {"GMP source": self._source}
        build_chk = {
            "GMP license": os.path.join(self._source, "COPYINGv3"),
            "GMP library": self._lib,
            "GMP include directory": self.include_dir,
        }
        install_chk = {"GMP lib": self._lib.find_installed}
        super().__init__(get_chk, build_chk, install_chk)

    def _get(self):
        os.makedirs(self._root, exist_ok=True)
        url = self._url
        sha = "fd4829912cddd12f84181c3451cc752be224643e87fac497b69edddadc49b4f2"
        d, gmp = download_checksum_extract(
            "GMP source", self._root, url, sha, ".tar.xz"
        )
        print("Moving GMP source to: " + self._source)
        assert len(gmp) == 1, "gmp's tarball is weird"
        os.rename(gmp[0], self._source)
        os.rmdir(d)

    def _set_lib_type(self, config_log):
        """
        Determine the built library type
        Run this during the build stage, after the build!
        """
        with open(config_log) as f:
            lines = f.readlines()
        sh_lib_str = "Shared libraries:"
        lines = [i for i in lines if sh_lib_str in i]
        assert len(lines) == 1, "./configure gave weird output"
        is_static = lines[0].replace(sh_lib_str, "").strip() == "no"
        print("GMP lib type: " + ("static" if is_static else "shared"))
        lib_type = StaticLib if is_static else SharedLib
        self._lib = lib_type(self._lib.name, self._lib.build_dir)

    def _run(self, name, *args, _count = 0):
        """
        A wrapper for run
        _count should only be used by this function
        """
        whitelist = string.ascii_lowercase + string.digits + "_-"
        log_f = "".join([i for i in name.lower().replace(" ", "_") if i in whitelist])
        log_f = os.path.join(self._build_dir, "setup-py-" + log_f)
        log_f += ('' if _count == 0 else "_" + str(_count)) + '.log'
        if os.path.exists(log_f):
            return self._run(name, *args, _count = _count + 1)
        with open(log_f, "w") as f:
            print(name + "...")
            print("  - Output file: " + log_f)
            sys.stdout.write("  - ")
            run_cmd_no_fail(*args, stdout=f, stderr=f)
        return log_f

    def _build(self):
        print("Copying source to build dir: " + self._build_dir)
        shutil.copytree(self._source, self._build_dir)  # Do not pollute source
        with chdir(self._build_dir):
            # GMP warnings:
            # 1. GMP's online docs are incomplete
            # 2. GMP's detection of ld's shared lib support is broken on at least macOS
            # TODO: host=none is slow
            # TODO: enable-shared=mpz ?
            # If GMP's build system refuses to use a shared library, fallback to static
            config_args = [
                "--with-pic",
                "--disable-static",
                "--enable-shared",
                "--host=none",
            ]
            self._set_lib_type(self._run("Configuring", "./configure", *config_args))
            # Building + Checking
            nproc = max(cpu_count() - 1, 1)
            makej = (find_exe("make"), "-j" + str(nproc)) # GMP requires make
            _ = self._run("Building GMP", *makej)
            _ = self._run("Checking GMP build", *makej, "check")
            # Include dir
            os.mkdir(self.include_dir)
            shutil.copy2(os.path.join(self._build_dir, "gmp.h"), self.include_dir)

    def _license(self):
        if not os.path.exists(self._lic_d):
            os.mkdir(self._lic_d)

        def cpy(src, dst):
            src = os.path.join(self._build_dir, src)
            dst = os.path.join(self._lic_d, dst)
            print("Copying " + src + " --> " + dst)
            shutil.copy2(src, dst)

        cpy("COPYINGv3", "GNU-GPLv3")
        cpy("AUTHORS", "AUTHORS")
        cpy("COPYING.LESSERv3", "GNU-LGPLv3")
        print("Generating README...")
        with open(os.path.join(self._lic_d, "README"), "w") as f:
            f.write(
                "The compiled GMP library is licensed under the GNU LGPLv3. The library was built from unmodified source code which can be found at: "
                + self._url
            )

    def _install(self):
        self._lib.install()

    def _clean(self, level):
        if level.implies(CleanLevel.INSTALL):
            self._lib.clean_install()
        if level.implies(CleanLevel.LICENSE):
            shutil.rmtree(self._lic_d, ignore_errors=True)
        if level.implies(CleanLevel.BUILD_DEPS):
            shutil.rmtree(self._build_dir, ignore_errors=True)
            shutil.rmtree(self.include_dir, ignore_errors=True)
            self._lib.clean_build()
            self._lib = self._lib_default  # Reset lib type
        if level.implies(CleanLevel.GET):
            shutil.rmtree(self._root, ignore_errors=True)


class Boost(Library):
    """
    A class used to manage Boost
    """

    root = os.path.join(native, "boost")
    _lic = os.path.join(root, "LICENSE")

    def __init__(self):
        chk = {"boost headers": self.root, "boost license": self._lic}
        # Boost depends on GMP
        super().__init__(chk, {}, {}, GMP())

    @staticmethod
    def url_data():
        return {
            # Get this info from: https://www.boost.org/users/download/
            "posix": (
                "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz",
                "94ced8b72956591c4775ae2207a9763d3600b30d9d7446562c552f0a14a63be7",
                ".tar.gz",
            ),
            "nt": (
                "https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.zip",
                "f22143b5528e081123c3c5ed437e92f648fe69748e95fa6e2bd41484e2986cc3",
                ".zip",
            ),
        }[os.name]

    def _get(self):
        d, fs = download_checksum_extract("boost headers", native, *self.url_data())
        print("Installing boost license...")
        if len(fs) != 1:
            raise RuntimeError("Boost should decompress into a single directory.")
        os.mkdir(self.root)
        shutil.copy2(os.path.join(fs[0], "LICENSE_1_0.txt"), self._lic)
        print("Installing boost headers...")
        os.rename(os.path.join(fs[0], "boost"), os.path.join(self.root, "boost"))
        print("Cleaning temporary files...")
        shutil.rmtree(d)

    def _license(self):
        pass

    def _clean(self, level):
        if level.implies(CleanLevel.GET):
            if os.path.exists(self.root):
                shutil.rmtree(self.root)


class Z3(Library):
    """
    A class used to manage the z3 dependency
    Z3 has no dependencies; it should be pre-installed
    """

    _root = os.path.dirname(z3.__file__)
    include_dir = os.path.join(_root, "include")
    lib = SharedLib("libz3", os.path.join(_root, "lib"))

    def __init__(self):
        super().__init__({}, {}, {"Z3 library": self.lib.find_installed})

    # _get is simply that _root has been resolved
    # Z3's pip has no license file so nothing for us to copy

    def _build(self):
        assert self.lib.find_built(), "Z3 is missing"

    def _license(self):
        pass


class Backward(Library):
    """
    A class used to manage the backward dependency
    """

    def __init__(self):
        # TODO: https://sourceware.org/elfutils/
        # TODO: https://sourceware.org/elfutils/ftp/0.186/
        # TODO: these depend on libdebuginfod (=dummy is an option?)
        super().__init__({}, {}, {})

    def _get(self):
        bk = os.path.join(native, "backward-cpp")
        b = os.path.exists(bk)
        assert b, "Backward is missing; run: git submodule init --recursive"
        lic = os.path.join(bk, "LICENSE.txt")
        assert os.path.exists(lic), "Backward missing license"

    def _license(self):
        pass


class Pybind11(Library):
    """
    A class used to manage the backward dependency
    """

    def __init__(self):
        super().__init__({}, {}, {})

    def _get(self):
        root = os.path.join(native, "pybind11")
        b = os.path.exists(root)
        assert b, "pybind11 is missing; run: git submodule init --recursive"
        lic = os.path.join(root, "LICENSE")
        assert os.path.exists(lic), "pybind11 missing license"

    def _license(self):
        pass


class Claricpp(Library):
    """
    A class to manage Claricpp
    Warning: if build_doc or enable_tests, .build() may be forced
    """
    # Config
    build_doc = False
    build_debug = False
    enable_tests = False
    build_claricpp = True
    # Constants
    build_dir = os.path.join(native, "build")
    _lib = SharedLib("libclaricpp", build_dir)
    _out_src = os.path.join(BuiltLib.install_dir, "src")

    def __init__(self):
        chk = {self._lib.name: self._lib, "Claricpp src": self._out_src}
        build_chk = {} if self.build_doc or self.enable_tests else chk
        super().__init__({}, build_chk, chk, Boost(), Z3(), Pybind11(), Backward())

    @classmethod
    def _cmake_config_args(cls, claricpp):
        """
        Create arguments to pass to cmake for configuring claricpp
        """
        z3_built = Z3.lib.find_built()
        assert z3_built is not None, "z3 was not built"
        config = {
            "VERSION": version,
            "CLARICPP": claricpp,
            # Build options
            "CONSTANT_LOG_LEVEL": cls.build_debug,
            "DEFAULT_RELEASE_LOG_LEVEL": "Critical",
            "CMAKE_BUILD_TYPE": "Debug" if cls.build_debug else "Release",
            # Backtrace options
            "WARN_BACKWARD_LIMITATIONS": True,
            "REQUIRE_BACKWARD_BACKEND": False,  # TODO:
            "SOURCE_ROOT_FOR_BACKTRACE": None,  # TODO: make a runtime thing config'd by python
            # Disable options
            "ENABLE_TESTING": cls.enable_tests,
            "CPP_CHECK": False,
            "CLANG_TIDY": False,
            "ENABLE_MEMCHECK": False,
            "BUILD_DOC": cls.build_doc,
            "LWYU": False,
            # Library config
            "GMPDIR": GMP.lib_dir,
            "GMP_INCLUDE_DIR": GMP.include_dir,
            "Boost_INCLUDE_DIRS": Boost.root,
            "Z3_ACQUISITION_MODE": "PATH",
            "Z3_INCLUDE_DIR": Z3.include_dir,
            "Z3_LIB": z3_built,
        }
        on_off = lambda x: ("ON" if x else "OFF") if type(x) is bool else x
        dd = lambda key, val: "-D" + key + "=" + ("" if val is None else on_off(val))
        return [dd(*i) for i in config.items()]

    @classmethod
    def _cmake(cls, native, build):
        print("Configuring...")
        cmake_args = cls._cmake_config_args(claricpp)
        with chdir(build):
            run_cmd_no_fail(find_exe("cmake"), *cmake_args, native)

    def _build(self):
        if not os.path.exists(self.build_dir):
            os.mkdir(self.build_dir)
        self._cmake(native, self.build_dir)
        with chdir(self.build_dir):
            if self.build_claricpp:
                print("Building " + claricpp + "...")
                build_cmake_target(claricpp)
            if self.enable_tests:
                print("Building tests...")
                build_cmake_target("all")
                print("Tests built in build dir: " + self.build_dir)
            if self.build_doc:
                print("Building docs...")
                build_cmake_target("docs")
                print("Docs built in: " + os.path.join(self.build_dir, 'docs'))

    def _license(self):
        pass  # Same as main project

    @classmethod
    def _install_ignore(cls, d, fs):
        d = os.path.abspath(d)
        skip = os.path.realpath(os.path.join(cls.build_dir, 'docs')) # Don't install docs
        paths = { os.path.realpath(os.path.join(d, i)):i for i in fs }
        return [ k for i,k in paths.items() if i == skip ]

    def _install(self):
        self._lib.install()
        if not os.path.exists(self._out_src):
            shutil.copytree(os.path.join(native, "src"), self._out_src, ignore=self._install_ignore)

    def _clean(self, level):
        if level.implies(CleanLevel.INSTALL):
            self._lib.clean_install()
            shutil.rmtree(self._out_src, ignore_errors=True)
        if level.implies(CleanLevel.BUILT_LIBS):
            self._lib.clean_build()
        if level.implies(CleanLevel.BUILD):
            try:  # No clue if this stuff even exists
                with chdir(self.build_dir):
                    build_cmake_target("clean")
            except:  # Ignore errors during the above
                pass
            shutil.rmtree(self.build_dir, ignore_errors=True)


class ClaricppAPI(Library):
    """
    A class to manage ClaricppAPI
    """

    _api_target = "clari"
    _build_dir = os.path.join(Claricpp.build_dir, "src/api")
    _lib = SharedLib(_api_target, _build_dir)

    def __init__(self):
        chk = {self._lib.name: self._lib}
        super().__init__({}, chk, chk, Claricpp())

    def _build(self):
        print("Building " + self._api_target + "...")
        with chdir(self._build_dir):
            build_cmake_target(self._api_target)

    def _license(self):
        pass  # Same as main project

    def _install(self):
        self._lib.install()

    def _clean(self, level):
        if level.implies(CleanLevel.INSTALL):
            self._lib.clean_install()
        if level.implies(CleanLevel.BUILT_LIBS):
            self._lib.clean_build()
        if level.implies(CleanLevel.BUILD):
            shutil.rmtree(self._build_dir, ignore_errors=True)


######################################################################
#                             setuptools                             #
######################################################################


class SDist(SDistOriginal):
    def run(self):
        f = lambda: ClaricppAPI().get(False)
        self.execute(f, (), msg="Getting build source dependencies")
        super().run()


class Build(BuildOriginal):
    def run(self):
        # Build native components and install to the python src location
        Claricpp.build_debug = ("SETUP_PY_BUILD_DEBUG" in os.environ)
        f = lambda: ClaricppAPI().install(False)
        self.execute(f, (), msg="Building native components")
        print("Done building native components")
        super().run()


class SimpleCommand(Command):

    user_options = []

    def initialize_options(self):
        pass

    def finalize_options(self):
        pass

class BuildTests(SimpleCommand):
    def run(self):
        Claricpp.enable_tests = True
        self.run_command("build")
        print("To test: cd " + Claricpp.build_dir + " && ctest .")

class BuildDocs(SimpleCommand):
    def run(self):
        Claricpp.build_doc = True
        Claricpp.build_claricpp = False
        f = lambda: Claricpp().build(False)
        self.execute(f, (), msg="Building native docs")

class Clean(CleanOriginal):
    def run(self):
        lvl = os.getenv("SETUP_PY_CLEAN_LEVEL", "get").upper()
        print("Clean level set to: " + lvl)
        f = lambda: ClaricppAPI().clean(getattr(CleanLevel, lvl))
        self.execute(f, (), msg="Cleaning claripy/native")


if __name__ == "__main__":
    setup(
        cmdclass={
            "sdist": SDist,
            "build": Build,
            "docs": BuildDocs,
            "build_tests": BuildTests,  # A custom command to build native tests
            "clean": Clean,  # A custom command, makes dev easier
        },
    )

/** @file */
#include "simplify.hpp"

#include "../simplify.hpp"

#include <pybind11/functional.h>


/** Clear the stored python simplifier */
static void clear_py_simp() noexcept {
    Simplify::manager.set_python_simplifier(nullptr); // nullptr_t override is noexcept
}

void API::bind_simplify_init(API::Binder::ModuleGetter &m) {
    register_at_exit(clear_py_simp);
    m("API").def(
        "set_python_simplifier",
        [](const std::function<Simplify::Func> &s) { Simplify::manager.set_python_simplifier(s); },
        "Set a function to be called on every invocation of the builtin simplify()."
        " Will be called as simplifier(op)",
        pybind11::arg("simplifier"));
}
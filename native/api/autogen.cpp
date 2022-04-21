// Claricpp API

#include "headers.hpp"
#include "manual.hpp"
#include <algorithm>
#include <functional>
#include <ios>
#include <iterator>
#include <locale>
#include <map>
#include <memory>
#include <ostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <variant>
#include <vector>
#include <z3++.h>


//
// Derived from file: binder/raw_output/clari.cpp
//


/** The name of the root module */
CCSC API::root_mod_name {"clari"};

namespace API::Binder {

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_6(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_7(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_8(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_9(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_10(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_11(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_12(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_13(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_14(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_15(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_16(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_17(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_18(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_19(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_20(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_21(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_22(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_23(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_24(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_25(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_26(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_27(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_28(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_29(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_30(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_31(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_32(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_33(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_34(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_35(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_36(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_37(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_38(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_39(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown_40(std::function< pybind11::module &(std::string const &namespace_) > &M);

} // namespace API::Binder


PYBIND11_MODULE(clari, root_module) {
	root_module.doc() = "clari module";

	std::map <std::string, pybind11::module> modules;
	API::Binder::ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	static std::vector<std::string> const reserved_python_words {"nonlocal", "global", };

	auto mangle_namespace_name(
		[](std::string const &ns) -> std::string {
			if ( std::find(reserved_python_words.begin(), reserved_python_words.end(), ns) == reserved_python_words.end() ) return ns;
			else return ns+'_';
		}
	);

	std::vector< std::pair<std::string, std::string> > sub_modules {
		{"", "Annotation"},
		{"", "Backend"},
		{"Backend", "Z3"},
		{"", "CUID"},
		{"", "Create"},
		{"Create", "FP"},
		{"Create", "String"},
		{"", "Expr"},
		{"", "Factory"},
		{"", "Hash"},
		{"", "Mode"},
		{"Mode", "FP"},
		{"Mode", "Sign"},
		{"", "Op"},
		{"Op", "FP"},
		{"Op", "String"},
		{"", "PyObj"},
		{"", "Util"},
		{"Util", "Backtrace"},
		{"Util", "Err"},
		{"", "API"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule( mangle_namespace_name(p.second).c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	API::Binder::bind_unknown_unknown(M);
	API::Binder::bind_unknown_unknown_1(M);
	API::Binder::bind_unknown_unknown_2(M);
	API::Binder::bind_unknown_unknown_3(M);
	API::Binder::bind_unknown_unknown_4(M);
	API::Binder::bind_unknown_unknown_5(M);
	API::Binder::bind_unknown_unknown_6(M);
	API::Binder::bind_unknown_unknown_7(M);
	API::Binder::bind_unknown_unknown_8(M);
	API::Binder::bind_unknown_unknown_9(M);
	API::Binder::bind_unknown_unknown_10(M);
	API::Binder::bind_unknown_unknown_11(M);
	API::Binder::bind_unknown_unknown_12(M);
	API::Binder::bind_unknown_unknown_13(M);
	API::Binder::bind_unknown_unknown_14(M);
	API::Binder::bind_unknown_unknown_15(M);
	API::Binder::bind_unknown_unknown_16(M);
	API::Binder::bind_unknown_unknown_17(M);
	API::Binder::bind_unknown_unknown_18(M);
	API::Binder::bind_unknown_unknown_19(M);
	API::Binder::bind_unknown_unknown_20(M);
	API::Binder::bind_unknown_unknown_21(M);
	API::Binder::bind_unknown_unknown_22(M);
	API::Binder::bind_unknown_unknown_23(M);
	API::Binder::bind_unknown_unknown_24(M);
	API::Binder::bind_unknown_unknown_25(M);
	API::Binder::bind_unknown_unknown_26(M);
	API::Binder::bind_unknown_unknown_27(M);
	API::Binder::bind_unknown_unknown_28(M);
	API::Binder::bind_unknown_unknown_29(M);
	API::Binder::bind_unknown_unknown_30(M);
	API::Binder::bind_unknown_unknown_31(M);
	API::Binder::bind_unknown_unknown_32(M);
	API::Binder::bind_unknown_unknown_33(M);
	API::Binder::bind_unknown_unknown_34(M);
	API::Binder::bind_unknown_unknown_35(M);
	API::Binder::bind_unknown_unknown_36(M);
	API::Binder::bind_unknown_unknown_37(M);
	API::Binder::bind_unknown_unknown_38(M);
	API::Binder::bind_unknown_unknown_39(M);
	API::Binder::bind_unknown_unknown_40(M);

	// Manual API call
	API::bind_manual(root_module, M);
}


//
// File: binder/raw_output/unknown/unknown.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Util::Backtrace::Lazy file: line:21
		pybind11::class_<Util::Backtrace::Lazy, std::shared_ptr<Util::Backtrace::Lazy>> cl(M("Util::Backtrace"), "Lazy", "The lazy backtrace holder type ");
		cl.def("str", (std::string (Util::Backtrace::Lazy::*)() const) &Util::Backtrace::Lazy::str, "As string \n\nC++: Util::Backtrace::Lazy::str() const --> std::string");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_1.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Util::Err::Claricpp file: line:35
struct PyCallBack_Util_Err_Claricpp : public Util::Err::Claricpp {
	using Util::Err::Claricpp::Claricpp;

};

namespace API::Binder {
void bind_unknown_unknown_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Util::Err::Claricpp file: line:35
		pybind11::class_<Util::Err::Claricpp, std::shared_ptr<Util::Err::Claricpp>, PyCallBack_Util_Err_Claricpp> cl(M("Util::Err"), "Claricpp", "The base claricpp exception class\n  Any exception thrown intentionally must subclass this\n  Note: Since exceptions do not need to be super fast and since we have const date members:\n  for clarity we ignore the rule of 5 in favor of what the compiler defaults. Subclasses\n  of Claricpp should feel free to do the same unless they have non-const data members\n  This class saves the last n_backtraces backtraces");
		cl.def_static("log_atomic_change", (void (*)(const char *const, const bool, const bool)) &Util::Err::Claricpp::log_atomic_change, "Logs that an atomic was toggled \n\nC++: Util::Err::Claricpp::log_atomic_change(const char *const, const bool, const bool) --> void", pybind11::arg("what"), pybind11::arg("old"), pybind11::arg("new_"));
		cl.def_static("warn_backtrace_slow", (void (*)()) &Util::Err::Claricpp::warn_backtrace_slow, "Warns that enabling backtraces causes a performance hit \n\nC++: Util::Err::Claricpp::warn_backtrace_slow() --> void");
		cl.def_static("toggle_backtrace", [](const bool & a0) -> bool { return Util::Err::Claricpp::toggle_backtrace(a0); }, "", pybind11::arg("set"));
		cl.def_static("toggle_backtrace", (bool (*)(const bool, const bool)) &Util::Err::Claricpp::toggle_backtrace, "Enable / disable backtraces\n  Returns the old state\n\nC++: Util::Err::Claricpp::toggle_backtrace(const bool, const bool) --> bool", pybind11::arg("set"), pybind11::arg("log_me"));
		cl.def_static("backtraces_enabled", (bool (*)()) &Util::Err::Claricpp::backtraces_enabled, "Return true if and only if backtraces are enabled \n\nC++: Util::Err::Claricpp::backtraces_enabled() --> bool");
		cl.def("what", (const char * (Util::Err::Claricpp::*)() const) &Util::Err::Claricpp::what, "Message getter \n\nC++: Util::Err::Claricpp::what() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def_static("lazy_backtrace", []() -> std::shared_ptr<const class Util::Backtrace::Lazy> { return Util::Err::Claricpp::lazy_backtrace(); }, "");
		cl.def_static("lazy_backtrace", (class std::shared_ptr<const class Util::Backtrace::Lazy> (*)(const unsigned long)) &Util::Err::Claricpp::lazy_backtrace, "Get a previous backtrace in an unevaluated form; returns {} on error\n  Get the a previous backtrace\n  Ignores the last index'th backtraces\n  Ex. index = 0 gets the last backtrace, index = 1 gets the second to last\n  Call ->str() on the result to get the backtrace as a string\n\nC++: Util::Err::Claricpp::lazy_backtrace(const unsigned long) --> class std::shared_ptr<const class Util::Backtrace::Lazy>", pybind11::arg("index"));
		cl.def_static("backtrace", []() -> std::string { return Util::Err::Claricpp::backtrace(); }, "");
		cl.def_static("backtrace", (std::string (*)(const unsigned long)) &Util::Err::Claricpp::backtrace, "Eagerly evaluated lazy_backtrace(index)\n  If lazy_backtrace(index) returns nullptr; will return {}\n  Unlike lazy_backtrace, this may throw if evaluation fails\n\nC++: Util::Err::Claricpp::backtrace(const unsigned long) --> std::string", pybind11::arg("index"));
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_10.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_10(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Factory::FactoryMade file: line:43
		pybind11::class_<Factory::FactoryMade, Factory::FactoryMade*, Hash::Hashed, CUID::HasCUID> cl(M("Factory"), "FactoryMade", "A type that can be constructed by the factory\n  All factory constructable types must subclass this\n  All subclasses that are or have an instantiable subclass constructed via factory\n	  1. Must include the FACTORY_ENABLE_CONSTRUCTION_FROM_BASE method. Note that\n		 this also defines a static_cuid\n  Warning: No virtual destructor; do *not* delete by base class pointer; avoid slicing!");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_11.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // HasRepr file: line:16
		pybind11::class_<HasRepr<Annotation::Base>, HasRepr<Annotation::Base>*> cl(M(""), "HasRepr_Annotation_Base_t", "");
		cl.def("repr", (std::string (HasRepr<Annotation::Base>::*)() const) &HasRepr<Annotation::Base>::repr, "C++: HasRepr<Annotation::Base>::repr() const --> std::string");
		cl.def("assign", (struct HasRepr<struct Annotation::Base> & (HasRepr<Annotation::Base>::*)(const struct HasRepr<struct Annotation::Base> &)) &HasRepr<Annotation::Base>::operator=, "C++: HasRepr<Annotation::Base>::operator=(const struct HasRepr<struct Annotation::Base> &) --> struct HasRepr<struct Annotation::Base> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HasRepr file: line:16
		pybind11::class_<HasRepr<Annotation::Vec>, HasRepr<Annotation::Vec>*> cl(M(""), "HasRepr_Annotation_Vec_t", "");
		cl.def("repr", (std::string (HasRepr<Annotation::Vec>::*)() const) &HasRepr<Annotation::Vec>::repr, "C++: HasRepr<Annotation::Vec>::repr() const --> std::string");
		cl.def("assign", (struct HasRepr<struct Annotation::Vec> & (HasRepr<Annotation::Vec>::*)(const struct HasRepr<struct Annotation::Vec> &)) &HasRepr<Annotation::Vec>::operator=, "C++: HasRepr<Annotation::Vec>::operator=(const struct HasRepr<struct Annotation::Vec> &) --> struct HasRepr<struct Annotation::Vec> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HasRepr file: line:16
		pybind11::class_<HasRepr<Expr::Base>, HasRepr<Expr::Base>*> cl(M(""), "HasRepr_Expr_Base_t", "");
		cl.def("repr", (std::string (HasRepr<Expr::Base>::*)() const) &HasRepr<Expr::Base>::repr, "C++: HasRepr<Expr::Base>::repr() const --> std::string");
		cl.def("assign", (struct HasRepr<class Expr::Base> & (HasRepr<Expr::Base>::*)(const struct HasRepr<class Expr::Base> &)) &HasRepr<Expr::Base>::operator=, "C++: HasRepr<Expr::Base>::operator=(const struct HasRepr<class Expr::Base> &) --> struct HasRepr<class Expr::Base> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // HasRepr file: line:16
		pybind11::class_<HasRepr<Op::Base>, HasRepr<Op::Base>*> cl(M(""), "HasRepr_Op_Base_t", "");
		cl.def("repr", (std::string (HasRepr<Op::Base>::*)() const) &HasRepr<Op::Base>::repr, "C++: HasRepr<Op::Base>::repr() const --> std::string");
		cl.def("assign", (struct HasRepr<class Op::Base> & (HasRepr<Op::Base>::*)(const struct HasRepr<class Op::Base> &)) &HasRepr<Op::Base>::operator=, "C++: HasRepr<Op::Base>::operator=(const struct HasRepr<class Op::Base> &) --> struct HasRepr<class Op::Base> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_12.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Annotation::Base file: line:21
struct PyCallBack_Annotation_Base : public Annotation::Base {
	using Annotation::Base::Base;

	bool eliminatable() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Annotation::Base *>(this), "eliminatable");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Base::eliminatable();
	}
	bool relocatable() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Annotation::Base *>(this), "relocatable");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return Base::relocatable();
	}
	const char * name() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Annotation::Base *>(this), "name");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return Base::name();
	}
};

namespace API::Binder {
void bind_unknown_unknown_12(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Annotation::Base file: line:21
		pybind11::class_<Annotation::Base, std::shared_ptr<Annotation::Base>, PyCallBack_Annotation_Base, HasRepr<Annotation::Base>, Factory::FactoryMade> cl(M("Annotation"), "Base", "Annotations are used to achieve claripy's goal of being an arithmetic instrumentation\n engine. They provide a means to pass extra information to the claripy backends.");
		cl.def( pybind11::init( [](const unsigned long long & a0){ return new Annotation::Base(a0); }, [](const unsigned long long & a0){ return new PyCallBack_Annotation_Base(a0); } ), "doc");
		cl.def( pybind11::init<const unsigned long long &, const unsigned long long>(), pybind11::arg("h"), pybind11::arg("c") );

		cl.def( pybind11::init( [](PyCallBack_Annotation_Base const &o){ return new PyCallBack_Annotation_Base(o); } ) );
		cl.def( pybind11::init( [](Annotation::Base const &o){ return new Annotation::Base(o); } ) );
		cl.def("eliminatable", (bool (Annotation::Base::*)() const) &Annotation::Base::eliminatable, "Returns whether this annotation can be eliminated in a simplification.\n True if eliminatable, False otherwise\n\nC++: Annotation::Base::eliminatable() const --> bool");
		cl.def("relocatable", (bool (Annotation::Base::*)() const) &Annotation::Base::relocatable, "Returns whether this annotation can be relocated in a simplification.\n  True if it can be relocated, false otherwise.\n\nC++: Annotation::Base::relocatable() const --> bool");
		cl.def("name", (const char * (Annotation::Base::*)() const) &Annotation::Base::name, "Name \n\nC++: Annotation::Base::name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Annotation::SimplificationAvoidance file: line:14
		pybind11::class_<Annotation::SimplificationAvoidance, std::shared_ptr<Annotation::SimplificationAvoidance>, Annotation::Base> cl(M("Annotation"), "SimplificationAvoidance", "A built-in annotation ");
		cl.def( pybind11::init<const unsigned long long &>(), pybind11::arg("h") );

		cl.def( pybind11::init( [](Annotation::SimplificationAvoidance const &o){ return new Annotation::SimplificationAvoidance(o); } ) );
		cl.def("eliminatable", (bool (Annotation::SimplificationAvoidance::*)() const) &Annotation::SimplificationAvoidance::eliminatable, "Returns whether this annotation can be eliminated in a simplification. \n\nC++: Annotation::SimplificationAvoidance::eliminatable() const --> bool");
		cl.def("relocatable", (bool (Annotation::SimplificationAvoidance::*)() const) &Annotation::SimplificationAvoidance::relocatable, "Returns whether this annotation can be relocated in a simplification. \n\nC++: Annotation::SimplificationAvoidance::relocatable() const --> bool");
		cl.def("name", (const char * (Annotation::SimplificationAvoidance::*)() const) &Annotation::SimplificationAvoidance::name, "name \n\nC++: Annotation::SimplificationAvoidance::name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Annotation::Vec file: line:16
		pybind11::class_<Annotation::Vec, std::shared_ptr<Annotation::Vec>, HasRepr<Annotation::Vec>, Hash::Hashed> cl(M("Annotation"), "Vec", "");
		cl.def( pybind11::init( [](Annotation::Vec const &o){ return new Annotation::Vec(o); } ) );
		cl.def_readonly("vec", &Annotation::Vec::vec);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_13.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Expr::Base file: line:28
struct PyCallBack_Expr_Base : public Expr::Base {
	using Expr::Base::Base;

	const char * type_name() const throw() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Expr::Base *>(this), "type_name");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Base::type_name\"");
	}
};

namespace API::Binder {
void bind_unknown_unknown_13(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Expr::Base file: line:28
		pybind11::class_<Expr::Base, Expr::Base*, PyCallBack_Expr_Base, HasRepr<Expr::Base>, Factory::FactoryMade> cl(M("Expr"), "Base", "The base Expr type\n  All exprs must subclass this\n  TODO: make quite a bit smaller by killing vtables; Hashed, HasCUID, and HasRepr all have one");
		cl.def_readonly("symbolic", &Expr::Base::symbolic);
		cl.def_readonly("op", &Expr::Base::op);
		cl.def_readonly("annotations", &Expr::Base::annotations);
		cl.def("type_name", (const char * (Expr::Base::*)() const) &Expr::Base::type_name, "Get the type name \n\nC++: Expr::Base::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_14.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_14(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // BitLength file: line:13
		pybind11::class_<BitLength, BitLength*> cl(M(""), "BitLength", "A class with a const bit length ");
		cl.def_readonly("bit_length", &BitLength::bit_length);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_15.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Expr::Bits file: line:16
struct PyCallBack_Expr_Bits : public Expr::Bits {
	using Expr::Bits::Bits;

	const char * type_name() const throw() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Expr::Bits *>(this), "type_name");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"Base::type_name\"");
	}
};

namespace API::Binder {
void bind_unknown_unknown_15(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Expr::Bits file: line:16
		pybind11::class_<Expr::Bits, Expr::Bits*, PyCallBack_Expr_Bits, Expr::Base, BitLength> cl(M("Expr"), "Bits", "This class represents an Expr of Bits ");
	}
	// Expr::get_bit_length(const class Expr::Base *const) file: line:40
	M("Expr").def("get_bit_length", (unsigned long long (*)(const class Expr::Base *const)) &Expr::get_bit_length, "Static casts T to Expr::Bits' raw pointer, then returns the bit_length\n  p may not be nullptr\n  Warning: This static casts, the user must ensure that p is a Bits\n\nC++: Expr::get_bit_length(const class Expr::Base *const) --> unsigned long long", pybind11::arg("p"));

	// Expr::get_bit_length(const class std::shared_ptr<const class Expr::Base> &) file: line:50
	M("Expr").def("get_bit_length", (unsigned long long (*)(const class std::shared_ptr<const class Expr::Base> &)) &Expr::get_bit_length, "Static casts T to Expr::Bits, then returns the bit_length\n  p may not be nullptr\n  Warning: This static casts, the user must ensure that p.get() is a Bits\n\nC++: Expr::get_bit_length(const class std::shared_ptr<const class Expr::Base> &) --> unsigned long long", pybind11::arg("p"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_16.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_16(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Expr::are_same_type(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &) file: line:19
	M("Expr").def("are_same_type", (bool (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &)) &Expr::are_same_type<true>, "C++: Expr::are_same_type(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &) --> bool", pybind11::arg("x"), pybind11::arg("y"));

	// Expr::are_same_type(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &) file: line:19
	M("Expr").def("are_same_type", (bool (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &)) &Expr::are_same_type<false>, "C++: Expr::are_same_type(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &) --> bool", pybind11::arg("x"), pybind11::arg("y"));

	{ // Expr::Bool file: line:37
		pybind11::class_<Expr::Bool, std::shared_ptr<Expr::Bool>, Expr::Base> cl(M("Expr"), "Bool", "An Expr::Base subclass representing a bool ");
		cl.def("type_name", (const char * (Expr::Bool::*)() const) &Expr::Bool::type_name, "Get the type name \n\nC++: Expr::Bool::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Expr::String file: line:57
		pybind11::class_<Expr::String, std::shared_ptr<Expr::String>, Expr::Bits> cl(M("Expr"), "String", "");
		cl.def("type_name", (const char * (Expr::String::*)() const) &Expr::String::type_name, "C++: Expr::String::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Expr::VS file: line:58
		pybind11::class_<Expr::VS, std::shared_ptr<Expr::VS>, Expr::Bits> cl(M("Expr"), "VS", "");
		cl.def("type_name", (const char * (Expr::VS::*)() const) &Expr::VS::type_name, "C++: Expr::VS::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Expr::BV file: line:59
		pybind11::class_<Expr::BV, std::shared_ptr<Expr::BV>, Expr::Bits> cl(M("Expr"), "BV", "");
		cl.def("type_name", (const char * (Expr::BV::*)() const) &Expr::BV::type_name, "C++: Expr::BV::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	{ // Expr::FP file: line:60
		pybind11::class_<Expr::FP, std::shared_ptr<Expr::FP>, Expr::Bits> cl(M("Expr"), "FP", "");
		cl.def("type_name", (const char * (Expr::FP::*)() const) &Expr::FP::type_name, "C++: Expr::FP::type_name() const --> const char *", pybind11::return_value_policy::automatic);
	}
	// Expr::find(const unsigned long long) file: line:61
	M("Expr").def("find", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned long long)) &Expr::find, "Get a shared pointer from a hash\n  If the object does not exist it returns a shared pointer to nullptr\n\nC++: Expr::find(const unsigned long long) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("h"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_17.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_17(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // PyObj::Base file: line:17
		pybind11::class_<PyObj::Base, std::shared_ptr<PyObj::Base>, Hash::Hashed> cl(M("PyObj"), "Base", "A class containing a ref to some python object and a hash ");
		cl.def( pybind11::init<const unsigned long long &, const unsigned long long>(), pybind11::arg("h"), pybind11::arg("r") );

		cl.def( pybind11::init( [](PyObj::Base const &o){ return new PyObj::Base(o); } ) );
		cl.def_readonly("ref", &PyObj::Base::ref);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_18.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_18(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // PyObj::VS file: line:16
		pybind11::class_<PyObj::VS, std::shared_ptr<PyObj::VS>, PyObj::Base, BitLength> cl(M("PyObj"), "VS", "A Value Set PyObj ");
		cl.def( pybind11::init<const unsigned long long &, const unsigned long long, const unsigned long long>(), pybind11::arg("h"), pybind11::arg("r"), pybind11::arg("bl") );

		cl.def( pybind11::init( [](PyObj::VS const &o){ return new PyObj::VS(o); } ) );

		cl.def("__str__", [](PyObj::VS const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_19.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_19(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::Base file: line:20
		pybind11::class_<Op::Base, std::shared_ptr<Op::Base>, HasRepr<Op::Base>, Factory::FactoryMade> cl(M("Op"), "Base", "Base operation expr\n  All op exprs must subclass this");
		cl.def("op_name", (const char * (Op::Base::*)() const) &Op::Base::op_name, "The name of the op \n\nC++: Op::Base::op_name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("unsafe_add_reversed_children", (void (Op::Base::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Base::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n  Be careful to ensure 'this' does not destruct while using said pointers\n\nC++: Op::Base::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Base::*)() const) &Op::Base::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Base::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Binary file: line:36
		pybind11::class_<Op::Binary<true>, std::shared_ptr<Op::Binary<true>>, Op::Base> cl(M("Op"), "Binary_true_t", "");
		cl.def_readonly("left", &Op::Binary<true>::left);
		cl.def_readonly("right", &Op::Binary<true>::right);
		cl.def("unsafe_add_reversed_children", (void (Op::Binary<true>::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Binary<true>::unsafe_add_reversed_children, "C++: Op::Binary<true>::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Binary<true>::*)() const) &Op::Binary<true>::python_children, "C++: Op::Binary<true>::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
		cl.def("op_name", (const char * (Op::Base::*)() const) &Op::Base::op_name, "The name of the op \n\nC++: Op::Base::op_name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("unsafe_add_reversed_children", (void (Op::Base::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Base::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n  Be careful to ensure 'this' does not destruct while using said pointers\n\nC++: Op::Base::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Base::*)() const) &Op::Base::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Base::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Binary file: line:36
		pybind11::class_<Op::Binary<false>, std::shared_ptr<Op::Binary<false>>, Op::Base> cl(M("Op"), "Binary_false_t", "");
		cl.def_readonly("left", &Op::Binary<false>::left);
		cl.def_readonly("right", &Op::Binary<false>::right);
		cl.def("unsafe_add_reversed_children", (void (Op::Binary<false>::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Binary<false>::unsafe_add_reversed_children, "C++: Op::Binary<false>::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Binary<false>::*)() const) &Op::Binary<false>::python_children, "C++: Op::Binary<false>::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
		cl.def("op_name", (const char * (Op::Base::*)() const) &Op::Base::op_name, "The name of the op \n\nC++: Op::Base::op_name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("unsafe_add_reversed_children", (void (Op::Base::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Base::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n  Be careful to ensure 'this' does not destruct while using said pointers\n\nC++: Op::Base::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Base::*)() const) &Op::Base::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Base::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Extract file: line:14
		pybind11::class_<Op::Extract, std::shared_ptr<Op::Extract>, Op::Base> cl(M("Op"), "Extract", "The op class: Extract ");
		cl.def_readonly("high", &Op::Extract::high);
		cl.def_readonly("low", &Op::Extract::low);
		cl.def_readonly("from", &Op::Extract::from);
		cl.def("unsafe_add_reversed_children", (void (Op::Extract::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Extract::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::Extract::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Extract::*)() const) &Op::Extract::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Extract::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::AbstractFlat file: line:36
		pybind11::class_<Op::AbstractFlat, std::shared_ptr<Op::AbstractFlat>, Op::Base> cl(M("Op"), "AbstractFlat", "An abstract flattened Op class\n  Operands must all be of the same type and there must be at least 2\n  These conditions are *not* validated");
		cl.def_readonly("operands", &Op::AbstractFlat::operands);
		cl.def("consider_size", (bool (Op::AbstractFlat::*)() const) &Op::AbstractFlat::consider_size, "Return true if this class requires each operand be of the same size \n\nC++: Op::AbstractFlat::consider_size() const --> bool");
		cl.def("unsafe_add_reversed_children", (void (Op::AbstractFlat::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::AbstractFlat::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::AbstractFlat::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::AbstractFlat::*)() const) &Op::AbstractFlat::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::AbstractFlat::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Flat file: line:86
		pybind11::class_<Op::Flat<true>, std::shared_ptr<Op::Flat<true>>, Op::AbstractFlat> cl(M("Op"), "Flat_true_t", "");
		cl.def("consider_size", (bool (Op::Flat<true>::*)() const) &Op::Flat<true>::consider_size, "C++: Op::Flat<true>::consider_size() const --> bool");
		cl.def_readonly("operands", &Op::AbstractFlat::operands);
		cl.def("consider_size", (bool (Op::AbstractFlat::*)() const) &Op::AbstractFlat::consider_size, "Return true if this class requires each operand be of the same size \n\nC++: Op::AbstractFlat::consider_size() const --> bool");
		cl.def("unsafe_add_reversed_children", (void (Op::AbstractFlat::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::AbstractFlat::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::AbstractFlat::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::AbstractFlat::*)() const) &Op::AbstractFlat::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::AbstractFlat::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_2.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // CUID::HasCUID file: line:38
		pybind11::class_<CUID::HasCUID, std::shared_ptr<CUID::HasCUID>> cl(M("CUID"), "HasCUID", "A type that has a class unique id\n  This has the benefits of a virtual function as inherited classes\n  can have different CUIDs than their ancestors, while also avoiding\n  the overhead of a vtabel call to invoke virtual cuid() const;\n  Warning: No virtual destructor; do *not* delete by base class pointer; avoid slicing!");
		cl.def( pybind11::init<const unsigned long long &>(), pybind11::arg("c") );

		cl.def( pybind11::init( [](CUID::HasCUID const &o){ return new CUID::HasCUID(o); } ) );
		cl.def_readonly("cuid", &CUID::HasCUID::cuid);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_20.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_20(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::FP::FromFP file: line:15
		pybind11::class_<Op::FP::FromFP, std::shared_ptr<Op::FP::FromFP>, Op::Base> cl(M("Op::FP"), "FromFP", "The op class which converts an FP into another FP (for example, a float into a double) ");
		cl.def_readonly("mode", &Op::FP::FromFP::mode);
		cl.def_readonly("fp", &Op::FP::FromFP::fp);
		cl.def_readonly("width", &Op::FP::FromFP::width);
		cl.def("unsafe_add_reversed_children", (void (Op::FP::FromFP::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::FP::FromFP::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::FP::FromFP::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::FP::FromFP::*)() const) &Op::FP::FromFP::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::FP::FromFP::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::FP::FromNot2sComplementBV file: line:15
		pybind11::class_<Op::FP::FromNot2sComplementBV, std::shared_ptr<Op::FP::FromNot2sComplementBV>, Op::Base> cl(M("Op::FP"), "FromNot2sComplementBV", "The op class which converts a non-2s-complement BV into an FP ");
		cl.def_readonly("bv", &Op::FP::FromNot2sComplementBV::bv);
		cl.def_readonly("width", &Op::FP::FromNot2sComplementBV::width);
		cl.def("unsafe_add_reversed_children", (void (Op::FP::FromNot2sComplementBV::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::FP::FromNot2sComplementBV::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::FP::FromNot2sComplementBV::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::FP::FromNot2sComplementBV::*)() const) &Op::FP::FromNot2sComplementBV::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::FP::FromNot2sComplementBV::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::FP::ModeBinary file: line:32
		pybind11::class_<Op::FP::ModeBinary, std::shared_ptr<Op::FP::ModeBinary>, Op::Base> cl(M("Op::FP"), "ModeBinary", "An FP Binary Op class\n  Operands must all be of the same type and size");
		cl.def_readonly("mode", &Op::FP::ModeBinary::mode);
		cl.def_readonly("left", &Op::FP::ModeBinary::left);
		cl.def_readonly("right", &Op::FP::ModeBinary::right);
		cl.def("unsafe_add_reversed_children", (void (Op::FP::ModeBinary::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::FP::ModeBinary::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::FP::ModeBinary::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::FP::ModeBinary::*)() const) &Op::FP::ModeBinary::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::FP::ModeBinary::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_21.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_21(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::Ternary file: line:33
		pybind11::class_<Op::Ternary<false>, std::shared_ptr<Op::Ternary<false>>, Op::Base> cl(M("Op"), "Ternary_false_t", "");
		cl.def_readonly("first", &Op::Ternary<false>::first);
		cl.def_readonly("second", &Op::Ternary<false>::second);
		cl.def_readonly("third", &Op::Ternary<false>::third);
		cl.def("unsafe_add_reversed_children", (void (Op::Ternary<false>::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Ternary<false>::unsafe_add_reversed_children, "C++: Op::Ternary<false>::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Ternary<false>::*)() const) &Op::Ternary<false>::python_children, "C++: Op::Ternary<false>::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
		cl.def("op_name", (const char * (Op::Base::*)() const) &Op::Base::op_name, "The name of the op \n\nC++: Op::Base::op_name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("unsafe_add_reversed_children", (void (Op::Base::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Base::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n  Be careful to ensure 'this' does not destruct while using said pointers\n\nC++: Op::Base::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Base::*)() const) &Op::Base::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Base::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Unary file: line:30
		pybind11::class_<Op::Unary, std::shared_ptr<Op::Unary>, Op::Base> cl(M("Op"), "Unary", "A Unary Op class ");
		cl.def_readonly("child", &Op::Unary::child);
		cl.def("unsafe_add_reversed_children", (void (Op::Unary::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Unary::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::Unary::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Unary::*)() const) &Op::Unary::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Unary::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_22.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_22(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::FP::ToIEEEBV file: line:22
		pybind11::class_<Op::FP::ToIEEEBV, std::shared_ptr<Op::FP::ToIEEEBV>, Op::Unary> cl(M("Op::FP"), "ToIEEEBV", "The unary fp op class: FP::ToIEEEBV ");
	}
	{ // Op::FP::Add file: line:31
		pybind11::class_<Op::FP::Add, std::shared_ptr<Op::FP::Add>, Op::FP::ModeBinary> cl(M("Op::FP"), "Add", "The op class: FP::Add\n  Input sizes may not differ");
	}
	{ // Op::FP::Sub file: line:36
		pybind11::class_<Op::FP::Sub, std::shared_ptr<Op::FP::Sub>, Op::FP::ModeBinary> cl(M("Op::FP"), "Sub", "The op class: FP::Sub\n  Input sizes may not differ");
	}
	{ // Op::FP::Mul file: line:41
		pybind11::class_<Op::FP::Mul, std::shared_ptr<Op::FP::Mul>, Op::FP::ModeBinary> cl(M("Op::FP"), "Mul", "The op class: FP::Mul\n  Input sizes may not differ");
	}
	{ // Op::FP::Div file: line:46
		pybind11::class_<Op::FP::Div, std::shared_ptr<Op::FP::Div>, Op::FP::ModeBinary> cl(M("Op::FP"), "Div", "The op class: FP::Div\n  Input sizes may not differ");
	}
	{ // Op::FP::FP file: line:55
		pybind11::class_<Op::FP::FP, std::shared_ptr<Op::FP::FP>, Op::Ternary<false>> cl(M("Op::FP"), "FP", "The ternary op class: FP::FP\n  Input sizes may differ");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_23.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_23(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::If file: line:14
		pybind11::class_<Op::If, std::shared_ptr<Op::If>, Op::Base> cl(M("Op"), "If", "The op class: If ");
		cl.def_readonly("cond", &Op::If::cond);
		cl.def_readonly("if_true", &Op::If::if_true);
		cl.def_readonly("if_false", &Op::If::if_false);
		cl.def("unsafe_add_reversed_children", (void (Op::If::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::If::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::If::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::If::*)() const) &Op::If::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::If::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Literal file: line:15
		pybind11::class_<Op::Literal, std::shared_ptr<Op::Literal>, Op::Base> cl(M("Op"), "Literal", "The op class Literal ");
		cl.def_readonly("value", &Op::Literal::value);
		cl.def("bit_length", (unsigned long long (Op::Literal::*)() const) &Op::Literal::bit_length, "Returns the bit_length of the value stored in Data\n  If Data contains a type that doesn't correspond to an Expr that is a subclass\n  of BitLength then an Usage exception is thrown\n\nC++: Op::Literal::bit_length() const --> unsigned long long");
		cl.def("unsafe_add_reversed_children", (void (Op::Literal::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Literal::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::Literal::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Literal::*)() const) &Op::Literal::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Literal::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_24.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_24(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::String::IndexOf file: line:14
		pybind11::class_<Op::String::IndexOf, std::shared_ptr<Op::String::IndexOf>, Op::Base> cl(M("Op::String"), "IndexOf", "The op class: String::IndexOf ");
		cl.def_readonly("str", &Op::String::IndexOf::str);
		cl.def_readonly("pattern", &Op::String::IndexOf::pattern);
		cl.def_readonly("start_index", &Op::String::IndexOf::start_index);
		cl.def("unsafe_add_reversed_children", (void (Op::String::IndexOf::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::String::IndexOf::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::String::IndexOf::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::String::IndexOf::*)() const) &Op::String::IndexOf::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::String::IndexOf::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::String::SubString file: line:14
		pybind11::class_<Op::String::SubString, std::shared_ptr<Op::String::SubString>, Op::Base> cl(M("Op::String"), "SubString", "The op class: String::SubString ");
		cl.def_readonly("start_index", &Op::String::SubString::start_index);
		cl.def_readonly("count", &Op::String::SubString::count);
		cl.def_readonly("full_string", &Op::String::SubString::full_string);
		cl.def("unsafe_add_reversed_children", (void (Op::String::SubString::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::String::SubString::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::String::SubString::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::String::SubString::*)() const) &Op::String::SubString::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::String::SubString::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_25.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_25(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::UIntBinary file: line:32
		pybind11::class_<Op::UIntBinary, std::shared_ptr<Op::UIntBinary>, Op::Base> cl(M("Op"), "UIntBinary", "An Op class that has an Expr operand and an int operand ");
		cl.def_readonly("expr", &Op::UIntBinary::expr);
		cl.def_readonly("integer", &Op::UIntBinary::integer);
		cl.def("unsafe_add_reversed_children", (void (Op::UIntBinary::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::UIntBinary::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::UIntBinary::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg("s"));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::UIntBinary::*)() const) &Op::UIntBinary::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::UIntBinary::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_26.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_26(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::String::IsDigit file: line:21
		pybind11::class_<Op::String::IsDigit, std::shared_ptr<Op::String::IsDigit>, Op::Unary> cl(M("Op::String"), "IsDigit", "The unary string op class: String::IsDigit ");
	}
	{ // Op::String::FromInt file: line:24
		pybind11::class_<Op::String::FromInt, std::shared_ptr<Op::String::FromInt>, Op::Unary> cl(M("Op::String"), "FromInt", "The unary string op class: String::FromInt ");
	}
	{ // Op::String::ToInt file: line:31
		pybind11::class_<Op::String::ToInt, std::shared_ptr<Op::String::ToInt>, Op::UIntBinary> cl(M("Op::String"), "ToInt", "The int binary op class: String::ToInt ");
	}
	{ // Op::String::Len file: line:34
		pybind11::class_<Op::String::Len, std::shared_ptr<Op::String::Len>, Op::UIntBinary> cl(M("Op::String"), "Len", "The int binary op class: String::Len ");
	}
	{ // Op::String::Contains file: line:43
		pybind11::class_<Op::String::Contains, std::shared_ptr<Op::String::Contains>, Op::Binary<false>> cl(M("Op::String"), "Contains", "The string binary op class: String::Contains\n  Input sizes may differ");
	}
	{ // Op::String::PrefixOf file: line:48
		pybind11::class_<Op::String::PrefixOf, std::shared_ptr<Op::String::PrefixOf>, Op::Binary<false>> cl(M("Op::String"), "PrefixOf", "The string binary op class: String::PrefixOf\n  Input sizes may differ");
	}
	{ // Op::String::SuffixOf file: line:53
		pybind11::class_<Op::String::SuffixOf, std::shared_ptr<Op::String::SuffixOf>, Op::Binary<false>> cl(M("Op::String"), "SuffixOf", "The string binary op class: String::SuffixOf\n  Input sizes may differ");
	}
	{ // Op::String::Replace file: line:62
		pybind11::class_<Op::String::Replace, std::shared_ptr<Op::String::Replace>, Op::Ternary<false>> cl(M("Op::String"), "Replace", "The ternary string op class: String::Replace\n  Input sizes may differ");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_27.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_27(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Op::Symbol file: line:14
		pybind11::class_<Op::Symbol, std::shared_ptr<Op::Symbol>, Op::Base> cl(M("Op"), "Symbol", "The op class Symbol ");
		cl.def_readonly("name", &Op::Symbol::name);
		cl.def("unsafe_add_reversed_children", (void (Op::Symbol::*)(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const) &Op::Symbol::unsafe_add_reversed_children, "Adds the raw expr children of the expr to the given stack in reverse\n  Warning: This does *not* give ownership, it transfers raw pointers\n\nC++: Op::Symbol::unsafe_add_reversed_children(class std::stack<const class Expr::Base *, class std::vector<const class Expr::Base *> > &) const --> void", pybind11::arg(""));
		cl.def("python_children", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> > (Op::Symbol::*)() const) &Op::Symbol::python_children, "Appends the expr children of the expr to the given vector\n  Note: This should only be used when returning children to python\n\nC++: Op::Symbol::python_children() const --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt, class std::shared_ptr<const class Expr::Base>, enum Mode::FP::Rounding, struct Mode::FP::Width> >");
	}
	{ // Op::Abs file: line:25
		pybind11::class_<Op::Abs, std::shared_ptr<Op::Abs>, Op::Unary> cl(M("Op"), "Abs", "The unary mathematical op class: Abs ");
	}
	{ // Op::Neg file: line:28
		pybind11::class_<Op::Neg, std::shared_ptr<Op::Neg>, Op::Unary> cl(M("Op"), "Neg", "The unary op class: Neg ");
	}
	{ // Op::Not file: line:31
		pybind11::class_<Op::Not, std::shared_ptr<Op::Not>, Op::Unary> cl(M("Op"), "Not", "The unary op class: Not ");
	}
	{ // Op::Invert file: line:34
		pybind11::class_<Op::Invert, std::shared_ptr<Op::Invert>, Op::Unary> cl(M("Op"), "Invert", "The unary op class: Invert ");
	}
	{ // Op::Reverse file: line:37
		pybind11::class_<Op::Reverse, std::shared_ptr<Op::Reverse>, Op::Unary> cl(M("Op"), "Reverse", "The unary bitwise op class: Reverse ");
	}
	{ // Op::SignExt file: line:44
		pybind11::class_<Op::SignExt, std::shared_ptr<Op::SignExt>, Op::UIntBinary> cl(M("Op"), "SignExt", "The int binary op class: SignExt ");
	}
	{ // Op::ZeroExt file: line:47
		pybind11::class_<Op::ZeroExt, std::shared_ptr<Op::ZeroExt>, Op::UIntBinary> cl(M("Op"), "ZeroExt", "The int binary op class: ZeroExt ");
	}
	{ // Op::Eq file: line:58
		pybind11::class_<Op::Eq, std::shared_ptr<Op::Eq>, Op::Binary<true>> cl(M("Op"), "Eq", "The binary comparison op class: Eq\n  Requires equal sized inputs");
	}
	{ // Op::Neq file: line:61
		pybind11::class_<Op::Neq, std::shared_ptr<Op::Neq>, Op::Binary<false>> cl(M("Op"), "Neq", "The binary comparison op class: Neq ");
	}
	{ // Op::Sub file: line:71
		pybind11::class_<Op::Sub, std::shared_ptr<Op::Sub>, Op::Binary<true>> cl(M("Op"), "Sub", "The mathematical binary op class: Sub\n  Requires equal sized inputs");
	}
	{ // Op::Widen file: line:100
		pybind11::class_<Op::Widen, std::shared_ptr<Op::Widen>, Op::Binary<true>> cl(M("Op"), "Widen", "The set binary op class: Widen\n  Requires equal sized inputs");
	}
	{ // Op::Union file: line:105
		pybind11::class_<Op::Union, std::shared_ptr<Op::Union>, Op::Binary<true>> cl(M("Op"), "Union", "The set binary op class: Union\n  Requires equal sized inputs");
	}
	{ // Op::Intersection file: line:110
		pybind11::class_<Op::Intersection, std::shared_ptr<Op::Intersection>, Op::Binary<true>> cl(M("Op"), "Intersection", "The set binary op class: Intersection\n  Requires equal sized inputs");
	}
	{ // Op::Concat file: line:115
		pybind11::class_<Op::Concat, std::shared_ptr<Op::Concat>, Op::Binary<false>> cl(M("Op"), "Concat", "The binary op class: Concat\n  Input sizes may differ");
	}
	{ // Op::Add file: line:126
		pybind11::class_<Op::Add, std::shared_ptr<Op::Add>, Op::Flat<true>> cl(M("Op"), "Add", "The flat math op class: Add\n  Requires equal sized inputs");
	}
	{ // Op::Mul file: line:131
		pybind11::class_<Op::Mul, std::shared_ptr<Op::Mul>, Op::Flat<true>> cl(M("Op"), "Mul", "The flat op class: Mul\n  Requires equal sized inputs");
	}
	{ // Op::Or file: line:138
		pybind11::class_<Op::Or, std::shared_ptr<Op::Or>, Op::Flat<true>> cl(M("Op"), "Or", "The flat op class: Or\n  Requires equal sized inputs");
	}
	{ // Op::And file: line:143
		pybind11::class_<Op::And, std::shared_ptr<Op::And>, Op::Flat<true>> cl(M("Op"), "And", "The flat op class: And\n  Requires equal sized inputs");
	}
	{ // Op::Xor file: line:148
		pybind11::class_<Op::Xor, std::shared_ptr<Op::Xor>, Op::Flat<true>> cl(M("Op"), "Xor", "The flat op class: Xor\n  Requires equal sized inputs");
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_28.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_28(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::extract(const unsigned long long, const unsigned long long, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:16
	M("Create").def("extract", [](const unsigned long long & a0, const unsigned long long & a1, const class std::shared_ptr<const class Expr::Base> & a2) -> std::shared_ptr<const class Expr::Base> { return Create::extract(a0, a1, a2); }, "", pybind11::arg("high"), pybind11::arg("low"), pybind11::arg("from"));
	M("Create").def("extract", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned long long, const unsigned long long, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::extract, "Create an Expr with an Extract op\n  Expr pointers may not be nullptr\n\nC++: Create::extract(const unsigned long long, const unsigned long long, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("high"), pybind11::arg("low"), pybind11::arg("from"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_29.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_29(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::FP::from_2s_complement_bv_signed(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) file: line:26
	M("Create::FP").def("from_2s_complement_bv_signed", [](const enum Mode::FP::Rounding & a0, const class std::shared_ptr<const class Expr::Base> & a1, const struct Mode::FP::Width & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::from_2s_complement_bv_signed(a0, a1, a2); }, "", pybind11::arg("m"), pybind11::arg("bv"), pybind11::arg("w"));
	M("Create::FP").def("from_2s_complement_bv_signed", (class std::shared_ptr<const class Expr::Base> (*)(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::from_2s_complement_bv_signed, "C++: Create::FP::from_2s_complement_bv_signed(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("m"), pybind11::arg("bv"), pybind11::arg("w"), pybind11::arg("sp"));

	// Create::FP::from_2s_complement_bv_unsigned(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) file: line:34
	M("Create::FP").def("from_2s_complement_bv_unsigned", [](const enum Mode::FP::Rounding & a0, const class std::shared_ptr<const class Expr::Base> & a1, const struct Mode::FP::Width & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::from_2s_complement_bv_unsigned(a0, a1, a2); }, "", pybind11::arg("m"), pybind11::arg("bv"), pybind11::arg("w"));
	M("Create::FP").def("from_2s_complement_bv_unsigned", (class std::shared_ptr<const class Expr::Base> (*)(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::from_2s_complement_bv_unsigned, "C++: Create::FP::from_2s_complement_bv_unsigned(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("m"), pybind11::arg("bv"), pybind11::arg("w"), pybind11::arg("sp"));

	// Create::FP::from_fp(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) file: line:16
	M("Create::FP").def("from_fp", [](const enum Mode::FP::Rounding & a0, const class std::shared_ptr<const class Expr::Base> & a1, const struct Mode::FP::Width & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::from_fp(a0, a1, a2); }, "", pybind11::arg("m"), pybind11::arg("fp"), pybind11::arg("w"));
	M("Create::FP").def("from_fp", (class std::shared_ptr<const class Expr::Base> (*)(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::from_fp, "Create an Expr with an FromFP op\n  Expr pointers may not be nullptr\n\nC++: Create::FP::from_fp(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("m"), pybind11::arg("fp"), pybind11::arg("w"), pybind11::arg("sp"));

	// Create::FP::from_not_2s_complement_bv(const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) file: line:16
	M("Create::FP").def("from_not_2s_complement_bv", [](const class std::shared_ptr<const class Expr::Base> & a0, const struct Mode::FP::Width & a1) -> std::shared_ptr<const class Expr::Base> { return Create::FP::from_not_2s_complement_bv(a0, a1); }, "", pybind11::arg("bv"), pybind11::arg("w"));
	M("Create::FP").def("from_not_2s_complement_bv", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::from_not_2s_complement_bv, "Create an Expr with an FromNot2sComplementBV op\n  Expr pointers may not be nullptr\n\nC++: Create::FP::from_not_2s_complement_bv(const class std::shared_ptr<const class Expr::Base> &, const struct Mode::FP::Width &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("bv"), pybind11::arg("w"), pybind11::arg("sp"));

	// Create::FP::to_bv_signed(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:25
	M("Create::FP").def("to_bv_signed", [](const enum Mode::FP::Rounding & a0, const class std::shared_ptr<const class Expr::Base> & a1, const unsigned long long & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::to_bv_signed(a0, a1, a2); }, "", pybind11::arg("mode"), pybind11::arg("fp"), pybind11::arg("bit_length"));
	M("Create::FP").def("to_bv_signed", (class std::shared_ptr<const class Expr::Base> (*)(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::to_bv_signed, "A shortcut to to_bv<Signed>; exists for the API \n\nC++: Create::FP::to_bv_signed(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("mode"), pybind11::arg("fp"), pybind11::arg("bit_length"), pybind11::arg("sp"));

	// Create::FP::to_bv_unsigned(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:31
	M("Create::FP").def("to_bv_unsigned", [](const enum Mode::FP::Rounding & a0, const class std::shared_ptr<const class Expr::Base> & a1, const unsigned long long & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::to_bv_unsigned(a0, a1, a2); }, "", pybind11::arg("mode"), pybind11::arg("fp"), pybind11::arg("bit_length"));
	M("Create::FP").def("to_bv_unsigned", (class std::shared_ptr<const class Expr::Base> (*)(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::to_bv_unsigned, "A shortcut to to_bv<Unsigned>; exists for the API \n\nC++: Create::FP::to_bv_unsigned(const enum Mode::FP::Rounding, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("mode"), pybind11::arg("fp"), pybind11::arg("bit_length"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_3.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_3(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Hash::Hashed file: line:18
		pybind11::class_<Hash::Hashed, Hash::Hashed*> cl(M("Hash"), "Hashed", "A type that has a precomputed hash value\n  Warning: No virtual destructor; do *not* delete by base class pointer; avoid slicing!");
		cl.def_readonly("hash", &Hash::Hashed::hash);
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_30.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_30(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::FP::to_ieee_bv(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:24
	M("Create::FP").def("to_ieee_bv", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::FP::to_ieee_bv(a0); }, "", pybind11::arg("x"));
	M("Create::FP").def("to_ieee_bv", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::to_ieee_bv, "Create a Expr with an FP::ToIEEEBV op\n  Expr pointers may not be nullptr\n\nC++: Create::FP::to_ieee_bv(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::FP::add(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) file: line:42
	M("Create::FP").def("add", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const enum Mode::FP::Rounding & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::add(a0, a1, a2); }, "", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"));
	M("Create::FP").def("add", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::add, "C++: Create::FP::add(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"), pybind11::arg("sp"));

	// Create::FP::sub(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) file: line:46
	M("Create::FP").def("sub", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const enum Mode::FP::Rounding & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::sub(a0, a1, a2); }, "", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"));
	M("Create::FP").def("sub", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::sub, "C++: Create::FP::sub(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"), pybind11::arg("sp"));

	// Create::FP::mul(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) file: line:50
	M("Create::FP").def("mul", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const enum Mode::FP::Rounding & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::mul(a0, a1, a2); }, "", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"));
	M("Create::FP").def("mul", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::mul, "C++: Create::FP::mul(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"), pybind11::arg("sp"));

	// Create::FP::div(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) file: line:54
	M("Create::FP").def("div", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const enum Mode::FP::Rounding & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::div(a0, a1, a2); }, "", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"));
	M("Create::FP").def("div", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::div, "C++: Create::FP::div(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const enum Mode::FP::Rounding, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("mode"), pybind11::arg("sp"));

	// Create::FP::fp(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:66
	M("Create::FP").def("fp", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const class std::shared_ptr<const class Expr::Base> & a2) -> std::shared_ptr<const class Expr::Base> { return Create::FP::fp(a0, a1, a2); }, "", pybind11::arg("first"), pybind11::arg("second"), pybind11::arg("third"));
	M("Create::FP").def("fp", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::FP::fp, "Create an Expr with an FP::FP op\n  Expr pointers may not be nullptr\n\nC++: Create::FP::fp(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("first"), pybind11::arg("second"), pybind11::arg("third"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_31.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_31(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::if_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:16
	M("Create").def("if_", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const class std::shared_ptr<const class Expr::Base> & a2) -> std::shared_ptr<const class Expr::Base> { return Create::if_(a0, a1, a2); }, "", pybind11::arg("cond"), pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("if_", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::if_, "Create an Expr with an If op\n  Expr pointers may not be nullptr\n\nC++: Create::if_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("cond"), pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::literal(const char *const, class std::shared_ptr<const struct Annotation::Vec>) file: line:14
	M("Create").def("literal", [](const char *const a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg(""));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const char *const, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "This function exists to prevent accidental use by explicit rejection \n\nC++: Create::literal(const char *const, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg(""), pybind11::arg(""));

	// Create::literal(const bool, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const bool & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const bool, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const bool, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(std::string, class std::shared_ptr<const struct Annotation::Vec>) file: line:27
	M("Create").def("literal", [](std::string const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(std::string, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(std::string, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const double, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const double & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const double, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const double, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const float, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const float & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const float, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const float, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(class std::shared_ptr<const struct PyObj::VS>, class std::shared_ptr<const struct Annotation::Vec>) file: line:27
	M("Create").def("literal", [](class std::shared_ptr<const struct PyObj::VS> const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(class std::shared_ptr<const struct PyObj::VS>, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(class std::shared_ptr<const struct PyObj::VS>, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const unsigned char, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const unsigned char & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned char, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const unsigned char, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const unsigned short, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const unsigned short & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned short, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const unsigned short, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const unsigned int, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const unsigned int & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned int, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const unsigned int, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:21
	M("Create").def("literal", [](const unsigned long long & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

	// Create::literal(struct BigInt, class std::shared_ptr<const struct Annotation::Vec>) file: line:27
	M("Create").def("literal", [](struct BigInt const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::literal(a0); }, "", pybind11::arg("data"));
	M("Create").def("literal", (class std::shared_ptr<const class Expr::Base> (*)(struct BigInt, class std::shared_ptr<const struct Annotation::Vec>)) &Create::literal, "C++: Create::literal(struct BigInt, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("data"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_32.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_32(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::String::from_int(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:20
	M("Create::String").def("from_int", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::String::from_int(a0); }, "", pybind11::arg("x"));
	M("Create::String").def("from_int", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::from_int, "Create an Expr with a String::FromInt op\n  Note: Currently Ints are taken in as BVs\n  Note: For now, we just set the size to 2 bytes larger than the input\n  This should be large-enough, and isn't as bad an over-estimation as INT_MAX or anything\n  Expr pointers may not be nullptr\n  Note: This is not trivial due to its length calculation\n\nC++: Create::String::from_int(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::String::index_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:16
	M("Create::String").def("index_of", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const class std::shared_ptr<const class Expr::Base> & a2, const unsigned long long & a3) -> std::shared_ptr<const class Expr::Base> { return Create::String::index_of(a0, a1, a2, a3); }, "", pybind11::arg("str"), pybind11::arg("pattern"), pybind11::arg("start_index"), pybind11::arg("bit_length"));
	M("Create::String").def("index_of", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::index_of, "Create an Expr with a String::IndexOf op\n  Expr pointers may not be nullptr\n\nC++: Create::String::index_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("str"), pybind11::arg("pattern"), pybind11::arg("start_index"), pybind11::arg("bit_length"), pybind11::arg("sp"));

	// Create::String::replace(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:17
	M("Create::String").def("replace", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const class std::shared_ptr<const class Expr::Base> & a2) -> std::shared_ptr<const class Expr::Base> { return Create::String::replace(a0, a1, a2); }, "", pybind11::arg("full"), pybind11::arg("search"), pybind11::arg("replacement"));
	M("Create::String").def("replace", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::replace, "Create an Expr with a String::Replace op\n  Despite being ternary, this is not a trivial op because of the unique length calculation\n  Expr pointers may not be nullptr\n\nC++: Create::String::replace(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("full"), pybind11::arg("search"), pybind11::arg("replacement"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_33.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_33(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::String::sub_string(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:43
	M("Create::String").def("sub_string", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1, const class std::shared_ptr<const class Expr::Base> & a2) -> std::shared_ptr<const class Expr::Base> { return Create::String::sub_string(a0, a1, a2); }, "", pybind11::arg("start_index"), pybind11::arg("count"), pybind11::arg("full_string"));
	M("Create::String").def("sub_string", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::sub_string, "Create an Expr with a String::SubString op\n  Expr pointers may not be nullptr\n\nC++: Create::String::sub_string(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("start_index"), pybind11::arg("count"), pybind11::arg("full_string"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_34.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_34(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::String::is_digit(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:22
	M("Create::String").def("is_digit", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::String::is_digit(a0); }, "", pybind11::arg("x"));
	M("Create::String").def("is_digit", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::is_digit, "Create a bool Expr with an String::IsDigit op\n  Expr pointers may not be nullptr\n\nC++: Create::String::is_digit(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::String::to_int(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:35
	M("Create::String").def("to_int", [](const class std::shared_ptr<const class Expr::Base> & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::String::to_int(a0, a1); }, "", pybind11::arg("expr"), pybind11::arg("integer"));
	M("Create::String").def("to_int", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::to_int, "Create an Expr with an String::SignExt op\n  Note: Currently Ints are taken in as BVs\n  Expr pointers may not be nullptr\n\nC++: Create::String::to_int(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("expr"), pybind11::arg("integer"), pybind11::arg("sp"));

	// Create::String::len(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:46
	M("Create::String").def("len", [](const class std::shared_ptr<const class Expr::Base> & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::String::len(a0, a1); }, "", pybind11::arg("expr"), pybind11::arg("integer"));
	M("Create::String").def("len", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::len, "Create an Expr with an String::Len op\n  Note: Currently Ints are output as BVs\n  Expr pointers may not be nullptr\n\nC++: Create::String::len(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("expr"), pybind11::arg("integer"), pybind11::arg("sp"));

	// Create::String::contains(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:60
	M("Create::String").def("contains", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::String::contains(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create::String").def("contains", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::contains, "Create an Expr with a String::Contains op\n  Expr pointers may not be nullptr\n\nC++: Create::String::contains(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::String::prefix_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:70
	M("Create::String").def("prefix_of", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::String::prefix_of(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create::String").def("prefix_of", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::prefix_of, "Create an Expr with a String::PrefixOf op\n  Expr pointers may not be nullptr\n\nC++: Create::String::prefix_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::String::suffix_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:80
	M("Create::String").def("suffix_of", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::String::suffix_of(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create::String").def("suffix_of", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::String::suffix_of, "Create an Expr with a String::SuffixOf op\n  Expr pointers may not be nullptr\n\nC++: Create::String::suffix_of(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_35.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_35(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::symbol_bool(std::string, class std::shared_ptr<const struct Annotation::Vec>) file: line:35
	M("Create").def("symbol_bool", [](std::string const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::symbol_bool(a0); }, "", pybind11::arg("name"));
	M("Create").def("symbol_bool", (class std::shared_ptr<const class Expr::Base> (*)(std::string, class std::shared_ptr<const struct Annotation::Vec>)) &Create::symbol_bool, "C++: Create::symbol_bool(std::string, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("name"), pybind11::arg("sp"));

	// Create::symbol_bv(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:40
	M("Create").def("symbol_bv", [](std::string const & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::symbol_bv(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("bit_length"));
	M("Create").def("symbol_bv", (class std::shared_ptr<const class Expr::Base> (*)(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::symbol_bv, "C++: Create::symbol_bv(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("name"), pybind11::arg("bit_length"), pybind11::arg("sp"));

	// Create::symbol_fp(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:46
	M("Create").def("symbol_fp", [](std::string const & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::symbol_fp(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("bit_length"));
	M("Create").def("symbol_fp", (class std::shared_ptr<const class Expr::Base> (*)(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::symbol_fp, "C++: Create::symbol_fp(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("name"), pybind11::arg("bit_length"), pybind11::arg("sp"));

	// Create::symbol_string(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:52
	M("Create").def("symbol_string", [](std::string const & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::symbol_string(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("bit_length"));
	M("Create").def("symbol_string", (class std::shared_ptr<const class Expr::Base> (*)(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::symbol_string, "C++: Create::symbol_string(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("name"), pybind11::arg("bit_length"), pybind11::arg("sp"));

	// Create::symbol_vs(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:58
	M("Create").def("symbol_vs", [](std::string const & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::symbol_vs(a0, a1); }, "", pybind11::arg("name"), pybind11::arg("bit_length"));
	M("Create").def("symbol_vs", (class std::shared_ptr<const class Expr::Base> (*)(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::symbol_vs, "C++: Create::symbol_vs(std::string, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("name"), pybind11::arg("bit_length"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_36.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_36(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::abs(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:24
	M("Create").def("abs", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::abs(a0); }, "", pybind11::arg("x"));
	M("Create").def("abs", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::abs, "Create an Expr with an Abs op\n  Expr pointers may not be nullptr\n\nC++: Create::abs(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::neg(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:31
	M("Create").def("neg", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::neg(a0); }, "", pybind11::arg("x"));
	M("Create").def("neg", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::neg, "Create an Expr with an Neg op\n  Expr pointers may not be nullptr\n\nC++: Create::neg(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::not_(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:38
	M("Create").def("not_", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::not_(a0); }, "", pybind11::arg("x"));
	M("Create").def("not_", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::not_, "Create an Expr with an Not op\n  Expr pointers may not be nullptr\n\nC++: Create::not_(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::invert(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:45
	M("Create").def("invert", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::invert(a0); }, "", pybind11::arg("x"));
	M("Create").def("invert", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::invert, "Create an Expr with an Invert op\n  Expr pointers may not be nullptr\n\nC++: Create::invert(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::reverse(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:52
	M("Create").def("reverse", [](const class std::shared_ptr<const class Expr::Base> & a0) -> std::shared_ptr<const class Expr::Base> { return Create::reverse(a0); }, "", pybind11::arg("x"));
	M("Create").def("reverse", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::reverse, "Create an Expr with an Reverse op\n  Expr pointers may not be nullptr\n\nC++: Create::reverse(const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("x"), pybind11::arg("sp"));

	// Create::sign_ext(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:63
	M("Create").def("sign_ext", [](const class std::shared_ptr<const class Expr::Base> & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::sign_ext(a0, a1); }, "", pybind11::arg("expr"), pybind11::arg("integer"));
	M("Create").def("sign_ext", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::sign_ext, "Create an Expr with an SignExt op\n  Expr pointers may not be nullptr\n\nC++: Create::sign_ext(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("expr"), pybind11::arg("integer"), pybind11::arg("sp"));

	// Create::zero_ext(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) file: line:72
	M("Create").def("zero_ext", [](const class std::shared_ptr<const class Expr::Base> & a0, const unsigned long long & a1) -> std::shared_ptr<const class Expr::Base> { return Create::zero_ext(a0, a1); }, "", pybind11::arg("expr"), pybind11::arg("integer"));
	M("Create").def("zero_ext", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>)) &Create::zero_ext, "Create an Expr with an ZeroExt op\n  Expr pointers may not be nullptr\n\nC++: Create::zero_ext(const class std::shared_ptr<const class Expr::Base> &, const unsigned long long, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("expr"), pybind11::arg("integer"), pybind11::arg("sp"));

	// Create::eq(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:87
	M("Create").def("eq", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::eq(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("eq", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::eq, "Create a Bool Expr with an Eq op\n  Expr pointers may not be nullptr\n\nC++: Create::eq(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::neq(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:97
	M("Create").def("neq", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::neq(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("neq", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::neq, "Create a Bool Expr with an Neq op\n  Expr pointers may not be nullptr\n\nC++: Create::neq(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::uge(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:117
	M("Create").def("uge", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::uge(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("uge", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::uge, "A shortcut for compare<UGE>; exists for the API \n\nC++: Create::uge(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::ugt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:123
	M("Create").def("ugt", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::ugt(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("ugt", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::ugt, "A shortcut for compare<UGT>; exists for the API \n\nC++: Create::ugt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::ule(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:129
	M("Create").def("ule", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::ule(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("ule", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::ule, "A shortcut for compare<ULE>; exists for the API \n\nC++: Create::ule(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::ult(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:135
	M("Create").def("ult", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::ult(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("ult", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::ult, "A shortcut for compare<ULT>; exists for the API \n\nC++: Create::ult(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::sge(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:141
	M("Create").def("sge", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::sge(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("sge", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::sge, "A shortcut for compare<SGE>; exists for the API \n\nC++: Create::sge(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::sgt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:147
	M("Create").def("sgt", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::sgt(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("sgt", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::sgt, "A shortcut for compare<SGT>; exists for the API \n\nC++: Create::sgt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::sle(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:153
	M("Create").def("sle", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::sle(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("sle", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::sle, "A shortcut for compare<SLE>; exists for the API \n\nC++: Create::sle(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::slt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:159
	M("Create").def("slt", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::slt(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("slt", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::slt, "A shortcut for compare<SLT>; exists for the API \n\nC++: Create::slt(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_37.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_37(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::sub(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:169
	M("Create").def("sub", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::sub(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("sub", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::sub, "Create an Expr with an Sub op\n  Expr pointers may not be nullptr\n\nC++: Create::sub(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::div_signed(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:186
	M("Create").def("div_signed", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::div_signed(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("div_signed", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::div_signed, "A shortcut for div<Signed>; exists for the API \n\nC++: Create::div_signed(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::div_unsigned(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:192
	M("Create").def("div_unsigned", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::div_unsigned(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("div_unsigned", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::div_unsigned, "A shortcut for div<Unsigned>; exists for the API \n\nC++: Create::div_unsigned(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::mod_signed(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:208
	M("Create").def("mod_signed", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::mod_signed(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("mod_signed", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::mod_signed, "A shortcut for mod<Signed>; exists for the API \n\nC++: Create::mod_signed(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::mod_unsigned(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:214
	M("Create").def("mod_unsigned", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::mod_unsigned(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("mod_unsigned", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::mod_unsigned, "A shortcut for mod<Unsigned>; exists for the API \n\nC++: Create::mod_unsigned(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::shift_l(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:232
	M("Create").def("shift_l", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::shift_l(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("shift_l", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::shift_l, "A shortcut for shift<Left>; exists for the API \n\nC++: Create::shift_l(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::shift_arithmetic_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:238
	M("Create").def("shift_arithmetic_right", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::shift_arithmetic_right(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("shift_arithmetic_right", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::shift_arithmetic_right, "A shortcut for shift<ArithmeticRight>; exists for the API \n\nC++: Create::shift_arithmetic_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::shift_logical_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:245
	M("Create").def("shift_logical_right", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::shift_logical_right(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("shift_logical_right", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::shift_logical_right, "A shortcut for shift<LogicalRight>; exists for the API \n\nC++: Create::shift_logical_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::rotate_left(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:261
	M("Create").def("rotate_left", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::rotate_left(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("rotate_left", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::rotate_left, "A shortcut for rotate<Left>; exists for the API \n\nC++: Create::rotate_left(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::rotate_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:267
	M("Create").def("rotate_right", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::rotate_right(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("rotate_right", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::rotate_right, "A shortcut for rotate<Right>; exists for the API \n\nC++: Create::rotate_right(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::widen(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:278
	M("Create").def("widen", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::widen(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("widen", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::widen, "Create an Expr with an Widen op\n  Expr pointers may not be nullptr\n\nC++: Create::widen(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::union_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:287
	M("Create").def("union_", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::union_(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("union_", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::union_, "Create an Expr with an Union op\n  Expr pointers may not be nullptr\n\nC++: Create::union_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::intersection_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:296
	M("Create").def("intersection_", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::intersection_(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("intersection_", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::intersection_, "Create an Expr with an Intersection op\n  Expr pointers may not be nullptr\n\nC++: Create::intersection_(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::concat(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) file: line:305
	M("Create").def("concat", [](const class std::shared_ptr<const class Expr::Base> & a0, const class std::shared_ptr<const class Expr::Base> & a1) -> std::shared_ptr<const class Expr::Base> { return Create::concat(a0, a1); }, "", pybind11::arg("left"), pybind11::arg("right"));
	M("Create").def("concat", (class std::shared_ptr<const class Expr::Base> (*)(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>)) &Create::concat, "Create an Expr with an Concat op\n  Expr pointers may not be nullptr\n\nC++: Create::concat(const class std::shared_ptr<const class Expr::Base> &, const class std::shared_ptr<const class Expr::Base> &, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("left"), pybind11::arg("right"), pybind11::arg("sp"));

	// Create::add(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) file: line:320
	M("Create").def("add", [](class std::vector<class std::shared_ptr<const class Expr::Base> > const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::add(a0); }, "", pybind11::arg("operands"));
	M("Create").def("add", (class std::shared_ptr<const class Expr::Base> (*)(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>)) &Create::add, "Create an Expr with an Add op\n  Expr pointers may not be nullptr\n\nC++: Create::add(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("operands"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_38.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_38(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Create::mul(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) file: line:328
	M("Create").def("mul", [](class std::vector<class std::shared_ptr<const class Expr::Base> > const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::mul(a0); }, "", pybind11::arg("operands"));
	M("Create").def("mul", (class std::shared_ptr<const class Expr::Base> (*)(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>)) &Create::mul, "Create an Expr with an Mul op\n  Expr pointers may not be nullptr\n\nC++: Create::mul(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("operands"), pybind11::arg("sp"));

	// Create::or_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) file: line:338
	M("Create").def("or_", [](class std::vector<class std::shared_ptr<const class Expr::Base> > const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::or_(a0); }, "", pybind11::arg("operands"));
	M("Create").def("or_", (class std::shared_ptr<const class Expr::Base> (*)(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>)) &Create::or_, "Create an Expr with an Or op\n  Expr pointers may not be nullptr\n\nC++: Create::or_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("operands"), pybind11::arg("sp"));

	// Create::and_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) file: line:345
	M("Create").def("and_", [](class std::vector<class std::shared_ptr<const class Expr::Base> > const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::and_(a0); }, "", pybind11::arg("operands"));
	M("Create").def("and_", (class std::shared_ptr<const class Expr::Base> (*)(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>)) &Create::and_, "Create an Expr with an And op\n  Expr pointers may not be nullptr\n\nC++: Create::and_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("operands"), pybind11::arg("sp"));

	// Create::xor_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) file: line:352
	M("Create").def("xor_", [](class std::vector<class std::shared_ptr<const class Expr::Base> > const & a0) -> std::shared_ptr<const class Expr::Base> { return Create::xor_(a0); }, "", pybind11::arg("operands"));
	M("Create").def("xor_", (class std::shared_ptr<const class Expr::Base> (*)(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>)) &Create::xor_, "Create an Expr with an Xor op\n  Expr pointers may not be nullptr\n\nC++: Create::xor_(class std::vector<class std::shared_ptr<const class Expr::Base> >, class std::shared_ptr<const struct Annotation::Vec>) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("operands"), pybind11::arg("sp"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_39.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_39(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Backend::Z3::Solver file: line:13
		pybind11::class_<Backend::Z3::Solver, std::shared_ptr<Backend::Z3::Solver>> cl(M("Backend::Z3"), "Solver", "A Z3 Solver object ");
		cl.def( pybind11::init( [](Backend::Z3::Solver const &o){ return new Backend::Z3::Solver(o); } ) );
		cl.def("assign", (class Backend::Z3::Solver & (Backend::Z3::Solver::*)(const class Backend::Z3::Solver &)) &Backend::Z3::Solver::operator=, "C++: Backend::Z3::Solver::operator=(const class Backend::Z3::Solver &) --> class Backend::Z3::Solver &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](Backend::Z3::Solver const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_4.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Mode::BigInt file: line:13
	pybind11::enum_<Mode::BigInt>(M("Mode"), "BigInt", "A mask used to define the type of comparison to be used ")
		.value("Str", Mode::BigInt::Str)
		.value("Int", Mode::BigInt::Int);

;

	// Mode::Compare file: line:15
	pybind11::enum_<Mode::Compare>(M("Mode"), "Compare", "A mask used to define the type of comparison to be used ")
		.value("UGE", Mode::Compare::UGE)
		.value("UGT", Mode::Compare::UGT)
		.value("ULE", Mode::Compare::ULE)
		.value("ULT", Mode::Compare::ULT)
		.value("SGE", Mode::Compare::SGE)
		.value("SGT", Mode::Compare::SGT)
		.value("SLE", Mode::Compare::SLE)
		.value("SLT", Mode::Compare::SLT);

;

	// Mode::is_signed(const enum Mode::Compare) file: line:18
	M("Mode").def("is_signed", (bool (*)(const enum Mode::Compare)) &Mode::is_signed, "Return true iff a Compare is signed \n\nC++: Mode::is_signed(const enum Mode::Compare) --> bool", pybind11::arg("c"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_40.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_40(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // Backend::Z3::Z3 file: line:24
		pybind11::class_<Backend::Z3::Z3, std::shared_ptr<Backend::Z3::Z3>> cl(M("Backend::Z3"), "Z3", "The Z3 backend\n  Warning: All Z3 backends within a given thread share their data");
		cl.def( pybind11::init( [](){ return new Backend::Z3::Z3(); } ) );
		cl.def("name", (const char * (Backend::Z3::Z3::*)() const) &Backend::Z3::Z3::name, "The name of this backend \n\nC++: Backend::Z3::Z3::name() const --> const char *", pybind11::return_value_policy::automatic);
		cl.def("simplify", (class std::shared_ptr<const class Expr::Base> (Backend::Z3::Z3::*)(const class Expr::Base *const)) &Backend::Z3::Z3::simplify, "Simplify the given expr\n  expr may not be nullptr\n\nC++: Backend::Z3::Z3::simplify(const class Expr::Base *const) --> class std::shared_ptr<const class Expr::Base>", pybind11::arg("expr"));
		cl.def("clear_persistent_data", (void (Backend::Z3::Z3::*)()) &Backend::Z3::Z3::clear_persistent_data, "Clears translocation data \n\nC++: Backend::Z3::Z3::clear_persistent_data() --> void");
		cl.def("satisfiable", (bool (Backend::Z3::Z3::*)(class Backend::Z3::Solver &) const) &Backend::Z3::Z3::satisfiable, "Check to see if the solver is in a satisfiable state \n\nC++: Backend::Z3::Z3::satisfiable(class Backend::Z3::Solver &) const --> bool", pybind11::arg("solver"));
		cl.def("satisfiable", (bool (Backend::Z3::Z3::*)(class Backend::Z3::Solver &, const class std::vector<const class Expr::Base *> &)) &Backend::Z3::Z3::satisfiable, "Check to see if the solver is in a satisfiable state \n\nC++: Backend::Z3::Z3::satisfiable(class Backend::Z3::Solver &, const class std::vector<const class Expr::Base *> &) --> bool", pybind11::arg("solver"), pybind11::arg("extra_constraints"));
		cl.def("solution", (bool (Backend::Z3::Z3::*)(const class Expr::Base *const, const class Expr::Base *const, class Backend::Z3::Solver &, const class std::vector<const class Expr::Base *> &)) &Backend::Z3::Z3::solution, "Check if expr = sol is a solution to the given solver; none may be nullptr \n\nC++: Backend::Z3::Z3::solution(const class Expr::Base *const, const class Expr::Base *const, class Backend::Z3::Solver &, const class std::vector<const class Expr::Base *> &) --> bool", pybind11::arg("expr"), pybind11::arg("sol"), pybind11::arg("solver"), pybind11::arg("extra_constraints"));
		cl.def("solution", (bool (Backend::Z3::Z3::*)(const class Expr::Base *const, const class Expr::Base *const, class Backend::Z3::Solver &)) &Backend::Z3::Z3::solution, "Check to see if sol is a solution to expr w.r.t the solver; neither may be nullptr \n\nC++: Backend::Z3::Z3::solution(const class Expr::Base *const, const class Expr::Base *const, class Backend::Z3::Solver &) --> bool", pybind11::arg("expr"), pybind11::arg("sol"), pybind11::arg("solver"));
		cl.def("unsat_core", (class std::vector<class std::shared_ptr<const class Expr::Base> > (Backend::Z3::Z3::*)(const class Backend::Z3::Solver &)) &Backend::Z3::Z3::unsat_core, "Return the unsat core from the solver\n  Warning: This assumes all of solver->assertions were added by add<true>\n\nC++: Backend::Z3::Z3::unsat_core(const class Backend::Z3::Solver &) --> class std::vector<class std::shared_ptr<const class Expr::Base> >", pybind11::arg("solver"));
		cl.def("eval", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > (Backend::Z3::Z3::*)(const class Expr::Base *const, class Backend::Z3::Solver &, const unsigned long long)) &Backend::Z3::Z3::eval, "Evaluate expr, return up to n different solutions\n  No pointers may be nullptr\n\nC++: Backend::Z3::Z3::eval(const class Expr::Base *const, class Backend::Z3::Solver &, const unsigned long long) --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> >", pybind11::arg("expr"), pybind11::arg("solver"), pybind11::arg("n_sol"));
		cl.def("eval", (class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > (Backend::Z3::Z3::*)(const class Expr::Base *const, class Backend::Z3::Solver &, const unsigned long long, const class std::vector<const class Expr::Base *> &)) &Backend::Z3::Z3::eval, "Evaluate expr, return up to n different solutions\n  No pointers may be nullptr\n\nC++: Backend::Z3::Z3::eval(const class Expr::Base *const, class Backend::Z3::Solver &, const unsigned long long, const class std::vector<const class Expr::Base *> &) --> class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> >", pybind11::arg("expr"), pybind11::arg("s"), pybind11::arg("n"), pybind11::arg("extra_constraints"));
		cl.def("batch_eval", (class std::vector<class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > > (Backend::Z3::Z3::*)(const class std::vector<const class Expr::Base *> &, class Backend::Z3::Solver &, const unsigned long long)) &Backend::Z3::Z3::batch_eval, "Evaluate every expr, return up to n different solutions\n  No pointers may be nullptr\n\nC++: Backend::Z3::Z3::batch_eval(const class std::vector<const class Expr::Base *> &, class Backend::Z3::Solver &, const unsigned long long) --> class std::vector<class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > >", pybind11::arg("exprs"), pybind11::arg("s"), pybind11::arg("n"));
		cl.def("batch_eval", (class std::vector<class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > > (Backend::Z3::Z3::*)(const class std::vector<const class Expr::Base *> &, class Backend::Z3::Solver &, const unsigned long long, const class std::vector<const class Expr::Base *> &)) &Backend::Z3::Z3::batch_eval, "Evaluate every expr, return up to n different solutions\n  No pointers may be nullptr\n\nC++: Backend::Z3::Z3::batch_eval(const class std::vector<const class Expr::Base *> &, class Backend::Z3::Solver &, const unsigned long long, const class std::vector<const class Expr::Base *> &) --> class std::vector<class std::vector<class std::variant<bool, std::string, float, double, class std::shared_ptr<const struct PyObj::VS>, unsigned char, unsigned short, unsigned int, unsigned long long, struct BigInt> > >", pybind11::arg("exprs"), pybind11::arg("s"), pybind11::arg("n"), pybind11::arg("extra_constraints"));
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_5.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_5(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Mode::FP::Rounding file: line:10
	pybind11::enum_<Mode::FP::Rounding>(M("Mode::FP"), "Rounding", "FP modes supported by claripy ")
		.value("NearestTiesEven", Mode::FP::Rounding::NearestTiesEven)
		.value("NearestTiesAwayFromZero", Mode::FP::Rounding::NearestTiesAwayFromZero)
		.value("TowardsZero", Mode::FP::Rounding::TowardsZero)
		.value("TowardsPositiveInf", Mode::FP::Rounding::TowardsPositiveInf)
		.value("TowardsNegativeInf", Mode::FP::Rounding::TowardsNegativeInf);

;

	{ // Mode::FP::Width file: line:17
		pybind11::class_<Mode::FP::Width, std::shared_ptr<Mode::FP::Width>> cl(M("Mode::FP"), "Width", "A floating point width struct ");
		cl.def( pybind11::init( [](){ return new Mode::FP::Width(); } ) );
		cl.def( pybind11::init( [](Mode::FP::Width const &o){ return new Mode::FP::Width(o); } ) );
		cl.def_readwrite("exp", &Mode::FP::Width::exp);
		cl.def_readwrite("mantissa", &Mode::FP::Width::mantissa);
		cl.def("mantissa_raw", (unsigned int (Mode::FP::Width::*)() const) &Mode::FP::Width::mantissa_raw, "The width of the mantissa, excluding the implicit 1 bit \n\nC++: Mode::FP::Width::mantissa_raw() const --> unsigned int");
		cl.def("width", (unsigned long long (Mode::FP::Width::*)() const) &Mode::FP::Width::width, "The full width of the fp \n\nC++: Mode::FP::Width::width() const --> unsigned long long");
		cl.def("no_sign_width", (unsigned long long (Mode::FP::Width::*)() const) &Mode::FP::Width::no_sign_width, "The full width of the fp \n\nC++: Mode::FP::Width::no_sign_width() const --> unsigned long long");
		cl.def("assign", (struct Mode::FP::Width & (Mode::FP::Width::*)(const struct Mode::FP::Width &)) &Mode::FP::Width::operator=, "C++: Mode::FP::Width::operator=(const struct Mode::FP::Width &) --> struct Mode::FP::Width &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](Mode::FP::Width const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_6.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Mode::LR file: line:13
	pybind11::enum_<Mode::LR>(M("Mode"), "LR", "A mask used to denote Left or Right ")
		.value("Left", Mode::LR::Left)
		.value("Right", Mode::LR::Right);

;

	// Mode::Shift file: line:11
	pybind11::enum_<Mode::Shift>(M("Mode"), "Shift", "A mask used to describe a type of bit shift ")
		.value("Left", Mode::Shift::Left)
		.value("LogicalRight", Mode::Shift::LogicalRight)
		.value("ArithmeticRight", Mode::Shift::ArithmeticRight);

;

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_7.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_7(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Mode::Sign::FP file: line:17
	pybind11::enum_<Mode::Sign::FP>(M("Mode::Sign"), "FP", "An Sign enum with an underlying signed value where non-signed-ness is disallowed\n  The underlying values of the enum values are 1 and -1\n  signed specifier is required for cross-platform support")
		.value("Minus", Mode::Sign::FP::Minus)
		.value("Plus", Mode::Sign::FP::Plus);

;

	// Mode::Sign::Real file: line:23
	pybind11::enum_<Mode::Sign::Real>(M("Mode::Sign"), "Real", "An Sign enum with an underlying signed value where non-signed-ness is allowed\n  The underlying values of the enum values are 1, -1, and 0\n  signed specifier is required for cross-platform support")
		.value("Minus", Mode::Sign::Real::Minus)
		.value("None", Mode::Sign::Real::None)
		.value("Plus", Mode::Sign::Real::Plus);

;

	// Mode::Sign::to_real(const enum Mode::Sign::FP) file: line:26
	M("Mode::Sign").def("to_real", (enum Mode::Sign::Real (*)(const enum Mode::Sign::FP)) &Mode::Sign::to_real, "Convert an FP to a Real \n\nC++: Mode::Sign::to_real(const enum Mode::Sign::FP) --> enum Mode::Sign::Real", pybind11::arg("f"));

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_8.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_8(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Mode::Signed file: line:13
	pybind11::enum_<Mode::Signed>(M("Mode"), "Signed", "A mask used to denote Signed or Unsigned ")
		.value("Signed", Mode::Signed::Signed)
		.value("Unsigned", Mode::Signed::Unsigned);

;

}
} // namespace API::Binder


//
// File: binder/raw_output/unknown/unknown_9.cpp
//


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

namespace API::Binder {
void bind_unknown_unknown_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // BigInt file: line:16
		pybind11::class_<BigInt, std::shared_ptr<BigInt>> cl(M(""), "BigInt", "The arbitrary precision type claricpp uses ");
		cl.def( pybind11::init( [](BigInt const &o){ return new BigInt(o); } ) );
		cl.def( pybind11::init( [](){ return new BigInt(); } ) );
		cl.def_readwrite("value", &BigInt::value);
		cl.def_readwrite("bit_length", &BigInt::bit_length);
		cl.def_static("from_c_str", (struct BigInt (*)(const char *const, const unsigned long long)) &BigInt::from_c_str<Mode::BigInt::Str>, "C++: BigInt::from_c_str(const char *const, const unsigned long long) --> struct BigInt", pybind11::arg("s"), pybind11::arg("bit_length"));
		cl.def_static("from_c_str", (struct BigInt (*)(const char *const, const unsigned long long)) &BigInt::from_c_str<Mode::BigInt::Int>, "C++: BigInt::from_c_str(const char *const, const unsigned long long) --> struct BigInt", pybind11::arg("s"), pybind11::arg("bit_length"));
		cl.def_static("from_c_str", (struct BigInt (*)(const char *const, const unsigned long long)) &BigInt::from_c_str, "Convert the input to a BigInt using the default mode \n\nC++: BigInt::from_c_str(const char *const, const unsigned long long) --> struct BigInt", pybind11::arg("s"), pybind11::arg("bit_length"));
		cl.def_static("mode", (enum Mode::BigInt (*)(const enum Mode::BigInt)) &BigInt::mode, "Set the default BigInt mode to m \n\nC++: BigInt::mode(const enum Mode::BigInt) --> enum Mode::BigInt", pybind11::arg("m"));
		cl.def_static("mode", (enum Mode::BigInt (*)()) &BigInt::mode, "Get the default mode \n\nC++: BigInt::mode() --> enum Mode::BigInt");
		cl.def("assign", (struct BigInt & (BigInt::*)(const struct BigInt &)) &BigInt::operator=, "C++: BigInt::operator=(const struct BigInt &) --> struct BigInt &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		cl.def("__str__", [](BigInt const &o) -> std::string { std::ostringstream s; s << o; return s.str(); } );
	}
}
} // namespace API::Binder
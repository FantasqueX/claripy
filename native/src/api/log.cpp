/**
 * @file
 * \ingroup api
 */
#include "log.hpp"

#include "../util.hpp"

#include <pybind11/functional.h>


/** The python log backend */
struct PythonLog final : public Util::Log::Backend::Base {
  private:
    /** For brevity */
    using Lvl = ::Util::Log::Level::Level;

  public:
    /** The log function type */
    using Func = std::function<void(CCSC, std::underlying_type_t<Lvl>, std::string)>;
    /** Constructor */
    PythonLog(const Func &log_func) : py_log(log_func) {}
    /** Backend name */
    const char *name() const noexcept final { return "PythonLog"; }
    /** Log the given message */
    void log(CCSC id, const Lvl &lvl, Util::LazyStr &&msg) const final {
        py_log(id, Util::to_underlying(lvl), msg());
    }
    /** Flush the log if applicable
     *  We choose to leave this to python
     */
    void flush() const final {}
    /** The python logging function
     *  Note: we choose to store a reference in case pybind11 cleans up internally on shutdown
     */
    const Func py_log;
};

/** Restore the C++ log backend */
static void set_log_default() noexcept try {
    Util::Log::Backend::set<Util::Log::Backend::Default>();
}
UTIL_FALLBACKLOG_CATCH("Failed to restore C++ default logger")

void API::logger(Binder::ModuleGetter &m) {
    register_at_exit(set_log_default);
    m("API").def(
        "install_logger",
        [](const PythonLog::Func &py_log) { Util::Log::Backend::set<PythonLog>(py_log); },
        "Installs log_func to Claricpp's logger. The function "
        "will be called as py_log(id: str, level: int, msg: str)",
        pybind11::arg("py_log"));
    // TODO: handle non default log levels (i.e. 1)
    m("API").def(
        "get_log_level", []() { return Util::to_underlying(Util::Log::Level::get()); },
        "Get Claricpp's log level2.");
#ifndef CONSTANT_LOG_LEVEL
    m("API").def(
        "set_log_level",
        [](const unsigned lvl) {
    #ifdef DEBUG
            Util::Log::Level::set
    #else
            Util::Log::Level::silent_set
    #endif
                (static_cast<Util::Log::Level::Level>(lvl));
        },
        "Set the level Claricpp's log level. When a python logger is installed this functionally "
        "defines the minimum log level at which Claricpp will generate a log message and send it "
        "to python's logger.",
        pybind11::arg("lvl"));
#endif
}

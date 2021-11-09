/**
 * @file
 * \ingroup util
 * @brief This file defines public logging functions
 * @todo: Check to see if stream style would be faster than function style
 */
#ifndef R_UTIL_LOG_LOG_HPP_
#define R_UTIL_LOG_LOG_HPP_

#include "level.hpp"
#include "macros.hpp"
#include "private/send_to_backend.hpp"

#include "../sink.hpp"


/** A local macro used to define standard log functions */
#define DEFINE_LOG_LEVEL(LEVEL, NAME)                                                              \
    /** Log to a given log with given log level */                                                 \
    template <typename Log, typename... Args> void NAME(Args &&...args) {                          \
        if UTIL_LOG_LEVEL_CONSTEXPR (Level::enabled(Level::Level::LEVEL)) {                        \
            static UTIL_LOG_LEVEL_CONSTEXPR const LogID id { Log::log_id };                        \
            Private::send_to_backend(id, Level::Level::LEVEL, std::forward<Args>(args)...);        \
        }                                                                                          \
        else {                                                                                     \
            sink(std::forward<Args>(args)...);                                                     \
        }                                                                                          \
    }                                                                                              \
    /** Log to default log with given log level */                                                 \
    template <typename... Args> inline void NAME(Args &&...args) {                                 \
        NAME<Default>(std::forward<Args>(args)...);                                                \
    }


namespace Util::Log {

    /** Define the default log class */
    UTIL_LOG_DEFINE_LOG_CLASS(Default)

    // Define all log functions
    DEFINE_LOG_LEVEL(Verbose, verbose)
    DEFINE_LOG_LEVEL(Debug, debug)
    DEFINE_LOG_LEVEL(Info, info)
    DEFINE_LOG_LEVEL(Warning, warning)
    DEFINE_LOG_LEVEL(Error, error)
    DEFINE_LOG_LEVEL(Critical, critical)

} // namespace Util::Log

// Cleanup local macros
#undef DEFINE_LOG_LEVEL

#endif

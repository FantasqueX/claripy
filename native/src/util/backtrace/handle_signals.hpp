/**
 * @file
 * \ingroup util
 * @brief This file defines a way to enable backtrace support on signals
 */
#ifndef R_UTIL_BACKTRACE_HANDLESIGNALS_HPP_
#define R_UTIL_BACKTRACE_HANDLESIGNALS_HPP_

#include <atomic>

namespace Util::Backtrace {
    /** Enable signal handling so backtraces are printed on signals using backward */
    void backward_handle_signals();

    /** Enable signal handling so backtraces are printed on signals */
    inline void handle_signals() {
        backward_handle_signals();
    }
} // namespace Util::Backtrace

#endif

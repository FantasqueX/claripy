/** \defgroup util Claricpp Utilities
 * @brief A group of useful classes and methods which all parts of claricpp can utilize
 */

/**
 * @file
 * @brief This file includes all public pieces of util
 * \ingroup util
 */
#ifndef R_UTIL_HPP_
#define R_UTIL_HPP_

#include "util/affirm.hpp"
#include "util/affirm_not_null_debug.hpp"
#include "util/ansi_color_codes.hpp"
#include "util/avg.hpp"
#include "util/backtrace.hpp"
#include "util/bitmask.hpp"
#include "util/checked_static_cast.hpp"
#include "util/declare.hpp"
#include "util/demangle.hpp"
#include "util/dependent_constant.hpp"
#include "util/do_once.hpp"
#include "util/err.hpp"
#include "util/file_line_hash.hpp"
#include "util/fnv1a.hpp"
#include "util/full.hpp"
#include "util/heap_cache.hpp"
#include "util/hex_to_num.hpp"
#include "util/inc.hpp"
#include "util/log.hpp"
#include "util/macros.hpp"
#include "util/make_derived_shared.hpp"
#include "util/map_add.hpp"
#include "util/max.hpp"
#include "util/min.hpp"
#include "util/narrow.hpp"
#include "util/norm_path_hash.hpp"
#include "util/ostream.hpp"
#include "util/pointer_cast.hpp"
#include "util/pow.hpp"
#include "util/range_to_str.hpp"
#include "util/recurrence_guard.hpp"
#include "util/ref.hpp"
#include "util/run_after_main.hpp"
#include "util/run_before_main.hpp"
#include "util/run_on_destruction.hpp"
#include "util/safe_alloc.hpp"
#include "util/set_join.hpp"
#include "util/sign.hpp"
#include "util/sink.hpp"
#include "util/stack_limit.hpp"
#include "util/str_prefix.hpp"
#include "util/strlen.hpp"
#include "util/thread_safe.hpp"
#include "util/to_hex.hpp"
#include "util/to_str.hpp"
#include "util/to_underlying.hpp"
#include "util/type.hpp"
#include "util/variant_verify_index_type_is.hpp"
#include "util/verify_syscall.hpp"
#include "util/weak_cache.hpp"
#include "util/widen.hpp"

#endif

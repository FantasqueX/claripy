/**
 * @file
 * \ingroup util
 * @brief This file contains the possible exceptions that indicate an internal claricpp failure
 * These exceptions are not expected to be raised if claricpp is operating as intended
 */
#ifndef R_UTIL_ERR_UNEXPECTED_HPP_
#define R_UTIL_ERR_UNEXPECTED_HPP_

#include "claricpp.hpp"


namespace Util::Err {

    /** Base unexpected exception
     *  All unexpected exceptions must derive from this
     */
    UTIL_ERR_DEFINE_NONFINAL_EXCEPTION(Unexpected, Claricpp);

    /** Hash Collision exception */
    UTIL_ERR_DEFINE_NONFINAL_EXCEPTION(Collision, Unexpected);

    /** Null pointer exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Null, Unexpected);

    /** Invalid path exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(BadPath, Unexpected);

    /** Syscall failure exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Syscall, Unexpected);

    /** Bad size exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Size, Unexpected);

    /** Bad index exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Index, Unexpected);

    /** Bad cast exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(BadCast, Unexpected);

    /** Hash Collision exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(HashCollision, Collision);

    /** Bad variant access exception */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(BadVariantAccess, Unexpected);

    /** Raised when a virtual function that should have been overridden was called */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(MissingVirtualFunction, Claricpp);

    /** Raised when a function is given invalid arguments */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Usage, Claricpp);

    /** Raised when a recurrence guarded function recurses too many times */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(RecurrenceLimit, Claricpp);

    /** Raised when something unknown occurs */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Unknown, Claricpp);

    /** Raised when an unsupported op is invoked */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(NotSupported, Claricpp);

    /** Raised when a dynamic type error occurs */
    UTIL_ERR_DEFINE_FINAL_EXCEPTION(Type, Claricpp);

} // namespace Util::Err

#endif

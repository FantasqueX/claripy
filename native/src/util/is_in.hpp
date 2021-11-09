/**
 * @file
 * \ingroup util
 * @brief This file defines a method for determining if T is in a type list Args...
 */
#ifndef R_UTIL_ISIN_HPP_
#define R_UTIL_ISIN_HPP_

#include "is_ancestor.hpp"
#include "is_same.hpp"


namespace Util {

    /** Return true if T in Args */
    template <typename T, typename... Args>
    UTIL_ICCBOOL qualified_is_in { (is_exactly_same<T, Args> || ...) };

    /** Return true if T in Args; ignores const-ness of everything */
    template <typename T, typename... Args>
    UTIL_ICCBOOL is_in_ignore_const { (is_same_ignore_const<T, Args> || ...) };

    /** Return true if is_ancestor<Args[i], T> for any i */
    template <typename T, typename... Args>
    UTIL_ICCBOOL ancestor_is_in { (is_ancestor<Args, T> || ...) };

} // namespace Util

#endif

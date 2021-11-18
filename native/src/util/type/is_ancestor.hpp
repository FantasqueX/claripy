/**
 * @file
 * \ingroup util
 * @brief This file defines a method to determine if Derived derives from or is Base
 */
#ifndef R_UTIL_TYPE_ISANCESTOR_HPP_
#define R_UTIL_TYPE_ISANCESTOR_HPP_

#include "transfer_const.hpp"

#include <type_traits>


namespace Util::Type {

    /** Return true if Derived is Base or subclasses Base
     *  Unlike is_base_of, this returns true for <T, T> where T is a primitive
     */
    template <typename Base, typename Derived>
    UTIL_ICCBOOL is_ancestor { std::is_same_v<TransferConst<Base, Derived>, Derived> ||
                               std::is_base_of_v<Base, Derived> };

} // namespace Util::Type

#endif

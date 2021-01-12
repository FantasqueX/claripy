/**
 * @file
 * \ingroup utils
 * @brief This file contains declares the Utils:inc() function
 */
#ifndef __UTILS_INC_HPP__
#define __UTILS_INC_HPP__

#include "private/has_pre_inc_op.hpp"

#include "../constants.hpp"

#include <atomic>


/** A local macro to enforce consistency */
#define ATOM_T std::atomic<Constants::UInt>


namespace Utils {

    /** Thread-safe-ly increment a static number and return the result
     *  The template Args are used as a map key to allow this function to be reused as needed
     *  This function is primarily meant to run before main to help configure things
     */
    template <typename... Args, std::enable_if_t<has_pre_inc_op<ATOM_T>, int> = 0>
    inline Constants::UInt inc() {
        static ATOM_T ret(0);
        return ++ret;
    }

} // namespace Utils


#endif

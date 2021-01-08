/**
 * @file
 * @brief This file defines the underling hash function for Expressions
 */
#ifndef __EXPRESSION_HASH_SINGULAR_HPP__
#define __EXPRESSION_HASH_SINGULAR_HPP__

#include "../../constants.hpp"

#include <string>


namespace Expression::Hash {

    /** A struct used to allow different return types of singular depending on T
     *  The general case is undefined, specializations must be defined
     */
    template <typename> struct SingularRetMap;

    /** A using declaration to shortcut usage of SingularRetMap */
    template <typename T> using SRet = typename SingularRetMap<T>::RetType;

    /** Determines how hash handles the type passed
     *  This hash does not need to be a real hash, it just has to represent T as an SRet<T>
     *  which will be appened to a stringstream that will be properly hashed
     *  The general case is undefined, specializations must be defined
     */
    template <typename T> SRet<T> singular(const T &);

    /** A specialization for T = char * */
    template <> struct SingularRetMap<char *> { using RetType = Constants::CCSC; };
    /** A specialization for T = char * */
    template <> SRet<char *> singular<char *>(char *const &c) { return c; }

} // namespace Expression::Hash

#endif

/**
 * @file
 * @brief This file defines a method to create an Expression with an symbol Op
 */
#ifndef R_CREATE_SYMBOL_HPP_
#define R_CREATE_SYMBOL_HPP_

#include "constants.hpp"


namespace Create {

    /** Create a Bool Expression with an symbol op */
    inline EBasePtr symbol(std::string &&name, SPAV &&sp = nullptr) {
        return Expression::factory<Expression::Bool>(
            true, Op::factory<Op::Symbol>(std::move(name)), std::move(sp));
    }

    /** Create a Expression with an symbol op
     *  This override is for sized Expression types
     */
    template <typename T>
    EBasePtr symbol(std::string &&name, const Constants::UInt bit_length, SPAV &&sp = nullptr) {
        namespace Ex = Expression;

        // Type checks
        static_assert(Utils::is_ancestor<Ex::Bits, T>,
                      "Create::symbol argument types must be a subclass of Bits");
        static_assert(std::is_final_v<T>, "Create::symbol's T must be a final type");

        // Construct expression
        return Ex::factory<T>(true, Op::factory<Op::Symbol>(std::move(name)), bit_length,
                              std::move(sp));
    }

} // namespace Create

#endif

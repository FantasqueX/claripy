/**
 * @file
 * @brief This file defines a method to create an Expr with an symbol Op
 */
#ifndef R_CREATE_SYMBOL_HPP_
#define R_CREATE_SYMBOL_HPP_

#include "constants.hpp"


namespace Create {

    /** Create a Bool Expr with an symbol op */
    inline Expr::BasePtr symbol(std::string &&name, Annotation::SPAV &&sp = nullptr) {
        return Expr::factory<Expr::Bool>(true, Op::factory<Op::Symbol>(std::move(name)),
                                         std::move(sp));
    }

    /** Create a Expr with an symbol op
     *  This override is for sized Expr types
     */
    template <typename T>
    Expr::BasePtr symbol(std::string &&name, const UInt bit_length,
                         Annotation::SPAV &&sp = nullptr) {
        // Type checks
        static_assert(Util::Type::is_ancestor<Expr::Bits, T>,
                      "Create::symbol argument types must be a subclass of Bits");
        static_assert(std::is_final_v<T>, "Create::symbol's T must be a final type");

        // Construct expr
        return Expr::factory<T>(true, Op::factory<Op::Symbol>(std::move(name)), bit_length,
                                std::move(sp));
    }

} // namespace Create

#endif

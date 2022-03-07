/**
 * @file
 * @brief This file defines a group of fp create methods that are trivial passthrough methods
 * For example: Functions which just shell out to mode_binary
 */
#ifndef R_CREATE_FP_TRIVIAL_HPP_
#define R_CREATE_FP_TRIVIAL_HPP_

#include "../private/binary.hpp"
#include "../private/mode_binary.hpp"
#include "../private/ternary.hpp"
#include "../private/unary.hpp"


namespace Create::FP {

    /********************************************************************/
    /*                   Unary Passthrough Functions                    */
    /********************************************************************/

    /** Create a Expr with an FP::ToIEEEBV op
     *  Expr pointers may not be nullptr
     */
    inline Expr::BasePtr to_ieee_bv(const Expr::BasePtr &x, Annotation::SPAV sp = empty_spav) {
        return Private::unary_explicit<Expr::BV, Op::FP::ToIEEEBV, Expr::FP>(x, std::move(sp));
    }

    /********************************************************************/
    /*                 ModeBinary Passthrough Functions                 */
    /********************************************************************/

/** A local macro used for fp mode binary math ops with size mode first */
#define FP_MB_SMF_ARITH(FN, OP)                                                                    \
    inline Expr::BasePtr FN(const Expr::BasePtr &left, const Expr::BasePtr &right,                 \
                            const Mode::FP::Rounding mode, Annotation::SPAV sp = empty_spav) {     \
        return Private::mode_binary<Op::FP::OP>(left, right, mode, std::move(sp));                 \
    }

    /** Create a Expr with an FP::Add op
     *  Expr pointers may not be nullptr
     */
    FP_MB_SMF_ARITH(add, Add);
    /** Create a Expr with an FP::Sub op
     *  Expr pointers may not be nullptr
     */
    FP_MB_SMF_ARITH(sub, Sub);
    /** Create a Expr with an FP::Mul op
     *  Expr pointers may not be nullptr
     */
    FP_MB_SMF_ARITH(mul, Mul);
    /** Create a Expr with an FP::Div op
     *  Expr pointers may not be nullptr
     */
    FP_MB_SMF_ARITH(div, Div);

    // Cleanup
#undef FP_MB_SMF_ARITH

    /********************************************************************/
    /*                  Ternary Passthrough Functions                   */
    /********************************************************************/

    /** Create an Expr with an FP::FP op
     *  Expr pointers may not be nullptr
     */
    inline Expr::BasePtr fp(const Expr::BasePtr &first, const Expr::BasePtr &second,
                            const Expr::BasePtr &third, Annotation::SPAV sp = empty_spav) {
        return Private::ternary_explicit<Expr::FP, Op::FP::FP, Expr::BV>(first, second, third,
                                                                         std::move(sp));
    }

} // namespace Create::FP

#endif

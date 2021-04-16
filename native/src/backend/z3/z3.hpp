/**
 * @file
 * @brief This file defines the Z3 backend
 */
#ifndef __BACKEND_Z3_Z3_HPP__
#define __BACKEND_Z3_Z3_HPP__

#include "abstract.hpp"
#include "convert.hpp"

#include "../../error.hpp"
#include "../generic.hpp"


namespace Backend::Z3 {

    /** The solver type */
    using Solver = Z3::Solver;

    /** The Z3 backend */
    class Z3 final : public Generic<Z3ASTPtr, Solver> {
      private:
        /********************************************************************/
        /*                        Function Overrides                        */
        /********************************************************************/


        /** This dynamic dispatcher converts expr into a backend object
         *  All arguments of expr that are not primitives have been
         *  pre-converted into backend objects and are in args
         *  Arguments must be popped off the args stack if used
         *  Warning: This function may internally do unchecked static casting, we permit this
         *  *only* if the cuid of the expression is of or derive from the type being cast to.
         */
        BackendObj dispatch_conversion(const ExprRawPtr expr,
                                       std::vector<BORCPtr> &args) override final {

            // We define local macros below to enforce consistency
            // across 'trivial' ops to reduce copy-paste errors.

#define UNARY_CASE(OP, FN)                                                                        \
    case Op::OP::static_cuid: {                                                                   \
        auto ret { std::move(FN(*args.back())) };                                                 \
        args.pop_back();                                                                          \
        return ret;                                                                               \
    }

#define BINARY_DISPATCH(FN)                                                                       \
    const auto size = args.size();                                                                \
    auto ret { std::move(FN(*args[size - 2], *args[size - 1])) };                                 \
    args.resize(size - 2);                                                                        \
    return ret;

#define BINARY_CASE(OP, FN)                                                                       \
    case Op::OP::static_cuid: {                                                                   \
        BINARY_DISPATCH(FN);                                                                      \
    }

// Passing templated objects to macros can be messy since ','s are in both
// For simplicity and consistency we define a binary op macro for this case
#define BINARY_TEMPLATE_CASE(OP, FN, ...)                                                         \
    case Op::OP<__VA_ARGS__>::static_cuid: {                                                      \
        const auto &func = FN<__VA_ARGS__>;                                                       \
        BINARY_DISPATCH(func);                                                                    \
    }

#define INT_BINARY_CASE(OP, FN)                                                                   \
    case Op::OP::static_cuid: {                                                                   \
        static_assert(Op::is_int_binary<Op::OP>, WHOAMI "Op::" #OP "is not IntBinary");           \
        using To = Constants::CTSC<Op::IntBinary>;                                                \
        auto ret { std::move(FN(*args.back(), static_cast<To>(expr)->integer)) };                 \
        args.pop_back();                                                                          \
        return ret;                                                                               \
    }

#define MODE_BINARY_CASE(OP, FN)                                                                  \
    case Op::OP::static_cuid: {                                                                   \
        const auto size = args.size();                                                            \
        static_assert(Op::is_mode_binary<Op::OP>, WHOAMI "Op::" #OP "is not ModeBinary");         \
        using To = Constants::CTSC<Op::FP::ModeBinary>;                                           \
        auto ret { std::move(                                                                     \
            FN(static_cast<To>(expr)->mode, *args[size - 2], *args[size - 1])) };                 \
        args.resize(size - 2);                                                                    \
        return ret;                                                                               \
    }

#define TERNARY_CASE(OP, FN)                                                                      \
    case Op::OP::static_cuid: {                                                                   \
        const auto size = args.size();                                                            \
        auto ret { std::move(FN(*args[size - 3], *args[size - 2], *args[size - 1])) };            \
        args.resize(size - 3);                                                                    \
        return ret;                                                                               \
    }

#define FLAT_CASE(OP, FN)                                                                         \
    case Op::OP::static_cuid: {                                                                   \
        const auto a_size = args.size();                                                          \
        static_assert(Op::is_flat<Op::OP>, WHOAMI "Op::" #OP "is not Flat");                      \
        using To = Constants::CTSC<Op::Flat>;                                                     \
        const auto n = static_cast<To>(expr)->operands.size();                                    \
        auto ret { std::move(FN(&(args.data()[a_size - n]), n)) };                                \
        args.resize(a_size - n);                                                                  \
        return ret;                                                                               \
    }

            // Switch on expr type
            switch (expr->op->cuid) {

                // This should never be hit
                default: {
                    using Usage = Utils::Error::Unexpected;
                    throw Err::IncorrectUsage(
                        WHOAMI_WITH_SOURCE
                        "Unknown expression op given to Z3::dispatch_conversion."
                        "\nOp CUID: ",
                        expr->op->cuid);
                }

                // Unsupported ops
                case Op::Widen::static_cuid: // fallthrough
                case Op::Union::static_cuid: // fallthrough
                case Op::Intersection::static_cuid: {
                    using Usage = Error::Backend;
                    throw Err::Unsupported(
                        WHOAMI_WITH_SOURCE
                        "Unknown expression op given to Z3::dispatch_conversion."
                        "\nOp CUID: ",
                        expr->op->cuid);
                }

                    /************************************************/
                    /*              Top-Level Trivial               */
                    /************************************************/

                    // Unary

                    UNARY_CASE(Neg, Convert::neg);
                    UNARY_CASE(Abs, Convert::abs);
                    UNARY_CASE(Invert, Convert::invert);
                    UNARY_CASE(Reverse, Convert::reverse);

                    // IntBinary

                    INT_BINARY_CASE(SignExt, Convert::signext);
                    INT_BINARY_CASE(ZeroExt, Convert::zeroext);

                    // Binary

                    BINARY_CASE(Eq, Convert::eq);

                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, true, true, true);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, true, true, false);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, true, false, true);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, true, false, false);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, false, true, true);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, false, true, false);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, false, false, true);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare, false, false, false);

                    BINARY_CASE(Sub, Convert::sub);

                    BINARY_TEMPLATE_CASE(Div, Convert::div, true);
                    BINARY_TEMPLATE_CASE(Div, Convert::div, false);

                    BINARY_CASE(Pow, Convert::pow);

                    BINARY_TEMPLATE_CASE(Mod, Convert::mod, true);
                    BINARY_TEMPLATE_CASE(Mod, Convert::mod, false);

                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, true, true);
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, true, false);
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, false, true);
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, false, false);

                    BINARY_TEMPLATE_CASE(Rotate, Convert::rotate, true);
                    BINARY_TEMPLATE_CASE(Rotate, Convert::rotate, false);

                    BINARY_CASE(Concat, Convert::concat);

                    // Flat

                    FLAT_CASE(Add, Convert::add);
                    FLAT_CASE(Mul, Convert::mul);
                    FLAT_CASE(Or, Convert::or_);
                    FLAT_CASE(And, Convert::and_);
                    FLAT_CASE(Xor, Convert::xor_);

                    // Other

                    TERNARY_CASE(If, Convert::if_);

                case Op::Extract::static_cuid: {
                    using To = Constants::CTSC<Op::Extract>;
                    auto ret { std::move(Convert::extract(
                        static_cast<To>(expr)->high, static_cast<To>(expr)->low, *args.back())) };
                    args.pop_back();
                    return ret;
                }
                case Op::Literal::static_cuid: {
                    break; // TODO
                }
                case Op::Symbol::static_cuid: {
                    break; // TODO
                }

                    /************************************************/
                    /*                  FP Trivial                  */
                    /************************************************/

                    // Unary

                    UNARY_CASE(FP::ToIEEEBV, Convert::FP::to_ieee_bv);
                    UNARY_CASE(FP::IsInf, Convert::FP::is_inf);
                    UNARY_CASE(FP::IsNan, Convert::FP::is_nan);

                    // Binary

                    BINARY_CASE(FP::NE, Convert::FP::ne);

                    // Mode Binary

                    MODE_BINARY_CASE(FP::Add, Convert::FP::add)
                    MODE_BINARY_CASE(FP::Sub, Convert::FP::sub)
                    MODE_BINARY_CASE(FP::Div, Convert::FP::div)

                    // Ternary

                    TERNARY_CASE(FP::FP, Convert::FP::fp)

                    // Other

                case Op::FP::ToBV::static_cuid: {
                    using To = Constants::CTSC<Op::FP::ToBV>;
                    auto ret { std::move(
                        Convert::FP::to_bv(static_cast<To>(expr)->mode, *args.back())) };
                    args.pop_back();
                    return ret;
                }

                    /************************************************/
                    /*                String Trivial                */
                    /************************************************/

                    // Unary

                    UNARY_CASE(String::IsDigit, Convert::String::is_digit);
                    UNARY_CASE(String::FromInt, Convert::String::from_int);
                    UNARY_CASE(String::Unit, Convert::String::unit);

                    // Int Binary

                    INT_BINARY_CASE(String::ToInt, Convert::String::to_int);
                    INT_BINARY_CASE(String::Len, Convert::String::len);

                    // Binary

                    BINARY_CASE(String::Contains, Convert::String::contains);
                    BINARY_CASE(String::PrefixOf, Convert::String::prefix_of);
                    BINARY_CASE(String::SuffixOf, Convert::String::suffix_of);

                    // Ternary

                    TERNARY_CASE(String::Replace, Convert::String::replace);

                    // Other

                    TERNARY_CASE(String::SubString, Convert::sub_string)

                case Op::String::IndexOf::static_cuid: {
                    using To = Constants::CTSC<Op::String::IndexOf>;
                    const auto size = args.size();
                    auto ret { std::move(Convert::String::index_of(
                        *args[size - 2], *args[size - 1], static_cast<To>(expr)->start_index)) };
                    args.resize(size - 2);
                    return ret;
                }
            }

                // Cleanup
#undef UNARY_CASE
#undef BINARY_DISPATCH
#undef BINARY_CASE
#undef BINARY_TEMPLATE_CASE
#undef INT_BINARY_CASE
#undef MODE_BINARY_CASE
#undef TERNARY_CASE
#undef FLAT_CASE
        }
    };

} // namespace Backend::Z3

#endif

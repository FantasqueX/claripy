/**
 * @file
 * @brief This file defines the Z3 backend
 */
#ifndef R_BACKEND_Z3_Z3_HPP_
#define R_BACKEND_Z3_Z3_HPP_

#include "abstract.hpp"
#include "convert.hpp"
#include "tl_ctx.hpp"

#include "../../error.hpp"
#include "../generic.hpp"


namespace Backend::Z3 {

    /** The Z3 backend */
    class Z3 final : public Generic<z3::expr, false> {
        /** Z3 parent class */
        using Super = Generic<z3::expr, false>;

      public:
        /********************************************************************/
        /*                        Function Overrides                        */
        /********************************************************************/

        /** Destructor */
        ~Z3() noexcept override = default;

        /** Clear caches to decrease memory pressure */
        void downsize() override {
            Super::downsize();
            is_true_cache.scoped_unique().first.clear();
            is_false_cache.scoped_unique().first.clear();
        }

        /** Create a tls solver */
        [[nodiscard]] virtual std::shared_ptr<void> new_tls_solver() const override final {
            return { std::make_shared<z3::solver>(Private::tl_ctx) };
        }

        /** The name of this backend */
        [[nodiscard]] Constants::CCS name() const noexcept override final { return "z3"; }

        /** Return true if expr is always true */
        bool is_true(const Expression::RawPtr &expr) {
            auto [in_cache, res] { get_from_cache(is_true_cache, expr->hash) };
            if (in_cache) {
                return res;
            }
            const bool ret { convert(expr).is_true() };
            is_true_cache.scoped_unique().first.emplace(expr->hash, ret);
            is_false_cache.scoped_unique().first.emplace(expr->hash, ret);
            return ret;
        }

        /** Return true if expr is always false */
        bool is_false(const Expression::RawPtr &expr) {
            auto [in_cache, res] { get_from_cache(is_false_cache, expr->hash) };
            if (in_cache) {
                return res;
            }
            const bool ret { convert(expr).is_true() };
            is_false_cache.scoped_unique().first.emplace(expr->hash, ret);
            is_true_cache.scoped_unique().first.emplace(expr->hash, ret);
            return ret;
        }

        /** Simplify the given expression
         *  @todo: Currently this is stubbed, it needs to be implemented
         */
        Expression::BasePtr simplify(const Expression::RawPtr expr) override final {
            (void) expr;
            throw Utils::Error::Unexpected::NotSupported("This has yet to be implemented"); // TODO
        }

        /** This dynamic dispatcher converts expr into a backend object
         *  All arguments of expr that are not primitives have been
         *  pre-converted into backend objects and are in args
         *  Arguments must be popped off the args stack if used
         *  Warning: This function may internally do unchecked static casting, we permit this
         *  *only* if the cuid of the expression is of or derive from the type being cast to.
         */
        z3::expr dispatch_conversion(const Expression::RawPtr expr,
                                     std::vector<Constants::CTS<z3::expr>> &args) override final {

            // We define local macros below to enforce consistency
            // across 'trivial' ops to reduce copy-paste errors.

#define UNARY_CASE(OP, FN)                                                                        \
    case Op::OP::static_cuid: {                                                                   \
        auto ret { FN(*args.back()) };                                                            \
        args.pop_back();                                                                          \
        return ret;                                                                               \
    }

#define BINARY_DISPATCH(FN)                                                                       \
    const auto size { args.size() };                                                              \
    auto ret { FN(*args[size - 2], *args[size - 1]) };                                            \
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
        const constexpr auto func { FN<__VA_ARGS__> };                                            \
        BINARY_DISPATCH(func);                                                                    \
    }

#define UINT_BINARY_CASE(OP, FN)                                                                  \
    case Op::OP::static_cuid: {                                                                   \
        static_assert(Op::is_uint_binary<Op::OP>, "Op::" #OP " is not UIntBinary");               \
        using To = Constants::CTSC<Op::UIntBinary>;                                               \
        auto ret { FN(*args.back(), Utils::checked_static_cast<To>(expr->op.get())->integer) };   \
        args.pop_back();                                                                          \
        return ret;                                                                               \
    }

#define MODE_BINARY_CASE(OP, FN)                                                                  \
    case Op::OP::static_cuid: {                                                                   \
        static_assert(Op::FP::is_mode_binary<Op::OP>, "Op::" #OP " is not ModeBinary");           \
        using To = Constants::CTSC<Op::FP::ModeBinary>;                                           \
        const auto size { args.size() };                                                          \
        auto ret { FN(Utils::checked_static_cast<To>(expr->op.get())->mode, *args[size - 2],      \
                      *args[size - 1]) };                                                         \
        args.resize(size - 2);                                                                    \
        return ret;                                                                               \
    }

#define TERNARY_CASE(OP, FN)                                                                      \
    case Op::OP::static_cuid: {                                                                   \
        const auto size { args.size() };                                                          \
        auto ret { FN(*args[size - 3], *args[size - 2], *args[size - 1]) };                       \
        args.resize(size - 3);                                                                    \
        return ret;                                                                               \
    }

#define FLAT_CASE(OP, FN)                                                                         \
    case Op::OP::static_cuid: {                                                                   \
        static_assert(Op::is_flat<Op::OP>, "Op::" #OP " is not Flat");                            \
        using To = Constants::CTSC<Op::AbstractFlat>;                                             \
        const auto a_size { args.size() };                                                        \
        const auto n { Utils::checked_static_cast<To>(expr->op.get())->operands.size() };         \
        auto ret { FN(&(args.data()[a_size - n]), n) };                                           \
        args.resize(a_size - n);                                                                  \
        return ret;                                                                               \
    }

            // For brevity
            using Cmp = Mode::Compare;
            using Shft = Mode::Shift;

            // Switch on expr type
            switch (expr->op->cuid) {

                // This should never be hit
                default: {
                    throw Utils::Error::Unexpected::NotSupported(
                        WHOAMI_WITH_SOURCE
                        "Unknown expression op given to z3::dispatch_conversion."
                        "\nOp CUID: ",
                        expr->op->cuid);
                }

                // Unsupported ops
                case Op::Widen::static_cuid:           // fallthrough
                case Op::Union::static_cuid:           // fallthrough
                case Op::String::IsDigit::static_cuid: // fallthrough
                case Op::Intersection::static_cuid: {
                    throw Error::Backend::Unsupported(
                        WHOAMI_WITH_SOURCE
                        "Unknown expression op given to z3::dispatch_conversion."
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

                    // UIntBinary

                    UINT_BINARY_CASE(SignExt, Convert::signext);
                    UINT_BINARY_CASE(ZeroExt, Convert::zeroext);

                    // Binary

                    BINARY_CASE(Eq, Convert::eq);

                    BINARY_CASE(Neq, Convert::neq);

                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Signed | Cmp::Greater | Cmp::Eq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Signed | Cmp::Greater | Cmp::Neq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Signed | Cmp::Less | Cmp::Eq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Signed | Cmp::Less | Cmp::Neq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Unsigned | Cmp::Greater | Cmp::Eq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Unsigned | Cmp::Greater | Cmp::Neq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Unsigned | Cmp::Less | Cmp::Eq);
                    BINARY_TEMPLATE_CASE(Compare, Convert::compare,
                                         Cmp::Unsigned | Cmp::Less | Cmp::Neq);

                    BINARY_CASE(Sub, Convert::sub);

                    BINARY_TEMPLATE_CASE(Div, Convert::div, true);
                    BINARY_TEMPLATE_CASE(Div, Convert::div, false);

                    BINARY_CASE(Pow, Convert::pow);

                    BINARY_TEMPLATE_CASE(Mod, Convert::mod, true);
                    BINARY_TEMPLATE_CASE(Mod, Convert::mod, false);

                    // Logic / left is not supported a valid mode
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, Shft::Arithmetic | Shft::Left);
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, Shft::Arithmetic | Shft::Right);
                    BINARY_TEMPLATE_CASE(Shift, Convert::shift, Shft::Logical | Shft::Right);

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
                    const auto *const op { Utils::checked_static_cast<To>(expr->op.get()) };
                    auto ret { Convert::extract(op->high, op->low, *args.back()) };
                    args.pop_back();
                    return ret;
                }
                case Op::Literal::static_cuid: {
                    return Convert::literal(expr);
                }
                case Op::Symbol::static_cuid: {
                    return Convert::symbol(expr);
                }

                    /************************************************/
                    /*                  FP Trivial                  */
                    /************************************************/

                    // Unary

                    UNARY_CASE(FP::ToIEEEBV, Convert::FP::to_ieee_bv);
                    UNARY_CASE(FP::IsInf, Convert::FP::is_inf);
                    UNARY_CASE(FP::IsNaN, Convert::FP::is_nan);

                    // Mode Binary

                    MODE_BINARY_CASE(FP::Add, Convert::FP::add)
                    MODE_BINARY_CASE(FP::Sub, Convert::FP::sub)
                    MODE_BINARY_CASE(FP::Mul, Convert::FP::mul)
                    MODE_BINARY_CASE(FP::Div, Convert::FP::div)

                    // Ternary

                    TERNARY_CASE(FP::FP, Convert::FP::fp)

                    // Other

/** A local macro used for consistency */
#define TO_BV_BODY(TF)                                                                            \
    using ToBV = Constants::CTSC<Op::FP::ToBV<false>>;                                            \
    auto ret { Convert::FP::to_bv<TF>(Utils::checked_static_cast<ToBV>(expr->op.get())->mode,     \
                                      *args.back(), Expression::get_bit_length(expr)) };          \
    args.pop_back();                                                                              \
    return ret;

                case Op::FP::ToBV<true>::static_cuid: {
#ifdef DEBUG
                    using Bits = Constants::CTSC<Expression::Bits>;
                    Utils::affirm<Utils::Error::Unexpected::Type>(
                        dynamic_cast<Bits>(expr) != nullptr,
                        WHOAMI_WITH_SOURCE "FP::ToBV has no length");
#endif
                    TO_BV_BODY(true);
                }
                case Op::FP::ToBV<false>::static_cuid: {
#ifdef DEBUG
                    using Bits = Constants::CTSC<Expression::Bits>;
                    Utils::affirm<Utils::Error::Unexpected::Type>(
                        dynamic_cast<Bits>(expr) != nullptr,
                        WHOAMI_WITH_SOURCE "FP::ToBV has no length");
#endif
                    TO_BV_BODY(false);
                }

// Cleanup
#undef TO_BV_BODY

                    /************************************************/
                    /*                String Trivial                */
                    /************************************************/

                    // Unary

                    UNARY_CASE(String::FromInt, Convert::String::from_int);
                    UNARY_CASE(String::Unit, Convert::String::unit);

                    // Int Binary

                    UINT_BINARY_CASE(String::ToInt, Convert::String::to_int);
                    UINT_BINARY_CASE(String::Len, Convert::String::len);

                    // Binary

                    BINARY_CASE(String::Contains, Convert::String::contains);
                    BINARY_CASE(String::PrefixOf, Convert::String::prefix_of);
                    BINARY_CASE(String::SuffixOf, Convert::String::suffix_of);

                    // Ternary

                    TERNARY_CASE(String::Replace, Convert::String::replace);

                    // Other

                    TERNARY_CASE(String::SubString, Convert::String::substring)

                case Op::String::IndexOf::static_cuid: {
                    const auto size { args.size() };
#ifdef DEBUG
                    using To = Constants::CTSC<Expression::Bits>;
                    Utils::affirm<Utils::Error::Unexpected::Type>(
                        dynamic_cast<To>(expr) != nullptr,
                        WHOAMI_WITH_SOURCE "String::IndexOf has no length");
#endif
                    const auto bl { Expression::get_bit_length(expr) };
                    auto ret { Convert::String::index_of(*args[size - 3], *args[size - 2],
                                                         *args[size - 1], bl) };
                    args.resize(size - 2);
                    return ret;
                }
            }

                // Cleanup
#undef UNARY_CASE
#undef BINARY_DISPATCH
#undef BINARY_CASE
#undef BINARY_TEMPLATE_CASE
#undef UINT_BINARY_CASE
#undef MODE_BINARY_CASE
#undef TERNARY_CASE
#undef FLAT_CASE
        }

        /** Abstract a backend object into a claricpp expression */
        Expression::BasePtr abstract(const z3::expr &input) override final {
            (void) input;


            return { nullptr }; // TODO
        }

      private:
        /** An abbreviation for Utils::ThreadSafe::Mutable */
        template <typename T> using TSM = Utils::ThreadSafe::Mutable<T>;

        // Caches

        /** A helper function that tries to get an object from a cache
         *  Returns a pair; the first value is a boolean that stores if it was found
         *  The second value is the value that was found, or default constructed if not found
         *  Note that the second value is copied to ensure thread safety
         */
        template <typename Key, typename Value>
        static std::pair<bool, Value> get_from_cache(const TSM<std::map<Key, Value>> &tsm_cache,
                                                     const Key &key) {
            auto [cache, _] = tsm_cache.scoped_shared();
            if (const auto lookup { cache.find(key) }; lookup != cache.end()) {
                return { true, lookup->second };
            }
            return { false, {} };
        }

        /** is_true cache
         *  Map an expression hash to the result of is_true
         */
        inline static TSM<std::map<Hash::Hash, const bool>> is_true_cache {};

        /** is_false cache
         *  Map an expression hash to the result of is_false
         */
        inline static TSM<std::map<Hash::Hash, const bool>> is_false_cache {};
    };

} // namespace Backend::Z3

#endif

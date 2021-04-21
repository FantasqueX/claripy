/**
 * @file
 * @brief A 'flat' Op. I.e. An op that takes a vector<Expression::BasePtr> of inputs
 * For example, Add(a,b) can become A({a, b, c, d, ... }) if flattened
 */
#ifndef __OP_FLAT_HPP__
#define __OP_FLAT_HPP__

#include "base.hpp"


/** A macro used to define a trivial subclass of Flat
 *  Pass template arguments to Binary via variadic macro arguments
 *  If ConsiderSize, sizes will be compared as well when type checking if applicable
 *  An additional argument can be passed as the prefix to the desired debug name of the class
 *  For example, "FP::" may be desired for an FP op
 *  X can be anything, but must be different between different templates of the same class
 *  For example, Foo<int> must give a different X from Foo<bool>
 */
#define OP_FLAT_TRIVIAL_SUBCLASS(CLASS, CONSIDERSIZE, X, ...)                                     \
    class CLASS final : public ::Op::Flat<CONSIDERSIZE> {                                         \
        OP_FINAL_INIT(CLASS, (X), "" __VA_ARGS__);                                                \
                                                                                                  \
      private:                                                                                    \
        /** Private constructor */                                                                \
        explicit inline CLASS(const ::Hash::Hash &h, OpContainer &&input)                         \
            : Flat { h, static_cuid, std::forward<OpContainer>(input) } {}                        \
    };


namespace Op {

    /** An abstract flattened Op class
     *  Operands must all be of the same type and there must be at least 2
     *  These conditions are *not* validated
     */
    class AbstractFlat : public Base {
        OP_PURE_INIT(AbstractFlat);

      public:
        /** Operand container type */
        using OpContainer = std::vector<Expression::BasePtr>;

        /** Operands */
        const OpContainer operands;

        /** Return true if this class requires each operand be of the same size */
        virtual bool consider_size() const noexcept = 0;

        /** Add's the raw expression children of the expression to the given stack in reverse
         *  Warning: This does *not* give ownership, it transfers raw pointers
         */
        inline void add_reversed_children(Stack &s) const override final {
            for (auto i = operands.crbegin(); i != operands.crend(); ++i) {
                s.emplace(i->get());
            }
        }

      protected:
        /** Protected constructor
         *  Verify that all operands are of the same type and that there are at least 2
         */
        explicit inline AbstractFlat(const Hash::Hash &h, const CUID::CUID &cuid_,
                                     OpContainer &&input)
            : Base { h, cuid_ }, operands { input } {}
    };

    /** Default virtual destructor */
    AbstractFlat::~AbstractFlat() noexcept = default;

    /** A flattened Op class
     *  Operands must all be of the same type and there must be at least 2
     *  Both of these conditions are verified during construction
     *  If ConsiderSize, sizes will be compared as well when type checking if applicable
     */
    template <bool ConsiderSize> class Flat : public AbstractFlat {
        OP_PURE_INIT(Flat);

      public:
        /** Return ConsiderSize */
        inline bool consider_size() const noexcept override final { return ConsiderSize; }

      protected:
        /** Protected constructor
         *  Verify that all operands are of the same type and that there are at least 2
         */
        explicit inline Flat(const Hash::Hash &h, const CUID::CUID &cuid_, OpContainer &&input)
            : AbstractFlat { h, cuid_, std::move(input) } {
            namespace Err = Error::Expression;

            // Operands size
            Utils::affirm<Err::Size>(operands.size() >= 2, WHOAMI_WITH_SOURCE
                                     "constructor requires at least two arguments");

            // Verify all inputs are the same type
            for (const auto &i : operands) {
                if constexpr (ConsiderSize) {
                    Utils::affirm<Err::Type>(Expression::are_same_type<true>(operands[0], i),
                                             WHOAMI_WITH_SOURCE "operands differ by size or type");
                }
                else {
                    Utils::affirm<Err::Type>(Expression::are_same_type<false>(operands[0], i),
                                             WHOAMI_WITH_SOURCE "operands differ by size");
                }
            }
        }
    };

    /** Default virtual destructor */
    template <bool B> Flat<B>::~Flat() noexcept = default;

    /** Returns true if T is flat */
    template <typename T>
    UTILS_ICCBOOL is_flat { Utils::is_ancestor<Flat<true>, T> ||
                            Utils::is_ancestor<Flat<false>, T> };

} // namespace Op

#endif

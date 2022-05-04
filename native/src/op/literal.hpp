/**
 * @file
 * @brief The OP representing a Literal
 */
#ifndef R_SRC_OP_LITERAL_HPP_
#define R_SRC_OP_LITERAL_HPP_

#include "base.hpp"
#include "constants.hpp"


namespace Op {

    // Forward declare
    inline std::ostream &operator<<(std::ostream &, const PrimVar &);

    /** The op class Literal */
    class Literal final : public Base {
        OP_FINAL_INIT(Literal, "");

      public:
        /** Representation */
        const PrimVar value;

        /** repr */
        inline void repr_stream(std::ostream &out) const final {
            out << R"|({ "name":")|" << op_name() << R"|(", "value":)|" << value << " }";
        }

#define M_CASE(TYPE, EXPR)                                                                         \
    case (Util::Type::index<decltype(value), TYPE>): {                                             \
        const auto &got { std::get<TYPE>(value) };                                                 \
        return EXPR;                                                                               \
    }

        /** Appends the expr children of the expr to the given vector
         *  Note: This should only be used when returning children to python
         */
        inline std::vector<ArgVar> python_children() const final {
            static_assert(std::variant_size_v<decltype(value)> == 10);
            switch (value.index()) {
                M_CASE(bool, { got });
                M_CASE(std::string, { got });
                M_CASE(float, { got });
                M_CASE(double, { got });
                M_CASE(PyObj::VS::Ptr, { got });
                M_CASE(uint8_t, { got });
                M_CASE(uint16_t, { got });
                M_CASE(uint32_t, { got });
                M_CASE(U64, { got });
                M_CASE(BigInt, { got });
                default:
                    UTIL_THROW(Util::Err::Unknown, "Broken variant detected");
            }
        }

        /** Return true iff the op is a leaf op */
        inline bool is_leaf() const noexcept final {
            return true;
        }

      private:
#define M_P_CTOR(TYPE)                                                                             \
    static_assert(std::is_const_v<TYPE> == std::is_fundamental_v<TYPE>,                            \
                  "Fundamental types should be const, non-fundamental should not");                \
    /** Private constructor;  constructor should not be given shared pointers to nulllptr */       \
    explicit inline Literal(const Hash::Hash &h, TYPE &&data)                                      \
        : Base { h, static_cuid }, value { std::move(data) }

        // The different private constructors we allow
        // There should be one for each variant type
        M_P_CTOR(const bool) {};
        M_P_CTOR(std::string) {};
        M_P_CTOR(const float) {};
        M_P_CTOR(const double) {};
        M_P_CTOR(PyObj::VS::Ptr) {
            UTIL_ASSERT_NOT_NULL_DEBUG(std::get<PyObj::VS::Ptr>(value));
        }
        // BV constructors
        M_P_CTOR(const uint8_t) {};
        M_P_CTOR(const uint16_t) {};
        M_P_CTOR(const uint32_t) {};
        M_P_CTOR(const U64) {};
        M_P_CTOR(BigInt) {};
#undef M_P_CTOR

        /** Adds the raw expr children of the expr to the given stack in reverse
         *  Warning: This does *not* give ownership, it transfers raw pointers
         */
        inline void unsafe_add_reversed_children(Stack &) const noexcept final {}
    };

    /** Ostream operator for PrimVar */
    inline std::ostream &operator<<(std::ostream &o, const PrimVar &value) {
        switch (value.index()) {
            M_CASE(bool, o << std::boolalpha << got);
            M_CASE(std::string, o << std::quoted(got));
            M_CASE(float, o << got);
            M_CASE(double, o << got);
            M_CASE(PyObj::VS::Ptr, o << got);
            M_CASE(uint8_t, o << static_cast<uint16_t>(got));
            M_CASE(uint16_t, o << got);
            M_CASE(uint32_t, o << got);
            M_CASE(U64, o << got);
            M_CASE(BigInt, o << got);
            // Bad variant
            default:
                UTIL_THROW(Util::Err::Unknown, "unknown type in variant");
        }
    }
#undef M_CASE

} // namespace Op

#endif

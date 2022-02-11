/**
 * @file
 * @brief This file defines the Op class FP::From2sComplementBV
 */
#ifndef R_OP_FP_FROM2SCOMPLEMENTBV_HPP_
#define R_OP_FP_FROM2SCOMPLEMENTBV_HPP_

#include "../../mode.hpp"
#include "../base.hpp"


namespace Op::FP {

    /** The op class: Which converts a 2s complement BV into an FP */
    template <bool Signed> class From2sComplementBV final : public Base {
        OP_FINAL_INIT(From2sComplementBV, "FP::", Signed);

      public:
        /** The FP mode */
        const Mode::FP::Rounding mode;
        /** The expr to convert */
        const Expr::BasePtr bv;
        /** The fp width to convert to */
        const Mode::FP::Width width;

        /** Python's repr function (outputs json) */
        inline void repr(std::ostream &out) const final {
            out << R"|({ "name":")|" << op_name() << R"|(", "signed":)|" << std::boolalpha << Signed
                << R"|(, "rounding mode":)|" << Util::to_underlying(mode) << R"|(, "bv":)|";
            bv->repr(out);
            out << R"|(, "width":)|" << width << " }";
        }

        /** Adds the raw expr children of the expr to the given stack in reverse
         *  Warning: This does *not* give ownership, it transfers raw pointers
         */
        inline void unsafe_add_reversed_children(Stack &s) const final { s.emplace(bv.get()); }

        /** Appends the expr children of the expr to the given vector
         *  Note: This should only be used when returning children to python
         */
        inline void python_children(std::vector<ArgVar> &v) const final {
            v.emplace_back(mode);
            v.emplace_back(bv);
            v.emplace_back(width);
        }

      private:
        /** Protected constructor
         *  Ensure that bv is a BV
         */
        explicit inline From2sComplementBV(const Hash::Hash &h, const Mode::FP::Rounding m,
                                           const Expr::BasePtr &b, const Mode::FP::Width w)
            : Base { h, static_cuid }, mode { m }, bv { b }, width { w } {
            UTIL_ASSERT(Error::Expr::Type, CUID::is_t<Expr::BV>(bv),
                        "Operand fp must be an Expr::BV");
        }
    };

} // namespace Op::FP

#endif

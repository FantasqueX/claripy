/**
 * @file
 * @brief This file defines the Op class FP::FromNot2sComplementBV
 */
#ifndef R_OP_FP_FROMNOT2SCOMPLEMENTBV_HPP_
#define R_OP_FP_FROMNOT2SCOMPLEMENTBV_HPP_

#include "../../mode.hpp"
#include "../base.hpp"


namespace Op::FP {

    /** The op class which converts a non-2s-complement BV into an FP */
    class FromNot2sComplementBV final : public Base {
        OP_FINAL_INIT(FromNot2sComplementBV, 0, "FP::");

      public:
        /** The expr to convert */
        const Expr::BasePtr bv;
        /** The fp width to convert to */
        const Mode::FP::Width width;

        /** Python's repr function (outputs json) */
        inline void repr(std::ostream &out) const final {
            out << R"|({ "name":")|" << op_name() << R"|(, "bv":)|";
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
            v.emplace_back(bv);
            v.emplace_back(width);
        }

      private:
        /** Protected constructor
         *  Ensure that bv is a BV
         */
        explicit inline FromNot2sComplementBV(const Hash::Hash &h, const Expr::BasePtr &b,
                                              const Mode::FP::Width w)
            : Base { h, static_cuid }, bv { b }, width { w } {}
    };

} // namespace Op::FP

#endif

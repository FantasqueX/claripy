/**
 * @file
 * @brief A binary Op; takes two inputs of the same type
 * For example: Concat(Str1, Str2)
 */
#ifndef R_OP_OSTREAM_HPP_
#define R_OP_OSTREAM_HPP_

#include "base.hpp"


namespace Op {

    /** Overload the << stream operator to use append_repr */
    inline std::ostream &operator<<(std::ostream &os, const Op::Base *p) {
        p->append_repr(os);
        return os;
    }

    /** Overload the << stream operator to use append_repr */
    inline std::ostream &operator<<(std::ostream &os, const BasePtr &p) {
        os << p.get();
        return os;
    }

} // namespace Op

#endif

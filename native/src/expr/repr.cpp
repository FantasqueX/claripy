/** @file */
#include "repr.hpp"

#include "bits.hpp"

#include "../op.hpp"

#include <sstream>


void Expr::repr(const Expr::RawPtr e, std::ostream &out, const bool verbose) {
    Util::affirm<Util::Err::NotSupported>(!verbose, "verbose repr not yet implemented");
    UTIL_AFFIRM_NOT_NULL_DEBUG(e);
    UTIL_AFFIRM_NOT_NULL_DEBUG(e->op); // Sanity check
    // Null check
    if (e == nullptr) {
        Util::Log::warning(WHOAMI "called on nullptr");
        out << R"|({ "ptr":"nullptr" })|";
        return;
    }
    // Normal operation
    out << R"|({ "type":")|" << e->type_name() << R"|(", "symbolic":)|" << std::boolalpha
        << e->symbolic << ", ";
    if (dynamic_cast<CTSC<Expr::Bits>>(e) != nullptr) {
        out << R"|("bit_length":)|" << Expr::get_bit_length(e) << ", ";
    }
    out << R"|("op":)|";
    e->op->repr(out, verbose);
    out << " }";
}

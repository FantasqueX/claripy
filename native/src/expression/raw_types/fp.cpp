/** @file */
#include "fp.hpp"

#include "../../utils.hpp"


// Define required AST functions
AST_RAWTYPES_DEFINE_AST_SUBBITS_ID_FUNCTIONS(FP)


// For brevity
using namespace AST;


/** @todo */
RawTypes::FP::FP(const Hash h, const Op::Operation o) : RawTypes::Bits(h, o, 0) {}

/** @todo make this actually work */
Hash RawTypes::FP::hash(const Op::Operation o) {
    return Hash(FP::static_class_id) * (1 + Hash(o));
}

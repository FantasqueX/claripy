/**
 * @file
 * \ingroup unittest
 */
#include "testlib.hpp"

#include "../dcast.hpp"


/** Verify that the to_bv<Signed> function compiles and can be run without issue */
template <bool Signed> void to_bv_b() {

    // Create distinct inputs
    const Mode::FP::Rounding mode { Mode::FP::Rounding::TowardsZero };
    const auto fp { Create::literal(0.) };
    const UInt bit_length { 16 };

    // Test
    const auto exp { Create::FP::to_bv<Signed>(mode, fp, bit_length) };

    // Pointer checks
    UNITTEST_ASSERT(fp.use_count() == 2);
    UNITTEST_ASSERT(exp->op.use_count() == 1);

    // Type check
    const auto op_down { dcast<Op::FP::ToBV<Signed>>(exp->op) };
    const auto exp_down { dcast<Expr::BV>(exp) };

    // Contains check
    UNITTEST_ASSERT(op_down->fp == fp);

    // Size check
    UNITTEST_ASSERT(exp_down->bit_length == bit_length);
}

/** Verify that the to_bv function compiles and can be run without issue */
void to_bv() {
    to_bv_b<true>();
    to_bv_b<false>();
}

// Define the test
UNITTEST_DEFINE_MAIN_TEST(to_bv)

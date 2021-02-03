/**
 * @file
 * \ingroup unittest
 */
#include "hash.hpp"

#include "testlib.hpp"

#include <set>


/** A hashed struct */
struct A : public Hash::Hashed {
    /** Constructor */
    A(const Hash::Hash h) : Hashed { h } {}
};


/** Verify that hashing of multiple objects works */
void hash() {
    std::set<Hash::Hash> hashes;

    // Values to use
    const auto a0 { std::make_shared<A>(0_ui) };
    const auto a1 { std::make_shared<A>(1_ui) };
    const std::string hi_s { "hi" };
    const Constants::CCSC hi_c { "hi" };
    const std::vector<decltype(a0)> vec1 { a0, a1 };
    const std::vector<decltype(a0)> vec2 { a1, a0 };
    const Constants::UInt uz { 0_ui };
    const Constants::Int z { 0_i };

    // Hash multiple things

    hashes.insert(Hash::hash(a0, hi_s, z)); // 1
    hashes.insert(Hash::hash(a0, hi_s, z)); // 1

    hashes.insert(Hash::hash(a0, hi_s, uz)); // 2

    hashes.insert(Hash::hash(vec1)); // 3

    hashes.insert(Hash::hash(vec2)); // 4

    hashes.insert(Hash::hash(hi_s, hi_c)); // 5
    hashes.insert(Hash::hash(hi_s, hi_c)); // 5

    hashes.insert(Hash::hash(hi_c, hi_s)); // 6
    hashes.insert(Hash::hash(hi_c, hi_s)); // 6

    hashes.insert(Hash::hash(a0)); // 7

    hashes.insert(Hash::hash(a1)); // 8

    // Verify uniqueness
    UNITTEST_ASSERT(hashes.size() == 8)
}

// Define the test
UNITTEST_DEFINE_MAIN_TEST(hash)

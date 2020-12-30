/**
 * @file
 * @brief This file enables easy construction of ASTs with a given op
 */
#ifndef __TESTS_UNIT_TESTLIB_TESTLIB_CONSTRUCTAST_HPP__
#define __TESTS_UNIT_TESTLIB_TESTLIB_CONSTRUCTAST_HPP__

#include "ast.hpp"
#include "op.hpp"


namespace UnitTest::TestLib {

    /** Construct a T with Op op
     *  Op defaulted to Or
     */
    template <typename T> T construct_ast(Op::Operation o = Op::Operation::Or) {
        std::set<AST::BackendID> s;
        return AST::factory<T>(std::move(s), std::move(o));
    }

    /** Construct a T with Op op
     *  Passes args through to factory, which consumes them
     *  Op defaulted to Or
     */
    template <typename T, typename... Args> T construct_ast(Args &&...args) {
        std::set<AST::BackendID> s;
        Op::Operation o = Op::Operation::Or;
        return AST::factory<T>(std::move(s), std::move(o), std::forward<Args>(args)...);
    }

    /** Construct a T with Op op
     *  Passes args through to factory, which consumes them
     */
    template <typename T, typename... Args> T construct_ast(Op::Operation o, Args &&...args) {
        std::set<AST::BackendID> s;
        return AST::factory<T>(std::move(s), std::move(o), std::forward<Args>(args)...);
    }

} // namespace UnitTest::TestLib


#endif

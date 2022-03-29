/**
 * @file
 * \ingroup testlib
 */
#include "test_func.hpp"

#include "error.hpp"
#include "private/verify.hpp"
#include "util.hpp"

#include <exception>


/** Catch and print an error before exiting */
#define CATCH_ERROR(ERROR)                                                                         \
    catch (const ERROR &e) {                                                                       \
        UNITTEST_ERR(e.backtrace(), "\n", #ERROR ": ", e.raw_what());                              \
    }


int UnitTest::TestLib::test_func(TestFN &f) {
    // Notify verify that test_func has started running
    Private::verify();
    // Test f
    try {
        f();
        Util::Log::info("Test case passed!");
        return EXIT_SUCCESS;
    }
    // UnitTest error
    catch (Error &e) {
        Util::Log::error(e.backtrace(), "\n", e.raw_what());
        return EXIT_FAILURE;
    }
    // If there was a different error, note so and fail
    CATCH_ERROR(Util::Err::Internal)
    CATCH_ERROR(Util::Err::Python::Base)
    CATCH_ERROR(Util::Err::Claricpp)
    catch (std::exception &e) {
        UNITTEST_ERR("std::exception: ", e.what());
    }
}

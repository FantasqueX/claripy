# Requires: SIMPLE_TEST_DIR set to the desired test directory

# Error checking
if (NOT DEFINED SIMPLE_TEST_DIR)
	message(FATAL_ERROR "SimpleTest requires the SIMPLE_TEST_DIR variable be defined."
			"This must be defined before including the SimpleTest.cmake file"
	)
endif()

# Inform user about static analysis
if(CLANG_TIDY OR LWYU)
	message("Turning off some static analysis for test cases.")
endif()

# Create a function to add test cases
# This file generates a test case from a cpp file: ./<FNAME>.cpp
# <FNAME>.cpp must contain a function named <FNAME> of type int();
# This is the function that will be tested, it's return value will be the test return code
# Additional required cpp files can be passed in as extra arguments
# Test cases must have a local link, src, to /claripy/native/src
function(simple_test FUNC_NAME)

	# Usage check
	if ("${FUNC_NAME}" MATCHES "[/\.]")
		message(FATAL_ERROR
			"simple_test does not allow '.' or '/' in its input."
			"\tIt was given: ${FUNC_NAME}"
		)
	endif()

	# Disable some static analysis for test cases
	# We don't need it on test cases and it causes some issues
	# Note: By default unset only unsets within local scope
	if(LWYU)
		unset(CMAKE_LINK_WHAT_YOU_USE)
		set(LWYU OFF)
	endif()
	if(CLANG_TIDY)
		set(OVERRIDE_CHECKS
			"-readability-convert-member-functions-to-static"
			"-cppcoreguidelines-avoid-magic-numbers"
			"-readability-magic-numbers"
		)
		string(REPLACE ";" "," OVERRIDE_CHECKS "${OVERRIDE_CHECKS}")
		set(OVERRIDE_CHECKS "-checks=${OVERRIDE_CHECKS}")
		list(APPEND CMAKE_CXX_CLANG_TIDY "${OVERRIDE_CHECKS}")
		list(APPEND CMAKE_C_CLANG_TIDY "${OVERRIDE_CHECKS}")
	endif()

	# Determine the test prefix from the path
	string(LENGTH "${SIMPLE_TEST_DIR}/" ST_LEN)
	if(NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL SIMPLE_TEST_DIR)
		string(SUBSTRING "${CMAKE_CURRENT_SOURCE_DIR}" "${ST_LEN}" -1 SUBPATH)
	else()
		set(SUBPATH "")
	endif()
	string(REPLACE "/" "-" TEST_PREFIX "${SUBPATH}")
	string(LENGTH "${TEST_PREFIX}" TEST_PREFIX_LEN)
	if(NOT "${TEST_PREFIX_LEN}" EQUAL 0)
		set(TEST_PREFIX "${TEST_PREFIX}-")
	endif()

	# Create the test
	set(TEST_NAME "${TEST_PREFIX}${FUNC_NAME}")
	set(BINARY "${TEST_NAME}.test")
	add_executable("${BINARY}" "${FUNC_NAME}.cpp" ${ARGN})

	## Add the test
	message(STATUS "\t${TEST_NAME}")
	add_test("${TEST_NAME}" "./${BINARY}")

	# Add compile options
	target_compile_definitions("${BINARY}" PRIVATE "_GLIBCXX_ASSERTIONS")
	target_compile_options("${BINARY}" PRIVATE
		"-O0"
		"-g"
		"-fasynchronous-unwind-tables"
		"-grecord-gcc-switches"
	)

	# For debugging
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		target_link_options("${BINARY}" PUBLIC
			"-rdynamic"
		)
		target_link_libraries("${CLARICPP}" PRIVATE dl)
	endif()

	# Add memcheck test
	if(RUN_MEMCHECK_TESTS)
		set(MEMCHECK
			"${CMAKE_MEMORYCHECK_COMMAND}"
			"${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}"
		)
		separate_arguments(MEMCHECK)
		add_test("${TEST_NAME}.memcheck" ${MEMCHECK} "./${BINARY}")
	endif()

	# Link libraries and headers
	target_include_directories("${BINARY}"
		SYSTEM BEFORE
		PRIVATE "${Z3_INCLUDE_DIR}"
		PRIVATE ${Boost_INCLUDE_DIRS}
	)
	target_include_directories("${BINARY}"
		PRIVATE "${CLARICPP_SRC}"
		PRIVATE "${TESTLIB_SRC}"
	)
	# Link the test
	target_link_libraries("${BINARY}"
		PRIVATE "${GMP_LIBRARIES}" # Boost multiprecision backend
		PRIVATE "${Z3_LINK_TARGET}"
		PRIVATE "${CLARICPP}"
		PRIVATE "${TESTLIB}"
	)

endfunction()


cmake_minimum_required(VERSION 3.15)

include(FetchContent)

FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    GIT_TAG 2.3.6
)
FetchContent_MakeAvailable(doctest)

add_executable(minimal_test
    main.cpp
    test_binomial.cpp
    test_factorial.cpp
)

target_link_libraries(minimal_test minimalBinomial doctest)
target_compile_features(minimal_test PRIVATE cxx_std_17)
target_compile_definitions(minimal_test PRIVATE
    DOCTEST_CONFIG_SUPER_FAST_ASSERTS # uses a function call for asserts to speed up compilation
    DOCTEST_CONFIG_USE_STD_HEADERS # prevent non-standard overloading of std declarations
    DOCTEST_CONFIG_INCLUDE_TYPE_TRAITS # enable doctest::Approx() to take any argument explicitly convertible to a double
    DOCTEST_CONFIG_NO_POSIX_SIGNALS
    DOCTEST_CONFIG_NO_EXCEPTIONS
)

if (NOT MSVC)
    message("I am here v0")

    target_compile_options(doctest
    INTERFACE
        -fno-omit-frame-pointer
        -Wall
        -Wno-comment # Needed for doxygen
    )
endif()

message("I am here v1 " ${CMAKE_CXX_COMPILER_ID})


# Place the test executable at the project binary directory instead of in the nested subfolder
set_target_properties(minimal_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)
message("I am here v2")

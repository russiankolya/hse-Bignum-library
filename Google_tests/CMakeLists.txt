# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'BigintTest.cpp BigfloatTest.cpp' are source files with tests
add_executable(Google_Tests_run BigintTest.cpp BigfloatTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run Bignum)
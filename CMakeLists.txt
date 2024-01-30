cmake_minimum_required(VERSION 3.26)
project(hse_Bignum_library)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hse_Bignum_library main.cpp)


add_subdirectory(Bignum)

target_link_libraries(hse_Bignum_library PUBLIC Bignum)

target_include_directories(hse_Bignum_library PUBLIC
        "${PROJECT_BINARY_DIR}"
)

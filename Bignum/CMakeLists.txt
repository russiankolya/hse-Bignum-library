add_library(Bignum Bignum.cpp)

target_include_directories(Bignum
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
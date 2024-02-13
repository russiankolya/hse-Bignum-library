add_library(Bignum Bigint.cpp Bigfloat.cpp)

target_include_directories(Bignum
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)
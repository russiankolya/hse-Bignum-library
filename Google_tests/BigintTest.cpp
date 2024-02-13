#include "gtest/gtest.h"
#include "Bigint.h"

TEST(BigintTest, testDefaultConstructor) {
    Bigint bigint;
    ASSERT_EQ("0", bigint.get_value());
    ASSERT_FALSE(bigint.is_negative());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
#include "gtest/gtest.h"
#include "Bigfloat.h"

TEST(BigfloatTest, testDefaultConstructor) {
    Bigfloat bigfloat;
    ASSERT_EQ(Bigint(0), bigfloat.get_value());
    ASSERT_EQ(6, bigfloat.get_precision());
}
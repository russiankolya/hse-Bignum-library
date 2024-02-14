#include "gtest/gtest.h"
#include "Bigint.h"

TEST(BigintTest, testDefaultConstructor) {
    Bigint bigint;
    ASSERT_EQ("0", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}

TEST(BigintTest, testIntConstructor1) {
    Bigint bigint(123);
    ASSERT_EQ("123", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}

TEST(BigintTest, testIntConstructor2) {
    Bigint bigint(-123);
    ASSERT_EQ("123", bigint.value());
    ASSERT_TRUE(bigint.is_negative());
}

TEST(BigintTest, testIntConstructor3) {
    Bigint bigint(-0);
    ASSERT_EQ("0", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}

TEST(BigintTest, testStringConstructor1) {
    Bigint bigint("123");
    ASSERT_EQ("123", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}

TEST(BigintTest, testStringConstructor2) {
    Bigint bigint("-123");
    ASSERT_EQ("123", bigint.value());
    ASSERT_TRUE(bigint.is_negative());
}

TEST(BigintTest, testStringConstructor3) {
    Bigint bigint("-0");
    ASSERT_EQ("0", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}

TEST(BigintTest, testToString1) {
    Bigint bigint(123);
    ASSERT_EQ("123", bigint.to_string());
}

TEST(BigintTest, testToString2) {
    Bigint bigint("-123");
    ASSERT_EQ("-123", bigint.to_string());
}

TEST(BigintTest, testToString3) {
    Bigint bigint("-0");
    ASSERT_EQ("0", bigint.to_string());
}

TEST(BigintTest, testUnaryMinus1) {
    Bigint bigint(123);
    ASSERT_EQ("-123", (-bigint).to_string());
}

TEST(BigintTest, testUnaryMinus2) {
    Bigint bigint(-123);
    ASSERT_EQ("123", (-bigint).to_string());
}

TEST(BigintTest, testUnaryMinus3) {
    Bigint bigint(0);
    ASSERT_EQ("0", (-bigint).to_string());
}

TEST(BigintTest, testUnaryMinus4) {
    Bigint bigint("-0");
    ASSERT_EQ("0", (-bigint).to_string());
}
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

TEST(BigintTest, testAdd1) {
    std::string value1 = "123";
    std::string value2 = "456";
    ASSERT_EQ("579", Bigint::add(value1, value2));
    ASSERT_EQ("579", Bigint::add(value2, value1));
}

TEST(BigintTest, testAdd2) {
    std::string value1 = "0";
    std::string value2 = "456";
    ASSERT_EQ("456", Bigint::add(value1, value2));
    ASSERT_EQ("456", Bigint::add(value2, value1));
}

TEST(BigintTest, testAdd3) {
    std::string value1 = "100000";
    std::string value2 = "1";
    ASSERT_EQ("100001", Bigint::add(value1, value2));
    ASSERT_EQ("100001", Bigint::add(value2, value1));
}

TEST(BigintTest, testAdd4) {
    std::string value1 = "574805794185792837589295340325";
    std::string value2 = "483298573428923045";
    ASSERT_EQ("574805794186276136162724263370", Bigint::add(value1, value2));
    ASSERT_EQ("574805794186276136162724263370", Bigint::add(value2, value1));
}

TEST(BigintTest, testSubtract1) {
    std::string value1 = "456";
    std::string value2 = "123";
    ASSERT_EQ("333", Bigint::subtract(value1, value2));
}

TEST(BigintTest, testSubtract2) {
    std::string value1 = "456";
    std::string value2 = "456";
    ASSERT_EQ("0", Bigint::subtract(value1, value2));
}

TEST(BigintTest, testSubtract3) {
    std::string value1 = "100000";
    std::string value2 = "1";
    ASSERT_EQ("99999", Bigint::subtract(value1, value2));
}

TEST(BigintTest, testSubtract4) {
    std::string value1 = "574805794186276136162724263370";
    std::string value2 = "574805794185792837589295340325";
    ASSERT_EQ("483298573428923045", Bigint::subtract(value1, value2));
}
#include "gtest/gtest.h"
#include "Bigint.h"


// Default constructor test
TEST(BigintTest, testDefaultConstructor) {
    Bigint bigint;
    ASSERT_EQ("0", bigint.value());
    ASSERT_FALSE(bigint.is_negative());
}



// Int constructor tests
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



// String constructor tests
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



// to_string tests
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



// Unary minus tests
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



// String addition tests
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



// String subtraction tests
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



// Addition operator tests
TEST(BigintTest, testAddition1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_EQ("579", (bigint1 + bigint2).to_string());
    ASSERT_EQ("579", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAddition2) {
    Bigint bigint1(-123);
    Bigint bigint2(-456);
    ASSERT_EQ("-579", (bigint1 + bigint2).to_string());
    ASSERT_EQ("-579", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAddition3) {
    Bigint bigint1(-123);
    Bigint bigint2(456);
    ASSERT_EQ("333", (bigint1 + bigint2).to_string());
    ASSERT_EQ("333", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAddition4) {
    Bigint bigint1(123);
    Bigint bigint2(-456);
    ASSERT_EQ("-333", (bigint1 + bigint2).to_string());
    ASSERT_EQ("-333", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAddition5) {
    Bigint bigint1(0);
    Bigint bigint2(456);
    ASSERT_EQ("456", (bigint1 + bigint2).to_string());
    ASSERT_EQ("456", (bigint2 + bigint1).to_string());
}



// Subtraction operator tests
TEST(BigintTest, testSubtraction1) {
    Bigint bigint1(456);
    Bigint bigint2(123);
    ASSERT_EQ("333", (bigint1 - bigint2).to_string());
}



// Test equality operator
TEST(BigintTest, testEquality1) {
    Bigint bigint1(123);
    Bigint bigint2(123);
    ASSERT_TRUE(bigint1 == bigint2);
}

TEST(BigintTest, testEquality2) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_FALSE(bigint1 == bigint2);
}



// Test inequality operator
TEST(BigintTest, testInequality1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_TRUE(bigint1 != bigint2);
    ASSERT_TRUE(bigint2 != bigint1);
    ASSERT_FALSE(bigint1 != bigint1);
}



// Less than operator tests
TEST(BigintTest, testLessThan1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_TRUE(bigint1 < bigint2);
    ASSERT_FALSE(bigint2 < bigint1);
}

TEST(BigintTest, testLessThan2) {
    Bigint bigint1(3124132);
    Bigint bigint2(3124132);
    ASSERT_FALSE(bigint1 < bigint2);
    ASSERT_FALSE(bigint2 < bigint1);
}

TEST(BigintTest, testLessThan3) {
    Bigint bigint1(-123);
    Bigint bigint2(456);
    ASSERT_TRUE(bigint1 < bigint2);
    ASSERT_FALSE(bigint2 < bigint1);
}

TEST(BigintTest, testLessThan4) {
    Bigint bigint1(-123);
    Bigint bigint2(-456);
    ASSERT_FALSE(bigint1 < bigint2);
    ASSERT_TRUE(bigint2 < bigint1);
}

TEST(BigintTest, testLessThan5) {
    Bigint bigint1(123);
    Bigint bigint2(-456);
    ASSERT_FALSE(bigint1 < bigint2);
    ASSERT_TRUE(bigint2 < bigint1);
}

TEST(BigintTest, testLessThan6) {
    Bigint bigint1(0);
    Bigint bigint2(1);
    ASSERT_TRUE(bigint1 < bigint2);
    ASSERT_FALSE(bigint2 < bigint1);
}



// Greater than operator tests
TEST(BigintTest, testGreaterThan1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_FALSE(bigint1 > bigint2);
    ASSERT_TRUE(bigint2 > bigint1);
    ASSERT_FALSE(bigint1 > bigint1);
}



// Less than or equal operator tests
TEST(BigintTest, testLessThanOrEqual1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_TRUE(bigint1 <= bigint2);
    ASSERT_FALSE(bigint2 <= bigint1);
    ASSERT_TRUE(bigint1 <= bigint1);
}



// Greater than or equal operator tests
TEST(BigintTest, testGreaterThanOrEqual1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_FALSE(bigint1 >= bigint2);
    ASSERT_TRUE(bigint2 >= bigint1);
    ASSERT_TRUE(bigint1 >= bigint1);
}

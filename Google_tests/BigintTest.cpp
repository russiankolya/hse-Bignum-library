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



// Addition operator tests
TEST(BigintTest, testAdditionOperator1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_EQ("579", (bigint1 + bigint2).to_string());
    ASSERT_EQ("579", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAdditionOperator2) {
    Bigint bigint1(-123);
    Bigint bigint2(-456);
    ASSERT_EQ("-579", (bigint1 + bigint2).to_string());
    ASSERT_EQ("-579", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAdditionOperator3) {
    Bigint bigint1(-123);
    Bigint bigint2(456);
    ASSERT_EQ("333", (bigint1 + bigint2).to_string());
    ASSERT_EQ("333", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAdditionOperator4) {
    Bigint bigint1(123);
    Bigint bigint2(-456);
    ASSERT_EQ("-333", (bigint1 + bigint2).to_string());
    ASSERT_EQ("-333", (bigint2 + bigint1).to_string());
}

TEST(BigintTest, testAdditionOperator5) {
    Bigint bigint1(0);
    Bigint bigint2(456);
    ASSERT_EQ("456", (bigint1 + bigint2).to_string());
    ASSERT_EQ("456", (bigint2 + bigint1).to_string());
}



// Subtraction operator tests
TEST(BigintTest, testSubtractionOperator1) {
    Bigint bigint1(456);
    Bigint bigint2(123);
    ASSERT_EQ("333", (bigint1 - bigint2).to_string());
}



// Multiplication operator tests
TEST(BigintTest, testMultiplicationOperator1) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_EQ("56088", (bigint1 * bigint2).to_string());
    ASSERT_EQ("56088", (bigint2 * bigint1).to_string());
}

TEST(BigintTest, testMultiplicationOperator2) {
    Bigint bigint1(-12345);
    Bigint bigint2(45678);
    ASSERT_EQ("-563894910", (bigint1 * bigint2).to_string());
    ASSERT_EQ("-563894910", (bigint2 * bigint1).to_string());
}

TEST(BigintTest, testMultiplicationOperator3) {
    Bigint bigint1(-12345);
    Bigint bigint2(-45678);
    ASSERT_EQ("563894910", (bigint1 * bigint2).to_string());
    ASSERT_EQ("563894910", (bigint2 * bigint1).to_string());
}

TEST(BigintTest, testMultiplicationOperator4) {
    Bigint bigint1(12345);
    Bigint bigint2(0);
    ASSERT_EQ("0", (bigint1 * bigint2).to_string());
    ASSERT_EQ("0", (bigint2 * bigint1).to_string());
}

TEST(BigintTest, testMultiplicationOperator5) {
    Bigint bigint1(12345);
    Bigint bigint2(1);
    ASSERT_EQ("12345", (bigint1 * bigint2).to_string());
    ASSERT_EQ("12345", (bigint2 * bigint1).to_string());
}

TEST(BigintTest, testMultiplicationOperator6) {
    Bigint bigint1("-57934567923704");
    Bigint bigint2("83475389758497223");
    ASSERT_EQ("-4836110637921322606690359873992", (bigint1 * bigint2).to_string());
    ASSERT_EQ("-4836110637921322606690359873992", (bigint2 * bigint1).to_string());
}



// Division operator tests
TEST(BigintTest, testDivisionOperator1) {
    Bigint bigint1(456);
    Bigint bigint2(123);
    ASSERT_EQ("3", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator2) {
    Bigint bigint1(123);
    Bigint bigint2(456);
    ASSERT_EQ("0", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator3) {
    Bigint bigint1(123);
    Bigint bigint2(123);
    ASSERT_EQ("1", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator4) {
    Bigint bigint1(123);
    Bigint bigint2(1);
    ASSERT_EQ("123", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator5) {
    Bigint bigint1(123);
    Bigint bigint2(-23);
    ASSERT_EQ("-5", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator6) {
    Bigint bigint1(-123);
    Bigint bigint2(23);
    ASSERT_EQ("-5", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator7) {
    Bigint bigint1(-123);
    Bigint bigint2(-23);
    ASSERT_EQ("5", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator8) {
    Bigint bigint1("9587345983475345873129372197");
    Bigint bigint2("412343242342342384092384203");
    ASSERT_EQ("23", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator9) {
    Bigint bigint1("9587345983475345873129372197");
    Bigint bigint2("9587345983475345873129372197");
    ASSERT_EQ("1", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator10) {
    Bigint bigint1("-0");
    Bigint bigint2("312321");
    ASSERT_EQ("0", (bigint1 / bigint2).to_string());
}

TEST(BigintTest, testDivisionOperator11) {
    Bigint bigint1("312323");
    Bigint bigint2("0");
    ASSERT_ANY_THROW(bigint1 / bigint2);
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

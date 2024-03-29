#include "gtest/gtest.h"
#include "Bigfloat.h"

// Default constructor test
TEST(BigfloatTest, testDefaultConstructor) {
    Bigfloat bigfloat;
    ASSERT_EQ(bigfloat.number().value(), "0");
    ASSERT_EQ(bigfloat.precision(), 6);
}



// String constructor test
TEST(BigfloatTest, testStringConstructor1) {
    Bigfloat bigfloat("123.456789", 6);
    ASSERT_EQ(bigfloat.number().to_string(), "123456789");
    ASSERT_EQ(bigfloat.precision(), 6);
}

TEST(BigfloatTest, testStringConstructor2) {
    Bigfloat bigfloat("123.45", 6);
    ASSERT_EQ(bigfloat.number().to_string(), "123450000");
    ASSERT_EQ(bigfloat.precision(), 6);
}

TEST(BigfloatTest, testStringConstructor3) {
    Bigfloat bigfloat("123.4567", 2);
    ASSERT_EQ(bigfloat.number().to_string(), "12345");
    ASSERT_EQ(bigfloat.precision(), 2);
}

TEST(BigfloatTest, testStringConstructor4) {
    Bigfloat bigfloat("123.4567", 8);
    ASSERT_EQ(bigfloat.number().to_string(), "12345670000");
    ASSERT_EQ(bigfloat.precision(), 8);
}

TEST(BigfloatTest, testStringConstructor5) {
    Bigfloat bigfloat("0.12345678", 8);
    ASSERT_EQ(bigfloat.number().to_string(), "12345678");
    ASSERT_EQ(bigfloat.precision(), 8);
}

TEST(BigfloatTest, testStringConstructor6) {
    Bigfloat bigfloat("-0.12345678", 8);
    ASSERT_EQ(bigfloat.number().to_string(), "-12345678");
    ASSERT_EQ(bigfloat.precision(), 8);
}

TEST(BigfloatTest, testStringConstructor7) {
    Bigfloat bigfloat("-0.12345678", 2);
    ASSERT_EQ(bigfloat.number().to_string(), "-12");
    ASSERT_EQ(bigfloat.precision(), 2);
}

TEST(BigfloatTest, testStringConstructor8) {
    Bigfloat bigfloat("1234.5678", 2);
    ASSERT_EQ(bigfloat.number().to_string(), "123456");
    ASSERT_EQ(bigfloat.precision(), 2);
}

TEST(BigfloatTest, testStringConstructor9) {
    Bigfloat bigfloat("1234.5678", 8);
    ASSERT_EQ(bigfloat.number().to_string(), "123456780000");
    ASSERT_EQ(bigfloat.precision(), 8);
}

TEST(BigfloatTest, testStringConstructor10) {
    Bigfloat bigfloat("1", 8);
    ASSERT_EQ(bigfloat.number().to_string(), "100000000");
    ASSERT_EQ(bigfloat.precision(), 8);
}

TEST(BigfloatTest, testStringConstructor11) {
    ASSERT_ANY_THROW(Bigfloat("00.31312"));
}

TEST(BigfloatTest, testStringConstructor12) {
    ASSERT_ANY_THROW(Bigfloat(".31312"));
}

TEST(BigfloatTest, testStringConstructor13) {
    ASSERT_ANY_THROW(Bigfloat("31.31.2"));
}



/// to_string method test
TEST(BigfloatTest, testToString1) {
    Bigfloat bigfloat("123.456789", 6);
    ASSERT_EQ(bigfloat.to_string(), "123.456789");
}

TEST(BigfloatTest, testToString2) {
    Bigfloat bigfloat("123.45", 6);
    ASSERT_EQ(bigfloat.to_string(), "123.450000");
}

TEST(BigfloatTest, testToString3) {
    Bigfloat bigfloat("123.4567", 2);
    ASSERT_EQ(bigfloat.to_string(), "123.45");
}

TEST(BigfloatTest, testToString4) {
    Bigfloat bigfloat("0.4567", 8);
    ASSERT_EQ(bigfloat.to_string(), "0.45670000");
}

TEST(BigfloatTest, testToString5) {
    Bigfloat bigfloat("-0.001", 8);
    ASSERT_EQ(bigfloat.to_string(), "-0.00100000");
}

TEST(BigfloatTest, testToString6) {
    Bigfloat bigfloat("-1.1", 2);
    ASSERT_EQ(bigfloat.to_string(), "-1.10");
}

TEST(BigfloatTest, testToString7) {
    Bigfloat bigfloat("0", 2);
    ASSERT_EQ(bigfloat.to_string(), "0.00");
}

TEST(BigfloatTest, testToString8) {
    Bigfloat bigfloat("-0", 2);
    ASSERT_EQ(bigfloat.to_string(), "0.00");
}

TEST(BigfloatTest, testToString9) {
    Bigfloat bigfloat("1234.5678", 0);
    ASSERT_EQ(bigfloat.to_string(), "1234");
}

TEST(BigfloatTest, testToString10) {
    Bigfloat bigfloat("-0", 0);
    ASSERT_EQ(bigfloat.to_string(), "0");
}



/// Unary minus operator test
TEST(BigfloatTest, testUnaryMinus1) {
    Bigfloat bigfloat("123.456789", 6);
    ASSERT_EQ((-bigfloat).to_string(), "-123.456789");
}

TEST(BigfloatTest, testUnaryMinus2) {
    Bigfloat bigfloat("-123.456789", 6);
    ASSERT_EQ((-bigfloat).to_string(), "123.456789");
}

TEST(BigfloatTest, testUnaryMinus3) {
    Bigfloat bigfloat("0", 6);
    ASSERT_EQ((-bigfloat).to_string(), "0.000000");
}



/// Equality operator test
TEST(BigfloatTest, testEqualityOperator1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_TRUE(bigfloat1 == bigfloat2);
    ASSERT_TRUE(bigfloat1 == bigfloat2);
}

TEST(BigfloatTest, testEqualityOperator2) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.4567890000", 10);
    ASSERT_TRUE(bigfloat1 == bigfloat2);
    ASSERT_TRUE(bigfloat2 == bigfloat1);
}

TEST(BigfloatTest, testEqualityOperator3) {
    Bigfloat bigfloat1("-0.000", 6);
    Bigfloat bigfloat2("0.0000000", 4);
    ASSERT_TRUE(bigfloat1 == bigfloat2);
    ASSERT_TRUE(bigfloat2 == bigfloat1);
}



/// Less than operator test
TEST(BigfloatTest, testLessThanOperator1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_FALSE(bigfloat1 < bigfloat2);
    ASSERT_FALSE(bigfloat2 < bigfloat1);
}

TEST(BigfloatTest, testLessThanOperator2) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.4567890000", 10);
    ASSERT_FALSE(bigfloat1 < bigfloat2);
    ASSERT_FALSE(bigfloat2 < bigfloat1);
}

TEST(BigfloatTest, testLessThanOperator3) {
    Bigfloat bigfloat1("-0.000", 6);
    Bigfloat bigfloat2("0.0000000", 4);
    ASSERT_FALSE(bigfloat1 < bigfloat2);
    ASSERT_FALSE(bigfloat2 < bigfloat1);
}

TEST(BigfloatTest, testLessThanOperator4) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.4567891000", 10);
    ASSERT_TRUE(bigfloat1 < bigfloat2);
    ASSERT_FALSE(bigfloat2 < bigfloat1);
}

TEST(BigfloatTest, testLessThanOperator5) {
    Bigfloat bigfloat1("-0.001", 6);
    Bigfloat bigfloat2("0.0000001", 4);
    ASSERT_TRUE(bigfloat1 < bigfloat2);
    ASSERT_FALSE(bigfloat2 < bigfloat1);
}

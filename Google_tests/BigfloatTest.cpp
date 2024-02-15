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



/// Add function test
TEST(BigfloatTest, testAdd1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 6).to_string(), "246.913578");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 6).to_string(), "246.913578");
}

TEST(BigfloatTest, testAdd2) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 2);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 6).to_string(), "246.906789");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 6).to_string(), "246.906789");
}

TEST(BigfloatTest, testAdd3) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 8);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 6).to_string(), "246.913578");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 6).to_string(), "246.913578");
}

TEST(BigfloatTest, testAdd4) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 8);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 0).to_string(), "246");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 0).to_string(), "246");
}

TEST(BigfloatTest, testAdd5) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("-123.456789", 6);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 6).to_string(), "0.000000");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 6).to_string(), "0.000000");
}

TEST(BigfloatTest, testAdd6) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("-123.456789", 6);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 0).to_string(), "0");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 0).to_string(), "0");
}

TEST(BigfloatTest, testAdd7) {
    Bigfloat bigfloat1("-123.456789", 6);
    Bigfloat bigfloat2("0", 6);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 8).to_string(), "-123.45678900");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 8).to_string(), "-123.45678900");
}

TEST(BigfloatTest, testAdd8) {
    Bigfloat bigfloat1("-123.456789", 6);
    Bigfloat bigfloat2("-0", 6);
    ASSERT_EQ(bigfloat1.add(bigfloat2, 8).to_string(), "-123.45678900");
    ASSERT_EQ(bigfloat2.add(bigfloat1, 8).to_string(), "-123.45678900");
}



/// Subtraction function test
TEST(BigfloatTest, testSubtract1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.subtract(bigfloat2, 6).to_string(), "0.000000");
}

TEST(BigfloatTest, testSubtract2) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.subtract(bigfloat2, 8).to_string(), "0.00000000");
}

TEST(BigfloatTest, testSubtract3) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 2);
    ASSERT_EQ(bigfloat1.subtract(bigfloat2, 6).to_string(), "0.006789");
}

TEST(BigfloatTest, testSubtract4) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 8);
    ASSERT_EQ(bigfloat1.subtract(bigfloat2, 10).to_string(), "0.0000000000");
}



/// Multiplication function test
TEST(BigfloatTest, testMultiply1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 8).to_string(), "15241.57875019");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 8).to_string(), "15241.57875019");
}

TEST(BigfloatTest, testMultiply2) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 0).to_string(), "15241");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 0).to_string(), "15241");
}

TEST(BigfloatTest, testMultiply3) {
    Bigfloat bigfloat1("-123.456789", 6);
    Bigfloat bigfloat2("1", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 2).to_string(), "-123.45");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 2).to_string(), "-123.45");
}

TEST(BigfloatTest, testMultiply4) {
    Bigfloat bigfloat1("1.1", 6);
    Bigfloat bigfloat2("1.2", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 4).to_string(), "1.3200");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 4).to_string(), "1.3200");
}

TEST(BigfloatTest, testMultiply5) {
    Bigfloat bigfloat1("0.0001", 6);
    Bigfloat bigfloat2("10000", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 6).to_string(), "1.000000");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 6).to_string(), "1.000000");
}

TEST(BigfloatTest, testMultiply6) {
    Bigfloat bigfloat1("0.00000000000000000098347598347534982345234532453245234534267349507689045376894537698453769887234598623789456", 6);
    Bigfloat bigfloat2("1000020353452345324523453459785756834789573289457894890275893475983475893478953498347347578934682457689054604", 6);
    ASSERT_EQ(bigfloat1.multiply(bigfloat2, 0).to_string(), "0");
    ASSERT_EQ(bigfloat2.multiply(bigfloat1, 0).to_string(), "0");
}



/// Division function test
TEST(BigfloatTest, testDivide1) {
    Bigfloat bigfloat1("123.456789", 6);
    Bigfloat bigfloat2("123.456789", 6);
    ASSERT_EQ(bigfloat1.divide(bigfloat2, 6).to_string(), "1.000000");
}

TEST(BigfloatTest, testDivide2) {
    Bigfloat bigfloat1("1", 0);
    Bigfloat bigfloat2("3", 0);
    ASSERT_EQ(bigfloat1.divide(bigfloat2, 100).to_string(), "0." + std::string(100, '3'));
}

TEST(BigfloatTest, testDivide3) {
    Bigfloat bigfloat1("12312.3123", 4);
    Bigfloat bigfloat2("5346.534", 3);
    ASSERT_EQ(bigfloat1.divide(bigfloat2, 10).to_string(), "2.3028586931");
}

TEST(BigfloatTest, testDivide4) {
    Bigfloat bigfloat1("-12312.3123", 4);
    Bigfloat bigfloat2("5346.534", 3);
    ASSERT_EQ(bigfloat2.divide(bigfloat1, 10).to_string(), "-0.4342428838");
}

TEST(BigfloatTest, testDivide5) {
    Bigfloat bigfloat1("-12312.3123", 4);
    Bigfloat bigfloat2("-534.6534", 4);
    ASSERT_EQ(bigfloat2.divide(bigfloat1, 10).to_string(), "0.0434242883");
}

TEST(BigfloatTest, testDivide6) {
    Bigfloat bigfloat1("12312.3123", 4);
    Bigfloat bigfloat2("0.000000000", 4);
    Bigfloat res;
    ASSERT_ANY_THROW(res = bigfloat1.divide(bigfloat2, 10));
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

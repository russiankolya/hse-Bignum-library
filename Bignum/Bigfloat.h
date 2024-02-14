#ifndef HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#define HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#include "Bigint.h"

class Bigfloat {
public:
    /// Default constructor
    /// \param number string representation of the number
    /// \param precision uint8_t precision
    /// \note Default precision is 6
    Bigfloat(std::string number = "0", uint8_t precision = 6);

    /// Number getter
    /// \return Bigint number
    [[nodiscard]] Bigint number() const;
    /// Precision getter
    /// \return uint8_t precision
    [[nodiscard]] uint8_t precision() const;

    /// to_string method
    /// \returns string representation of the Bigfloat
    [[nodiscard]] std::string to_string() const;

    /// Unary minus operator
    /// \returns Bigfloat with the opposite sign
    Bigfloat operator-() const;

    /// Addition of two Bigfloat with given precision
    Bigfloat add(const Bigfloat& other, uint8_t precision) const;
    /// Subtraction of two Bigfloat with given precision
    Bigfloat subtract(const Bigfloat& other, uint8_t precision) const;
    /// Multiplication of two Bigfloat with given precision
    Bigfloat multiply(const Bigfloat& other, uint8_t precision) const;
    /// Division of two Bigfloat with given precision
    Bigfloat divide(const Bigfloat& other, uint8_t precision) const;


    /// Addition operator of two Bigfloat
    Bigfloat operator+(const Bigfloat& other) const;
    /// Subtraction operator of two Bigfloat
    Bigfloat operator-(const Bigfloat& other) const;
    /// Multiplication operator of two Bigfloat
    Bigfloat operator*(const Bigfloat& other) const;
    /// Division operator of two Bigfloat
    Bigfloat operator/(const Bigfloat& other) const;


    /// Assignment addition operator of two Bigfloat
    Bigfloat operator+=(const Bigfloat& other);
    /// Assignment subtraction operator of two Bigfloat
    Bigfloat operator-=(const Bigfloat& other);
    /// Assignment multiplication operator of two Bigfloat
    Bigfloat operator*=(const Bigfloat& other);
    /// Assignment division operator of two Bigfloat
    Bigfloat operator/=(const Bigfloat& other);

    /// Equality operator of two Bigfloat
    bool operator==(const Bigfloat& other) const;
    /// Inequality operator of two Bigfloat
    bool operator!=(const Bigfloat& other) const;
    /// Less than operator of two Bigfloat
    bool operator<(const Bigfloat& other) const;
    /// Greater than operator of two Bigfloat
    bool operator>(const Bigfloat& other) const;
    /// Less than or equal to operator of two Bigfloat
    bool operator<=(const Bigfloat& other) const;
    /// Greater than or equal to operator of two Bigfloat
    bool operator>=(const Bigfloat& other) const;

    /// Output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Bigfloat& bigfloat);
    /// Input stream operator
    friend std::istream& operator>>(std::istream& is, Bigfloat& bigfloat);

private:
    Bigint _number;
    uint8_t _precision;

    Bigfloat(Bigint number, uint8_t precision = 6);
};

#endif

#ifndef HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#define HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#include "Bigint.h"

/// \class Bigfloat
/// \brief Class for working with big floating point numbers with static precision
/// \details The class is designed to work with floating point numbers with arbitrary precision

class Bigfloat {
public:
    /// \brief Default constructor
    /// \details Initializes the value to 0 and precision to 6
    /// \param value double value to be converted to Bigfloat
    /// \param precision uint8_t precision of the floating point number
    /// \warning Sum of the integer part length and precision must be less than 18
    explicit Bigfloat(double value = 0.0, uint8_t precision = 6);

    /// \brief Value getter
    /// \details Returns the value of the big floating point number. Literally the value of the Bigfloat is a concatenation of the integer part and the fractional part
    /// \return Bigint
    [[nodiscard]] Bigint get_value() const;

    /// \brief Precision getter
    /// \return uint8_t
    [[nodiscard]] uint8_t get_precision() const;

    /// \brief String representation of the big floating point number
    /// \return std::string string representation of the big floating point number
    [[nodiscard]] std::string to_string() const;

    /// \brief Unary minus operator
    /// \return Bigfloat
    Bigfloat operator-() const;

    Bigfloat operator+(const Bigfloat &other) const;
    Bigfloat operator-(const Bigfloat &other) const;
    Bigfloat operator*(const Bigfloat &other) const;
    Bigfloat operator/(const Bigfloat &other) const;

    Bigfloat &operator+=(const Bigfloat &other);
    Bigfloat &operator-=(const Bigfloat &other);
    Bigfloat &operator*=(const Bigfloat &other);
    Bigfloat &operator/=(const Bigfloat &other);

    bool operator==(const Bigfloat &other) const;
    bool operator!=(const Bigfloat &other) const;
    bool operator<(const Bigfloat &other) const;
    bool operator>(const Bigfloat &other) const;
    bool operator<=(const Bigfloat &other) const;
    bool operator>=(const Bigfloat &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Bigfloat &bigfloat);
    friend std::istream &operator>>(std::istream &is, Bigfloat &bigfloat);

private:
    Bigint _value;
    uint8_t _precision;
};

#endif

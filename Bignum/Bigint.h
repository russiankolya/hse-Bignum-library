#ifndef HSE_BIGNUM_LIBRARY_BIGINT_H
#define HSE_BIGNUM_LIBRARY_BIGINT_H
#include <iostream>

class Bigint {
public:
    /// Default constructor
    /// \param value int64_t value to be converted to Bigint
    explicit Bigint(int64_t value = 0);

    /// String constructor
    /// \param value string value to be converted to Bigint
    explicit Bigint(const std::string &value);

    /// value getter
    /// \return std::string absolut value of the Bigint
    [[nodiscard]] std::string value() const;

    /// is_negative getter
    /// \return bool true if the Bigint is negative
    [[nodiscard]] bool is_negative() const;


    /// to_string method
    /// \returns string representation of the Bigint
    [[nodiscard]] std::string to_string() const;

    /// Unary minus operator
    /// \returns Bigint with the opposite sign
    Bigint operator-() const;


    /// Addition of two strings representing Bigint
    /// \param value1 first string
    /// \param value2 second string
    /// \returns string representing the sum of the two strings
    /// \note This method is static
    static std::string add(std::string value1, std::string value2);

    /// Subtraction of two strings representing Bigint
    /// \param value1 first string
    /// \param value2 second string
    /// \returns string representing the difference of the two strings
    /// \warning value1 must be greater than or equal to value2
    /// \note This method is static
    static std::string subtract(std::string value1, std::string value2);

    Bigint operator+(const Bigint &other) const;
    Bigint operator-(const Bigint &other) const;
    Bigint operator*(const Bigint &other) const;
    Bigint operator/(const Bigint &other) const;

    Bigint &operator+=(const Bigint &other);
    Bigint &operator-=(const Bigint &other);
    Bigint &operator*=(const Bigint &other);
    Bigint &operator/=(const Bigint &other);

    bool operator==(const Bigint &other) const;
    bool operator!=(const Bigint &other) const;
    bool operator<(const Bigint &other) const;
    bool operator>(const Bigint &other) const;
    bool operator<=(const Bigint &other) const;
    bool operator>=(const Bigint &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Bigint &bigint);
    friend std::istream &operator>>(std::istream &is, Bigint &bigint);

private:
    std::string _value;
    bool _is_negative;
};

#endif

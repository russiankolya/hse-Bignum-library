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
    [[nodiscard]] std::string get_value() const;

    /// is_negative getter
    /// \return bool true if the Bigint is negative
    [[nodiscard]] bool is_negative() const;


    /// to_string method
    /// \returns string representation of the Bigint
    [[nodiscard]] std::string to_string() const;

    /// Unary minus operator
    /// \returns Bigint with the opposite sign
    Bigint operator-() const;

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

    static std::string add(const std::string& value1, const std::string& value2);
    static std::string subtract(const std::string& value1, const std::string& value2);
};

#endif

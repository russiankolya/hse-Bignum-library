#ifndef HSE_BIGNUM_LIBRARY_BIGINT_H
#define HSE_BIGNUM_LIBRARY_BIGINT_H
#include <iostream>

class Bigint {
public:
    explicit Bigint(int64_t value = 0);
    explicit Bigint(const std::string &value);

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
    bool _isNegative;

    static std::string add(const std::string& value1, const std::string& value2);
    static std::string subtract(const std::string& value1, const std::string& value2);
};

#endif

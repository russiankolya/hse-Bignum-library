#ifndef HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#define HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#include "Bigint.h"

class Bigfloat {
public:
    explicit Bigfloat(double value = 0.0, int precision = 6);
    explicit Bigfloat(const std::string &value, int precision = 6);

    [[nodiscard]] Bigint get_value() const;
    [[nodiscard]] uint8_t get_precision() const;
    [[nodiscard]] std::string to_string() const;

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

#ifndef HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#define HSE_BIGNUM_LIBRARY_BIGFLOAT_H
#include "Bigint.h"

class Bigfloat {
public:
    Bigfloat(std::string number = 0, uint8_t precision = 6);


    [[nodiscard]] Bigint number() const;
    [[nodiscard]] uint8_t precision() const;

    [[nodiscard]] std::string to_string() const;

    Bigfloat operator-() const;

    Bigfloat operator+(const Bigfloat& other) const;
    Bigfloat operator-(const Bigfloat& other) const;
    Bigfloat operator*(const Bigfloat& other) const;
    Bigfloat operator/(const Bigfloat& other) const;

    Bigfloat operator+=(const Bigfloat& other);
    Bigfloat operator-=(const Bigfloat& other);
    Bigfloat operator*=(const Bigfloat& other);
    Bigfloat operator/=(const Bigfloat& other);

    bool operator==(const Bigfloat& other) const;
    bool operator!=(const Bigfloat& other) const;
    bool operator<(const Bigfloat& other) const;
    bool operator>(const Bigfloat& other) const;
    bool operator<=(const Bigfloat& other) const;
    bool operator>=(const Bigfloat& other) const;


private:
    Bigint _number;
    uint8_t _precision;

    Bigfloat(Bigint number = Bigint(0), uint8_t precision = 6);
};

#endif

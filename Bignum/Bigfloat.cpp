#include "Bigfloat.h"

Bigfloat::Bigfloat(double value, int precision) {
    for (int i = 0; i < precision; ++i) {
        value *= 10;
    }
    _value = Bigint(static_cast<int64_t>(value));
    _precision = precision;
}

Bigint Bigfloat::get_value() const {
    return _value;
}

uint8_t Bigfloat::get_precision() const {
    return _precision;
}
#include "Bigfloat.h"

Bigfloat::Bigfloat(double value, uint8_t precision) {
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

std::string Bigfloat::to_string() const {
    std::string result = _value.to_string();
    if (_precision > 0) {
        result.insert(result.size() - _precision, ".");
    }
    return result;
}
#include "Bigint.h"

Bigint::Bigint(int64_t value) {
    if (value < 0) {
        _is_negative = true;
        value = -value;
    } else {
        _is_negative = false;
    }
    _value = std::to_string(value);
}

Bigint::Bigint(const std::string &value) {
    if (value[0] == '-') {
        _value = value.substr(1);
        if (_value != "0") {
            _is_negative = true;
        }
    } else {
        _is_negative = false;
        _value = value;
    }
}

std::string Bigint::value() const {
    return _value;
}

bool Bigint::is_negative() const {
    return _is_negative;
}

std::string Bigint::to_string() const {
    std::string result;
    if (_is_negative) {
        result += '-';
    }
    result += _value;
    return result;
}

Bigint Bigint::operator-() const {
    Bigint result = *this;
    if (result._value != "0") {
        result._is_negative = !_is_negative;
    }
    return result;
}

Bigint Bigint::operator+(const Bigint &other) const {
    int64_t value1 = _is_negative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._is_negative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 + value2);
}

Bigint Bigint::operator-(const Bigint &other) const {
    int64_t value1 = _is_negative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._is_negative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 - value2);
}

Bigint Bigint::operator*(const Bigint &other) const {
    int64_t value1 = _is_negative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._is_negative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 * value2);
}

Bigint Bigint::operator/(const Bigint &other) const {
    int64_t value1 = _is_negative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._is_negative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 / value2);
}

Bigint &Bigint::operator+=(const Bigint &other) {
    *this = *this + other;
    return *this;
}

Bigint &Bigint::operator-=(const Bigint &other) {
    *this = *this - other;
    return *this;
}

Bigint &Bigint::operator*=(const Bigint &other) {
    *this = *this * other;
    return *this;
}

Bigint &Bigint::operator/=(const Bigint &other) {
    *this = *this / other;
    return *this;
}

bool Bigint::operator==(const Bigint &other) const {
    return _is_negative == other._is_negative && _value == other._value;
}

bool Bigint::operator!=(const Bigint &other) const {
    return !(*this == other);
}

bool Bigint::operator<(const Bigint &other) const {
    if (_is_negative && !other._is_negative) {
        return true;
    } else if (!_is_negative && other._is_negative) {
        return false;
    } else if (_is_negative && other._is_negative) {
        return -stoll(_value) > -stoll(other._value);
    } else {
        return stoll(_value) < stoll(other._value);
    }
}

bool Bigint::operator>(const Bigint &other) const {
    return !(*this < other || *this == other);
}

bool Bigint::operator<=(const Bigint &other) const {
    return *this < other || *this == other;
}

bool Bigint::operator>=(const Bigint &other) const {
    return *this > other || *this == other;
}

std::ostream &operator<<(std::ostream &os, const Bigint &bigint) {
    os << bigint.to_string();
    return os;
}

std::istream &operator>>(std::istream &is, Bigint &bigint) {
    std::string value;
    is >> value;
    bigint = Bigint(value);
    return is;
}
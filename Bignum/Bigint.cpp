#include "Bigint.h"

Bigint::Bigint(int64_t value) {
    if (value < 0) {
        _isNegative = true;
        value = -value;
    } else {
        _isNegative = false;
    }
    _value = std::to_string(value);
}

Bigint::Bigint(const std::string &value) {
    if (value[0] == '-') {
        _isNegative = true;
        _value = value.substr(1);
    } else {
        _isNegative = false;
        _value = value;
    }
}

Bigint Bigint::operator-() const {
    Bigint result = *this;
    result._isNegative = !_isNegative;
    return result;
}

Bigint Bigint::operator+(const Bigint &other) const {
    int64_t value1 = _isNegative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._isNegative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 + value2);
}

Bigint Bigint::operator-(const Bigint &other) const {
    int64_t value1 = _isNegative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._isNegative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 - value2);
}

Bigint Bigint::operator*(const Bigint &other) const {
    int64_t value1 = _isNegative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._isNegative ? -std::stoll(other._value) : std::stoll(other._value);
    return Bigint(value1 * value2);
}

Bigint Bigint::operator/(const Bigint &other) const {
    int64_t value1 = _isNegative ? -std::stoll(_value) : std::stoll(_value);
    int64_t value2 = other._isNegative ? -std::stoll(other._value) : std::stoll(other._value);
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
    return _isNegative == other._isNegative && _value == other._value;
}

bool Bigint::operator!=(const Bigint &other) const {
    return !(*this == other);
}

bool Bigint::operator<(const Bigint &other) const {
    if (_isNegative && !other._isNegative) {
        return true;
    } else if (!_isNegative && other._isNegative) {
        return false;
    } else if (_isNegative && other._isNegative) {
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
    if (bigint._isNegative) {
        os << '-';
    }
    os << bigint._value;
    return os;
}

std::istream &operator>>(std::istream &is, Bigint &bigint) {
    std::string value;
    is >> value;
    bigint = Bigint(value);
    return is;
}
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

std::string Bigint::add(std::string value1, std::string value2) {
    std::reverse(value1.begin(), value1.end());
    std::reverse(value2.begin(), value2.end());

    if (value1.size() < value2.size()) {
        std::swap(value1, value2);
    }

    std::string result;
    int carry = 0;
    for (size_t i = 0; i < value1.size(); ++i) {
        int sum = (value1[i] - '0');
        if (i < value2.size()) {
            sum += (value2[i] - '0');
        }
        sum += (carry);
        result += static_cast<char>('0' + (sum % 10));
        carry = sum / 10;
    }
    if (carry > 0) {
        result += static_cast<char>('0' + carry);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string Bigint::subtract(std::string value1, std::string value2) {
    std::reverse(value1.begin(), value1.end());
    std::reverse(value2.begin(), value2.end());

    std::string result;
    int carry = 0;
    for (size_t i = 0; i < value1.size(); ++i) {
        int diff = (value1[i] - '0');
        if (i < value2.size()) {
            diff -= (value2[i] - '0');
        }
        diff -= (carry);
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result += static_cast<char>('0' + diff);
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;

}

Bigint Bigint::operator+(const Bigint &other) const {

}

Bigint Bigint::operator-(const Bigint &other) const {

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
    if (_is_negative == other._is_negative) {
        if (!_is_negative) {
            if (_value.size() < other._value.size()) {
                return true;
            }
            if (_value.size() > other._value.size()) {
                return false;
            }
            return _value < other._value;
        } else {
            if (_value.size() < other._value.size()) {
                return false;
            }
            if (_value.size() > other._value.size()) {
                return true;
            }
            return _value > other._value;
        }
    } else {
        if (_is_negative) {
            return true;
        } else {
            return false;
        }
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
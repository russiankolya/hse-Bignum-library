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
        diff -= carry;
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
    if (_is_negative == other._is_negative) {
        if (!_is_negative) {
            return Bigint(add(_value, other._value));
        } else {
            return -Bigint(add((-*this)._value, (-other)._value));;
        }
    } else {
        if (!_is_negative) {
            if (*this > -other) {
                return Bigint(subtract(_value, (-other)._value));
            } else {
                return -Bigint(subtract((-other)._value, _value));
            }
        } else {
            if (other > -*this) {
                return Bigint(subtract(other._value, (-*this)._value));
            } else {
                return -Bigint(subtract((-*this)._value, other._value));
            }
        }
    }
}

Bigint Bigint::operator-(const Bigint &other) const {
    return *this + (-other);
}

Bigint Bigint::operator*(const Bigint &other) const {
    std::string value1 = _value;
    std::string value2 = other._value;

    size_t value1_size = value1.size();
    size_t value2_size = value2.size();

    std::vector<int> result(value1_size + value2_size, 0);

    for (int i = static_cast<int>(value1_size) - 1; i >= 0; --i) {
        for (int j = static_cast<int>(value2_size) - 1; j >= 0; --j) {
            int mul = (value1[i] - '0') * (value2[j] - '0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    std::reverse(result.begin(), result.end());
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    std::string string_result;
    for (int c : result) {
        string_result += static_cast<char>('0' + c);
    }

    bool is_negative = _is_negative ^ other._is_negative;
    if (string_result == "0") {
        is_negative = false;
    }

    if (!is_negative) {
        return Bigint(string_result);
    } else {
        return Bigint("-" + string_result);
    }
}

Bigint Bigint::operator/(const Bigint &other) const {
    if (other == Bigint(0)) {
        throw std::runtime_error("Division by zero");
    }

    Bigint value1 = *this;
    Bigint value2 = other;

    bool is_negative = value1._is_negative ^ value2._is_negative;
    if (value1._is_negative) {
        value1 = -value1;
    }
    if (value2._is_negative) {
        value2 = -value2;
    }

    std::string result;
    Bigint temp(0);

    for (char c : value1._value) {
        temp *= Bigint(10);
        temp += Bigint(c - '0');
        size_t count = 0;
        while (Bigint(temp) >= Bigint(value2)) {
            temp -= Bigint(value2);
            count++;
        }
        result += static_cast<char>('0' + count);
    }

    std::reverse(result.begin(), result.end());
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    if (result == "0") {
        is_negative = false;
    }

    if (!is_negative) {
        return Bigint(result);
    } else {
        return Bigint("-" + result);
    }
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
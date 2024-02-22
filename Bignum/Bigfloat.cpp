#include "Bigfloat.h"
#include <utility>

Bigfloat::Bigfloat(Bigint number, uint8_t precision) {
    _number = std::move(number);
    _precision = precision;
}

Bigfloat::Bigfloat(std::string number, uint8_t precision) : _precision(precision) {
    bool is_negative = false;
    if (number[0] == '-') {
        number = number.substr(1);
        is_negative = true;
    }

    size_t dot_position = number.find('.');

    if (std::any_of(number.begin(), number.end(), [](char c) { return !std::isdigit(c) && c != '.'; })
        || std::count(number.begin(), number.end(), '.') > 1
        || number.empty()
        || (number.size() > 1 && number[0] == '0' && number[1] == '0')
        || dot_position == 0 || dot_position == number.size() - 1) {
        throw std::runtime_error("Invalid number format");
    }

    if (dot_position == std::string::npos) {
        _number = Bigint(number);
        uint8_t current_precision = 0;
        while (current_precision < precision) {
            _number *= Bigint(10);
            current_precision++;
        }
    } else {
        std::string integer_part = number.substr(0, dot_position);
        std::string fractional_part = number.substr(dot_position + 1);

        uint8_t current_precision = fractional_part.size();
        while (current_precision < precision) {
            fractional_part += '0';
            current_precision++;
        }
        while (current_precision > precision) {
            fractional_part.pop_back();
            current_precision--;
        }

        //remove leading zeros from fractional part
        std::reverse(fractional_part.begin(), fractional_part.end());
        while (fractional_part.back() == '0' && fractional_part.size() > 1) {
            fractional_part.pop_back();
        }
        std::reverse(fractional_part.begin(), fractional_part.end());

        std::string result;

        if (integer_part != "0") {
            result += integer_part;
        }
        result += fractional_part;

        _number = Bigint(result);
    }

    if (_number == Bigint("0")) {
        is_negative = false;
    }

    if (is_negative) {
        _number = -_number;
    }
}

Bigint Bigfloat::number() const {
    return _number;
}

uint8_t Bigfloat::precision() const {
    return _precision;
}

std::string Bigfloat::to_string() const {
    if (_precision == 0) {
        return _number.to_string();
    }
    std::string result = _number.value();
    if (result.size() <= _precision) {
        result.insert(0, _precision - result.size(), '0');
        result.insert(0, "0.");
    } else {
        result.insert(result.size() - _precision, ".");
    }
    return _number.is_negative() ? "-" + result : result;
}

Bigfloat Bigfloat::operator-() const {
    return Bigfloat(-_number, _precision);
}

Bigfloat Bigfloat::add(const Bigfloat &other, uint8_t precision) const {
    uint8_t max_precision = std::max(_precision, other._precision);
    Bigint number1 = _number;
    Bigint number2 = other._number;
    for (uint8_t i = 0; i < max_precision - _precision; i++) {
        number1 *= Bigint(10);
    }
    for (uint8_t i = 0; i < max_precision - other._precision; i++) {
        number2 *= Bigint(10);
    }
    Bigint result = number1 + number2;
    while (max_precision < precision) {
        result *= Bigint(10);
        max_precision++;
    }
    while (max_precision > precision) {
        result /= Bigint(10);
        max_precision--;
    }
    return Bigfloat(result, precision);
}

Bigfloat Bigfloat::subtract(const Bigfloat &other, uint8_t precision) const {
    return add(-other, precision);
}

Bigfloat Bigfloat::multiply(const Bigfloat &other, uint8_t precision) const {
    Bigint number1 = _number;
    Bigint number2 = other._number;

    Bigint result = number1 * number2;
    uint8_t new_precision = _precision + other._precision;
    while (new_precision < precision) {
        result *= Bigint(10);
        new_precision++;
    }
    while (new_precision > precision) {
        result /= Bigint(10);
        new_precision--;
    }
    return Bigfloat(result, precision);
}

Bigfloat Bigfloat::divide(const Bigfloat &other, uint8_t precision) const {
    if (other._number == Bigint("0")) {
        throw std::runtime_error("Division by zero");
    }

    Bigint number1 = _number;
    Bigint number2 = other._number;
    uint8_t number1_precision = _precision;
    uint8_t number2_precision = other._precision;

    while (number1_precision < number2_precision) {
        number1 *= Bigint(10);
        number1_precision++;
    }
    while (number2_precision < number1_precision) {
        number2 *= Bigint(10);
        number2_precision++;
    }

    for (uint8_t i = 0; i < precision; i++) {
        number1 *= Bigint(10);
    }

    Bigint result = number1 / number2;
    return Bigfloat(result, precision);

}

Bigfloat Bigfloat::operator+(const Bigfloat &other) const {
    return add(other, std::max(_precision, other._precision));
}

Bigfloat Bigfloat::operator-(const Bigfloat &other) const {
    return subtract(other, std::max(_precision, other._precision));
}

Bigfloat Bigfloat::operator*(const Bigfloat &other) const {
    return multiply(other, std::max(_precision, other._precision));
}

Bigfloat Bigfloat::operator/(const Bigfloat &other) const {
    return divide(other, std::max(_precision, other._precision));
}

Bigfloat Bigfloat::operator+=(const Bigfloat &other) {
    *this = (*this).add(other, _precision);
    return *this;
}

Bigfloat Bigfloat::operator-=(const Bigfloat &other) {
    *this = (*this).subtract(other, _precision);
    return *this;
}

Bigfloat Bigfloat::operator*=(const Bigfloat &other) {
    *this = (*this).multiply(other, _precision);
    return *this;
}

Bigfloat Bigfloat::operator/=(const Bigfloat &other) {
    *this = (*this).divide(other, _precision);
    return *this;
}

bool Bigfloat::operator==(const Bigfloat &other) const {
    Bigint number1 = _number;
    Bigint number2 = other._number;
    uint8_t number1_precision = _precision;
    uint8_t number2_precision = other._precision;

    while (number1_precision < number2_precision) {
        number1 *= Bigint(10);
        number1_precision++;
    }
    while (number2_precision < number1_precision) {
        number2 *= Bigint(10);
        number2_precision++;
    }
    return number1 == number2;
}

bool Bigfloat::operator<(const Bigfloat &other) const {
    Bigint number1 = _number;
    Bigint number2 = other._number;
    uint8_t number1_precision = _precision;
    uint8_t number2_precision = other._precision;

    while (number1_precision < number2_precision) {
        number1 *= Bigint(10);
        number1_precision++;
    }
    while (number2_precision < number1_precision) {
        number2 *= Bigint(10);
        number2_precision++;
    }
    return number1 < number2;
}

bool Bigfloat::operator!=(const Bigfloat &other) const {
    return !(*this == other);
}

bool Bigfloat::operator>(const Bigfloat &other) const {
    return !(*this < other || *this == other);
}

bool Bigfloat::operator<=(const Bigfloat &other) const {
    return *this < other || *this == other;
}

bool Bigfloat::operator>=(const Bigfloat &other) const {
    return *this > other || *this == other;
}

std::ostream &operator<<(std::ostream &os, const Bigfloat &bigfloat) {
    os << bigfloat.to_string();
    return os;
}

std::istream &operator>>(std::istream &is, Bigfloat &bigfloat) {
    std::string number;
    is >> number;
    bigfloat = Bigfloat(number, bigfloat.precision());
    return is;
}

Bigfloat operator ""_bf(const char *number, size_t size) {
    return Bigfloat(std::string(number, size));
}

#include "Bigfloat.h"

Bigfloat::Bigfloat(Bigint number, uint8_t precision) {
    _number = number;
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
        while (fractional_part.back() == '0') {
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
#include <iostream>
#include "Bigfloat.h"
#include <chrono>

const int PRECISION = 101;

Bigfloat calculate() {
    Bigfloat pi("0", PRECISION);

    uint8_t k = 0;
    Bigfloat degree_of_16 = Bigfloat("1", PRECISION);
    Bigfloat cur_8k_value = Bigfloat("0", PRECISION);
    while (true) {
        Bigfloat a1 = Bigfloat("4", PRECISION) / (cur_8k_value + Bigfloat("1", PRECISION));
        Bigfloat a2 = Bigfloat("2", PRECISION) / (cur_8k_value + Bigfloat("4", PRECISION));
        Bigfloat a3 = Bigfloat("1", PRECISION) / (cur_8k_value + Bigfloat("5", PRECISION));
        Bigfloat a4 = Bigfloat("1", PRECISION) / (cur_8k_value + Bigfloat("6", PRECISION));

        Bigfloat sum = (a1 - a2 - a3 - a4) / degree_of_16;

        if (sum > Bigfloat("0", PRECISION)) {
            pi += sum;
            ++k;

            cur_8k_value += Bigfloat("8", PRECISION);
            degree_of_16 *= Bigfloat("16", PRECISION);
        } else {
            break;
        }
    }
    return pi;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Bigfloat pi = calculate();
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "First " << PRECISION << " of pi after decimal point is: " << pi << "\n";
    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}

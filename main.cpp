#include <iostream>
#include "Bigfloat.h"
#include <chrono>

Bigfloat calculate(int precision) {
    Bigfloat pi("0", precision);

    uint8_t k = 0;
    Bigfloat degree_of_16 = Bigfloat("1", precision);
    Bigfloat cur_8k_value = Bigfloat("0", precision);
    while (true) {
        Bigfloat a1 = Bigfloat("4", precision) / (cur_8k_value + Bigfloat("1", precision));
        Bigfloat a2 = Bigfloat("2", precision) / (cur_8k_value + Bigfloat("4", precision));
        Bigfloat a3 = Bigfloat("1", precision) / (cur_8k_value + Bigfloat("5", precision));
        Bigfloat a4 = Bigfloat("1", precision) / (cur_8k_value + Bigfloat("6", precision));

        Bigfloat sum = (a1 - a2 - a3 - a4) / degree_of_16;

        if (sum > Bigfloat("0", precision)) {
            pi += sum;
            ++k;

            cur_8k_value += Bigfloat("8", precision);
            degree_of_16 *= Bigfloat("16", precision);
        } else {
            break;
        }
    }
    return pi;
}

int main() {
    int precision;
    std::cin >> precision;

    auto start = std::chrono::high_resolution_clock::now();
    Bigfloat pi = calculate(precision);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "First " << precision << " of pi after decimal point is: " << pi << "\n";
    std::cout << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << "ms\n";
}

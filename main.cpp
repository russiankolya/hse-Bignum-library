#include <iostream>
#include "Bigint.h"

int main() {
    Bigint a(123);
    Bigint b(456);

    std::cout << a + b << "\n";
}

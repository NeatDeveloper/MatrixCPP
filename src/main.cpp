#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int>
        matrix_b({
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        }),
        matrix_a({
            { 10, 11, 12 },
            { 13, 14, 15 },
            { 16, 17, 18 }
        });

    std::cout << matrix_a + matrix_b;
    std::cout << matrix_a - matrix_b;
    std::cout << matrix_a * matrix_b;
    std::cout << matrix_a / matrix_b;
    std::cout << matrix_a % matrix_b;

    return 0;
}

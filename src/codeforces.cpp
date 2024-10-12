#include <iostream>
#include <vector>
#include <limits>

// Нормальная реализация логики по ссылке: https://github.com/NeatDeveloper/MatrixCPP.git

class Matrix {
    public:
        std::vector<std::vector<int>> instance;

        std::size_t rows_count;
        std::size_t columns_count;

        Matrix(size_t size): rows_count(size), columns_count(size), instance(size, std::vector<int>(size, 1)) {
            for (size_t i = 1; i < rows_count; ++i)
                for (size_t j = 1; j < columns_count; ++j) {
                    instance[i][j] = instance[i][j - 1] + instance[i - 1][j];
                }
        };

        int max() {
            int max = std::numeric_limits<int>::min();

            for (const auto& row : instance)
                for (int value : row)
                    if (value > max) max = value;

            return max;
        }

        friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
            for (size_t i = 0; i < matrix.rows_count; ++i)
                for (size_t j = 0; j < matrix.columns_count; ++j) is >> matrix.instance[i][j];

            return is;
        };

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
            for (size_t i = 0; i < matrix.rows_count; ++i) {
                for (size_t j = 0; j < matrix.columns_count; ++j) os << matrix.instance[i][j] << " ";

                os << '\n';
            }

            return os;
        }
};

int main() {
    int size;

    std::cin >> size;

    Matrix matrix(size);

    std::cout << matrix.max() << '\n';

    return 0;
}

#include "Matrix.h"

template<typename Y>
Matrix<Y>::Matrix(const std::vector<std::vector<Y>>& matrix)
    : instance(matrix), rows_count(matrix.size()), columns_count(matrix[0].size()) {
    for (const auto& row : matrix)
        if (row.size() != columns_count) throw std::invalid_argument("Некорректные размеры матрицы");
}

// Метод для вывода матрицы
template<typename Y>
void Matrix<Y>::draw() const {
    for (const auto& row : instance) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Получение элемента матрицы
template<typename Y>
Y Matrix<Y>::get_elem(size_t row, size_t column) const {
    if (row >= rows_count || column >= columns_count) throw std::out_of_range("Индекс выходит за пределы матрицы");

    return instance[row][column];
}

// Установка элемента матрицы
template<typename Y>
bool Matrix<Y>::set_elem(size_t row, size_t column, Y value) {
    // if (row >= rows || col >= cols) throw std::out_of_range("Индекс за пределами матрицы");
    if (row >= rows_count || column >= columns_count) return false;

    instance[row][column] = value;

    return true;
}


template<typename Y>
std::ostream& operator<<(std::ostream& os, const Matrix<Y>& matrix) {
    for (size_t i = 0; i < matrix.rows_count; ++i) {
        std::cout << "| ";
        for (size_t j = 0; j < matrix.columns_count; ++j) {
            os << matrix.instance[i][j] << " ";
        }
        os << '|' << std::endl;
    }
    return os;
}

template<typename Y>
Matrix<Y> Matrix<Y>::T() const {
    std::vector<std::vector<Y>> transposed(columns_count, std::vector<Y>(rows_count));

    for (size_t i = 0; i < rows_count; ++i)
        for (size_t j = 0; j < columns_count; ++j) transposed[j][i] = instance[i][j];

    return Matrix<Y>(transposed);
}

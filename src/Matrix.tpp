#include "Matrix.h"

template<typename Y>
Matrix<Y>::Matrix(const std::vector<std::vector<Y>>& matrix):
instance(matrix), rows_count(matrix.size()), columns_count(matrix[0].size()) { }

template<typename Y>
Matrix<Y>::Matrix(size_t rows, size_t columns, size_t default_value):
rows_count(rows), columns_count(columns), instance(rows, std::vector<Y>(columns, default_value)) { }

template<typename Y>
Matrix<Y>::Matrix(size_t size, size_t default_value):
rows_count(size), columns_count(size), instance(size, std::vector<Y>(size, default_value)) {
    for (size_t i = 1; i < rows_count; ++i)
        for (size_t j = 1; j < columns_count; ++j) {
            instance[i][j] = instance[i][j - 1] + instance[i - 1][j];
        }
}

template<typename Y>
Y Matrix<Y>::max() {
    Y max = std::numeric_limits<Y>::min();

    for (const auto& row : instance)
        for (int value : row)
            if (value > max) max = value;

    return max;
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
    if (row >= rows_count || column >= columns_count) return false;

    instance[row][column] = value;

    return true;
}


template<typename Y>
Matrix<Y> Matrix<Y>::T() const {
    std::vector<std::vector<Y>> transposed(columns_count, std::vector<Y>(rows_count));

    for (size_t i = 0; i < rows_count; ++i)
        for (size_t j = 0; j < columns_count; ++j) transposed[j][i] = instance[i][j];

    return Matrix<Y>(transposed);
}


template<typename Y>
Y Matrix<Y>::sum_above_main_diagonal() {
    if (rows_count != columns_count) throw std::invalid_argument("Матрица должна быть квадратной для вычисления суммы над главной диагональю");

    Y sum = 0;

    for (int i = 0; i < rows_count; ++i)
        for (int j = i; j < columns_count; ++j)
            sum += instance[i][j];

    return sum;
}

// Метод для нахождения суммы элементов над побочной диагональю
template<typename Y>
Y Matrix<Y>::sum_above_side_diagonal() {
    if (rows_count != columns_count) throw std::invalid_argument("Матрица должна быть квадратной для вычисления суммы над побочной диагональю");

    Y sum = 0;

    for (size_t i = 0; i < rows_count; i++)
        for (size_t j = 0; j < columns_count - i - 1; j++)
            sum += instance[i][j];

    return sum;
}

template<typename Y>
Y Matrix<Y>::sum_below_main_diagonal() {
    if (rows_count != columns_count) throw std::invalid_argument("Матрица должна быть квадратной для вычисления суммы под главной диагональю");

    Y sum = 0;

    for (size_t i = 1; i < rows_count; ++i)
        for (size_t j = 0; j < i; ++j) sum += instance[i][j];

    return sum;
}

template<typename Y>
Y Matrix<Y>::sum_below_side_diagonal() {
    if (rows_count != columns_count) throw std::invalid_argument("Матрица должна быть квадратной для вычисления суммы под побочной диагональю");

    Y sum = 0;

    for (size_t i = 0; i < rows_count; ++i)
        for (size_t j = 0; j < columns_count; ++j)
            if (i + j >= rows_count - 1) sum += instance[i][j];

    return sum;
}

template<typename Y>
bool Matrix<Y>::is_cute() {
    for (int i = 0; i < rows_count - 1; ++i) {
        for (int j = 0; j < columns_count - 1; ++j) {
            int sum = instance[i][j] + instance[i][j + 1] + instance[i + 1][j] + instance[i + 1][j + 1];

            if (sum == 0 || sum == 4) return false;
        }
    }

    return true;
}

// Перегрузки

// Оператор <<
template<typename Y>
std::ostream& operator<<(std::ostream& os, const Matrix<Y>& matrix) {

    for (size_t i = 0; i < matrix.rows_count; ++i) {
        for (size_t j = 0; j < matrix.columns_count; ++j) os << matrix.instance[i][j] << " ";

        os << '\n';
    }

    return os;
}

// Оператор >>
template<typename Y>
std::istream& operator>>(std::istream& is, Matrix<Y>& matrix) {
    for (size_t i = 0; i < matrix.rows_count; ++i)
        for (size_t j = 0; j < matrix.columns_count; ++j) is >> matrix.instance[i][j];

    return is;
}



template<typename Y>
Matrix<Y> Matrix<Y>::operator+(const Matrix<Y>& other) const {
    if(
        rows_count != other.rows_count ||
        columns_count != other.columns_count
    ) throw std::invalid_argument("Матрицы должны быть одинакового размера");

    Matrix<Y> sum(rows_count, columns_count, 1);

    for(int i = 0; i < rows_count; i++)
        for(int j = 0; j < columns_count; j++)
            sum.instance[i][j] = instance[i][j] + other.instance[i][j];

    return sum;
}

template<typename Y>
Matrix<Y> Matrix<Y>::operator-(const Matrix<Y>& other) const {
    if(
        rows_count != other.rows_count ||
        columns_count != other.columns_count
    ) throw std::invalid_argument("Матрицы должны быть одинакового размера");

    Matrix<Y> difference(rows_count, columns_count, 1);

    for(int i = 0; i < rows_count; i++)
        for(int j = 0; j < columns_count; j++)
            difference.instance[i][j] = instance[i][j] - other.instance[i][j];

    return difference;
}

template<typename Y>
Matrix<Y> Matrix<Y>::operator*(const Matrix<Y>& other) const {
    if(
        rows_count != other.rows_count ||
        columns_count != other.columns_count
    ) throw std::invalid_argument("Матрицы должны быть одинакового размера");

    Matrix<Y> composition(rows_count, columns_count, 1);

    for(int i = 0; i < rows_count; i++)
        for(int j = 0; j < columns_count; j++)
            composition.instance[i][j] = instance[i][j] * other.instance[i][j];

    return composition;
}

template<typename Y>
Matrix<Y> Matrix<Y>::operator/(const Matrix<Y>& other) const {
    if(
        rows_count != other.rows_count ||
        columns_count != other.columns_count
    ) throw std::invalid_argument("Матрицы должны быть одинакового размера");

    Matrix<Y> quotien(rows_count, columns_count, 1);

    for(int i = 0; i < rows_count; i++)
        for(int j = 0; j < columns_count; j++) {
            if(other.instance[i][j] == 0) throw std::invalid_argument("На ноль делить нельзя");

            quotien.instance[i][j] = instance[i][j] / other.instance[i][j];
        }

    return quotien;
}

template<typename Y>
Matrix<Y> Matrix<Y>::operator%(const Matrix<Y>& other) const {
    if(
        rows_count != other.rows_count ||
        columns_count != other.columns_count
    ) throw std::invalid_argument("Матрицы должны быть одинакового размера");

    Matrix<Y> quotien(rows_count, columns_count, 1);

    for(int i = 0; i < rows_count; i++)
        for(int j = 0; j < columns_count; j++) {
            if(other.instance[i][j] == 0) throw std::invalid_argument("На ноль делить нельзя");

            quotien.instance[i][j] = instance[i][j] % other.instance[i][j];
        }

    return quotien;
}

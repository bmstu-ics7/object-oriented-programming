#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <math.h>

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(int n);
    Matrix(int n, int m);
    ~Matrix();

    Matrix(const Matrix<T>& copied);
    Matrix(Matrix<T>&& copied);
    Matrix<T>& operator=(const Matrix<T>& copied);
    Matrix<T>& operator=(Matrix<T>&& copied);

    int rows();
    int columns();
    int rows() const;
    int columns() const;

    operator bool() const;

    const T& get(int i, int j) const;
    T& get(int i, int j);
    const T& operator()(int i, int j) const;
    T& operator()(int i, int j);

    Matrix<T>& addColumn();
    Matrix<T>& addRow();

    Matrix<T> addition(const Matrix<T>& mat);
    Matrix<T>& additionSelf(const Matrix<T>& mat);
    Matrix<T> operator+(const Matrix<T>& mat);
    Matrix<T>& operator+=(const Matrix<T>& mat);

    Matrix<T> subtraction(const Matrix<T>& mat);
    Matrix<T>& subtractionSelf(const Matrix<T>& mat);
    Matrix<T> operator-(const Matrix<T>& mat);
    Matrix<T>& operator-=(const Matrix<T>& mat);

    Matrix<T> multiplication(const Matrix<T>& mat);
    Matrix<T>& multiplicationSelf(const Matrix<T>& mat);
    Matrix<T> operator*(const Matrix<T>& mat);
    Matrix<T>& operator*=(const Matrix<T>& mat);

    Matrix<T> addition(const T& element);
    Matrix<T>& additionSelf(const T& element);
    Matrix<T> operator+(const T& element);
    Matrix<T>& operator+=(const T& element);

    Matrix<T> subtraction(const T& element);
    Matrix<T>& subtractionSelf(const T& element);
    Matrix<T> operator-(const T& element);
    Matrix<T>& operator-=(const T& element);

    Matrix<T> multiplication(const T& element);
    Matrix<T>& multiplicationSelf(const T& element);
    Matrix<T> operator*(const T& element);
    Matrix<T>& operator*=(const T& element);

    Matrix<T> inverse();
    Matrix<T> operator-();
    Matrix<T>& inverseSelf();

    Matrix<T> transposition();
    Matrix<T>& transpositionSelf();

    T determinant();

private:
    int n;
    int m;
    int allocateLen;
    std::unique_ptr<T[]> data;
    Matrix<T> getMatrixWithoutRowAndCol(int row, int col);
};

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix)
{
    int n, m;
    in >> n >> m;
    matrix = Matrix<T>(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            in >> matrix(i, j);

    return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.columns(); ++j) {
            out << matrix(i, j) << '\t';
        }
        out << std::endl;
    }

    return out;
}

template <typename T>
Matrix<T>::Matrix() : Matrix(0) {}

template <typename T>
Matrix<T>::Matrix(int n) : Matrix(n, n) {}

template <typename T>
Matrix<T>::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    allocateLen = n * m;
    data.reset(new T[allocateLen]);

    for (int i = 0; i < allocateLen; ++i)
        data[i] = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
    n = 0;
    m = 0;
    data = nullptr;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& copied)
{
    n = copied.n;
    m = copied.m;
    allocateLen = copied.allocateLen;
    data.reset(new T[allocateLen]);
    for (int i = 0; i < allocateLen; ++i)
        data[i] = copied.data[i];
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& copied)
{
    n = copied.n;
    m = copied.m;
    allocateLen = copied.allocateLen;
    data = copied.data;
    copied.data = nullptr;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& copied)
{
    n = copied.n;
    m = copied.m;
    allocateLen = copied.allocateLen;
    data = nullptr;
    data.reset(new T[allocateLen]);
    for (int i = 0; i < allocateLen; ++i)
        data[i] = copied.data[i];

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& copied)
{
    if (data) {
        data = nullptr;
    }

    allocateLen = copied.allocateLen;
    n = copied.n;
    m = copied.m;
    data = copied.data;
    copied.data = nullptr;
    return *this;
}

template <typename T>
int Matrix<T>::rows()
{
    return n;
}

template <typename T>
int Matrix<T>::columns()
{
    return m;
}

template <typename T>
int Matrix<T>::rows() const
{
    return n;
}

template <typename T>
int Matrix<T>::columns() const
{
    return m;
}

template <typename T>
Matrix<T>::operator bool() const
{
    return n == 0 || m == 0;
}

template <typename T>
T& Matrix<T>::get(int i, int j)
{
    return data[i * m + j];
}

template <typename T>
const T& Matrix<T>::get(int i, int j) const
{
    return data[i * m + j];
}

template <typename T>
T& Matrix<T>::operator()(int i, int j)
{
    return get(i, j);
}

template <typename T>
const T& Matrix<T>::operator()(int i, int j) const
{
    return get(i, j);
}

template <typename T>
Matrix<T>& Matrix<T>::addColumn()
{
    Matrix<T> mat(n, m + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            mat(i, j) = get(i, j);
    *this = mat;
    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::addRow()
{
    Matrix<T> mat(n + 1, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            mat(i, j) = get(i, j);
    *this = mat;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::addition(const Matrix<T>& mat)
{
    Matrix<T> res(n, m);

    if (n != mat.n || m != mat.m)
        return Matrix<T>();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res(i, j) = this->get(i, j) + mat(i, j);

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::additionSelf(const Matrix<T>& mat)
{
    if (n != mat.n || m != mat.m)
        return *this;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->get(i, j) += mat(i, j);

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& mat)
{
    return addition(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& mat)
{
    return additionSelf(mat);
}

template <typename T>
Matrix<T> Matrix<T>::subtraction(const Matrix<T>& mat)
{
    Matrix<T> res(n, m);

    if (n != mat.n || m != mat.m)
        return Matrix<T>();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res(i, j) = this->get(i, j) - mat(i, j);

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::subtractionSelf(const Matrix<T>& mat)
{
    if (n != mat.n || m != mat.m)
        return *this;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->get(i, j) -= mat(i, j);

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& mat)
{
    return subtraction(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& mat)
{
    return subtractionSelf(mat);
}

template <typename T>
Matrix<T> Matrix<T>::multiplication(const Matrix<T>& mat)
{
    Matrix<T> res(n, mat.m);

    if (m != mat.n)
        return Matrix<T>();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < mat.m; ++j)
            for (int k = 0; k < m; ++k)
                res(i, j) += this->get(i, k) * mat(k, j);

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::multiplicationSelf(const Matrix<T>& mat)
{
    Matrix<T> res(n, mat.m);

    if (m != mat.n)
        return *this;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < mat.m; ++j)
            for (int k = 0; k < m; ++k)
                res(i, j) += this->get(i, k) * mat(k, j);

    *this = res;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& mat)
{
    return multiplication(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& mat)
{
    return multiplicationSelf(mat);
}

template <typename T>
Matrix<T> Matrix<T>::addition(const T& element)
{
    Matrix<T> res(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res(i, j) = this->get(i, j) + element;

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::additionSelf(const T& element)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->get(i, j) += element;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const T& element)
{
    return addition(element);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const T& element)
{
    return additionSelf(element);
}

template <typename T>
Matrix<T> Matrix<T>::subtraction(const T& element)
{
    Matrix<T> res(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res(i, j) = this->get(i, j) - element;

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::subtractionSelf(const T& element)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->get(i, j) -= element;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T& element)
{
    return subtraction(element);
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const T& element)
{
    return subtractionSelf(element);
}

template <typename T>
Matrix<T> Matrix<T>::multiplication(const T& element)
{
    Matrix<T> res(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
                res(i, j) = this->get(i, j) * element;

    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::multiplicationSelf(const T& element)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
                get(i, j) *= element;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& element)
{
    return multiplication(element);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T& element)
{
    return multiplicationSelf(element);
}

template <typename T>
Matrix<T> Matrix<T>::inverse()
{
    if (n != m)
        return Matrix<T>();

    int size = n;
    Matrix<T> ed(size);
    Matrix<T> mat = *this;

    for (int i = 0; i < size; ++i)
        ed(i, i) = 1;

    for (int row = 0; row < size; ++row) {
        if (mat(row, row) == 0) {
            bool change = false;
            for (int i = row + 1; i < size; ++i) {
                if (mat(i, row) != 0) {
                    for (int j = 0; j < size; ++j) {
                        std::swap(mat(row, j), mat(i, j));
                        std::swap(ed(row, j), ed(i, j));
                    }
                    change = true;
                    break;
                }
            }

            if (!change)
                return Matrix<T>();
        }

        T v = mat(row, row);
        for (int j = 0; j < size; ++j) {
            mat(row, j) /= v;
            ed(row, j) /= v;
        }

        for (int i = row + 1; i < size; ++i) {
            T v = mat(i, row);
            for (int j = 0; j < size; ++j) {
                mat(i, j) -= v * mat(row, j);
                ed(i, j) -= v * ed(row, j);
            }
        }
    }

    for (int row = size - 1; row > 0; --row) {
        for (int i = row - 1; i >= 0; --i) {
            T v = mat(i, row);
            for (int j = 0; j < size; ++j) {
                mat(i, j) -= v * mat(row, j);
                ed(i, j) -= v * ed(row, j);
            }
        }
    }

    return Matrix<T>(ed);
}

template <typename T>
Matrix<T> Matrix<T>::operator-()
{
    return inverse();
}

template <typename T>
Matrix<T>& Matrix<T>::inverseSelf()
{
    *this = inverse();
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::transposition()
{
    Matrix<T> res(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res(i, j) = get(j, i);
        }
    }
    return Matrix<T>(res);
}

template <typename T>
Matrix<T>& Matrix<T>::transpositionSelf()
{
    *this = transposition();
    return *this;
}

template <typename T>
T Matrix<T>::determinant()
{
    T result = 0;

    if (n != m)
        return result;

    if (n == 2)
        return get(0, 0) * get(1, 1) - get(0, 1) * get(1, 0);

    for (int i = 0; i < n; ++i) {
        result += pow(-1, i) * get(0, i) * 
                  getMatrixWithoutRowAndCol(0, i).determinant();
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::getMatrixWithoutRowAndCol(int row, int col)
{
    Matrix<T> mat(n - 1, m - 1);
    
    for (int i = 0; i < n; ++i) {
        if (i == row)
            continue;
        for (int j = 0; j < m; ++j) {
            if (j == col)
                continue;
            int i1 = i < row ? i : i - 1;
            int j1 = j < col ? j : j - 1;
            mat(i1, j1) = get(i, j);
        }
    }

    return Matrix<T>(mat);
}

#endif // MATRIX_H


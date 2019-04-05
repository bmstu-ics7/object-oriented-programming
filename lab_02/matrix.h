#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

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

    const T& get(int i, int j) const;
    T& get(int i, int j);
    const T& operator()(int i, int j) const;
    T& operator()(int i, int j);

    Matrix<T>& addition(const Matrix<T>& mat);
    Matrix<T>& additionSelf(const Matrix<T>& mat);
    Matrix<T>& operator+(const Matrix<T>& mat);
    Matrix<T>& operator+=(const Matrix<T>& mat);

    Matrix<T>& multiplication(const Matrix<T>& mat);
    Matrix<T>& multiplicationSelf(const Matrix<T>& mat);
    Matrix<T>& operator*(const Matrix<T>& mat);
    Matrix<T>& operator*=(const Matrix<T>& mat);

    // std::istream& operator>>(std::istream& in, Matrix<T>& matrix);
    // std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

private:
    int n;
    int m;
    int allocateLen;
    T* data;
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
    data = new T[allocateLen];

    for (int i = 0; i < allocateLen; ++i)
        data[i] = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
    if (data)
        delete[] data;
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
    data = new T[allocateLen];
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
    if (data) {
        delete[] data;
        data = nullptr;
    }

    n = copied.n;
    m = copied.m;
    allocateLen = copied.allocateLen;
    data = new T[copied.allocateLen];
    for (int i = 0; i < allocateLen; ++i)
        data[i] = copied.data[i];

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& copied)
{
    if (data) {
        delete[] data;
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
Matrix<T>& Matrix<T>::addition(const Matrix<T>& mat)
{
    static Matrix<T> res(n, m);

    if (n != mat.n || m != mat.m)
        return res;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res(i, j) = this->get(i, j) + mat(i, j);

    return res;
}

template <typename T>
Matrix<T>& Matrix<T>::additionSelf(const Matrix<T>& mat)
{
    static Matrix<T> res(n, m);

    if (n != mat.n || m != mat.m)
        return *this;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            this->get(i, j) += mat(i, j);

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& mat)
{
    return addition(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& mat)
{
    return additionSelf(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::multiplication(const Matrix<T>& mat)
{
    static Matrix<T> res(n, mat.m);

    if (m != mat.n)
        return res;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < mat.m; ++j)
            for (int k = 0; k < m; ++k)
                res(i, j) += this->get(i, k) * mat(k, j);

    return res;
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
Matrix<T>& Matrix<T>::operator*(const Matrix<T>& mat)
{
    return multiplication(mat);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& mat)
{
    return multiplicationSelf(mat);
}

#endif // MATRIX_H

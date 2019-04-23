#ifndef __ITERATOR_H
#define __ITERATOR_H

#include <iterator>
#include "exception.hpp"

template<typename T>
class Matrix;

template<typename T>
class MatrixIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Matrix<T>;

public:
    MatrixIterator() {};
    MatrixIterator(std::shared_ptr<T> data, int i, int len) : data(data), index(i), len(len) {};

    bool operator!=(MatrixIterator const& other) const;
    bool operator==(MatrixIterator const& other) const;
    MatrixIterator<T>& operator++();
    MatrixIterator<T> operator++(int);
    MatrixIterator<T>& operator--();
    MatrixIterator<T> operator--(int);
    T& operator*();
    T* operator->();
    const T& operator*() const;
    const T* operator->() const;
    operator bool() const;
private:
    std::weak_ptr<T> data;
    int index;
    int len;
};

template<typename T>
class ConstMatrixIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Matrix<T>;

public:
    ConstMatrixIterator() {};
    ConstMatrixIterator(std::shared_ptr<T> data, int i, int len) : data(data), index(i), len(len) {};

    bool operator!=(ConstMatrixIterator const& other) const;
    bool operator==(ConstMatrixIterator const& other) const;
    ConstMatrixIterator<T>& operator++();
    ConstMatrixIterator<T> operator++(int);
    ConstMatrixIterator<T>& operator--();
    ConstMatrixIterator<T> operator--(int);
    const T& operator*() const;
    const T* operator->() const;
    operator bool() const;
private:
    std::weak_ptr<T> data;
    int index;
    int len;
};

#endif // __ITERATOR_H

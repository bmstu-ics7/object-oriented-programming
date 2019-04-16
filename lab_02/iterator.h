#ifndef __ITERATOR_H
#define __ITERATOR_H

#include <iterator>

template<typename T>
class Matrix;

template<typename T>
class MatrixIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Matrix<T>;

public:
    MatrixIterator() {};
    MatrixIterator(std::shared_ptr<T> data, int i) : data(data), index(i) {};

    bool operator!=(MatrixIterator const& other) const;
    bool operator==(MatrixIterator const& other) const;
    MatrixIterator<T>& operator++();
    MatrixIterator<T> operator++(int);
    MatrixIterator<T>& operator--();
    MatrixIterator<T> operator--(int);
    T& operator*() const;
    T* operator->() const;
private:
    std::shared_ptr<T> data;
    int index;
};

template<typename T>
class ConstMatrixIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Matrix<T>;

public:
    ConstMatrixIterator() {};
    ConstMatrixIterator(std::shared_ptr<T> data, int i) : data(data), index(i) {};

    bool operator!=(ConstMatrixIterator const& other) const;
    bool operator==(ConstMatrixIterator const& other) const;
    ConstMatrixIterator<T>& operator++();
    ConstMatrixIterator<T> operator++(int);
    ConstMatrixIterator<T>& operator--();
    ConstMatrixIterator<T> operator--(int);
    const T& operator*() const;
    const T* operator->() const;
private:
    std::shared_ptr<T> data;
    int index;
};

template <typename T>
bool MatrixIterator<T>::operator!=(MatrixIterator const& other) const
{
    return index != other.index;
}

template <typename T>
bool MatrixIterator<T>::operator==(MatrixIterator const& other) const
{
    return index == other.index;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator++()
{
    index++;
    return *this;
}

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator++(int)
{
    index++;
    return *this;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator--()
{
    index--;
    return *this;
}

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator--(int)
{
    index--;
    return *this;
}

template <typename T>
T& MatrixIterator<T>::operator*() const
{
    return data.get()[index];
}

template <typename T>
T* MatrixIterator<T>::operator->() const
{
    return data.get() + index;
}

template <typename T>
bool ConstMatrixIterator<T>::operator!=(ConstMatrixIterator const& other) const
{
    return index != other.index;
}

template <typename T>
bool ConstMatrixIterator<T>::operator==(ConstMatrixIterator const& other) const
{
    return index == other.index;
}

template <typename T>
ConstMatrixIterator<T>& ConstMatrixIterator<T>::operator++()
{
    index++;
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator++(int)
{
    index++;
    return *this;
}

template <typename T>
ConstMatrixIterator<T>& ConstMatrixIterator<T>::operator--()
{
    index--;
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator--(int)
{
    index--;
    return *this;
}

template <typename T>
const T& ConstMatrixIterator<T>::operator*() const
{
    return data.get()[index];
}

template <typename T>
const T* ConstMatrixIterator<T>::operator->() const
{
    return data.get() + index;
}


#endif // __ITERATOR_H

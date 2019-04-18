#ifndef __ITERATOR_HPP
#define __ITERATOR_HPP

#include "iterator.h"

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
    return data.lock().get()[index];
}

template <typename T>
T* MatrixIterator<T>::operator->() const
{
    return data.lock().get() + index;
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
    return data.lock().get()[index];
}

template <typename T>
const T* ConstMatrixIterator<T>::operator->() const
{
    return data.lock().get() + index;
}


#endif // __ITERATOR_HPP

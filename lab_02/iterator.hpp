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
    if (++index > len) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator++(int)
{
    if (++index > len) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
MatrixIterator<T>& MatrixIterator<T>::operator--()
{
    if (--index < 0) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
MatrixIterator<T> MatrixIterator<T>::operator--(int)
{
    if (--index < 0) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
T& MatrixIterator<T>::operator*()
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get()[index];
}

template <typename T>
T* MatrixIterator<T>::operator->()
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get() + index;
}
template <typename T>
const T& MatrixIterator<T>::operator*() const
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get()[index];
}

template <typename T>
const T* MatrixIterator<T>::operator->() const
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get() + index;
}

template <typename T>
MatrixIterator<T>::operator bool() const
{
    return !(data.expired() || data.lock() == nullptr);
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
    if (++index > len) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator++(int)
{
    if (++index > len) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
ConstMatrixIterator<T>& ConstMatrixIterator<T>::operator--()
{
    if (--index < 0) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
ConstMatrixIterator<T> ConstMatrixIterator<T>::operator--(int)
{
    if (--index < 0) {
        throw IteratorException("Iterator out of range");
    }
    return *this;
}

template <typename T>
const T& ConstMatrixIterator<T>::operator*() const
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get()[index];
}

template <typename T>
const T* ConstMatrixIterator<T>::operator->() const
{
    if (data.expired() || data.lock() == nullptr) {
        throw IteratorException("Object in iterator was deleted");
    }
    return data.lock().get() + index;
}

template <typename T>
ConstMatrixIterator<T>::operator bool() const
{
    return !data.expired();
}

#endif // __ITERATOR_HPP

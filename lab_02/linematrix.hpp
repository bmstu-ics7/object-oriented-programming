#ifndef __LINEMATRIX_HPP
#define __LINEMATRIX_HPP

#include "linematrix.h"

template <typename T>
T& LineMatrix<T>::operator[](size_t i)
{
    if (i >= len) {
        throw IndexException("Index out of range");
    }
    return line[i];
}

template <typename T>
const T& LineMatrix<T>::operator[](size_t i) const
{
    if (i >= len) {
        throw IndexException("Index out of range");
    }
    return line[i];
}

#endif //__LINEMATRIX_HPP

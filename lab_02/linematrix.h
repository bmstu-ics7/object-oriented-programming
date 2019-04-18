#ifndef __LINEMATRIX_H
#define __LINEMATRIX_H

#include <sys/types.h>

#include "exception.h"

template <typename T>
class LineMatrix
{
public:
    LineMatrix(T* line, int len) : line(line), len(len) {}
    T& operator[](size_t i);
    const T& operator[](size_t i) const;
private:
    T* line;
    int len;
};

#endif //__LINEMATRIX_H

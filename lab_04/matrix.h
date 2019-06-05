#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <vector>

class Matrix
{
public:
    Matrix();
    Matrix(size_t size);
    Matrix(std::vector< std::vector< double > > data);

private:
    std::vector< std::vector< double > > data;
    const size_t size;
};

#endif // MATRIX_H

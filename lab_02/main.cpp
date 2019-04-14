#include <iostream>

#include "matrix.h"

using namespace std;

int main()
{
    Matrix<int> m(10);
    for (int i = 0; i < m.rows(); ++i)
        for (int j = 0; j < m.columns(); ++j)
            m(i, j) = (i + 1) * (j + 1);
    cout << m << endl;

    Matrix<int> m2(10);
    for (int i = 0; i < m2.rows(); ++i)
        for (int j = 0; j < m2.columns(); ++j)
            m2(i, j) = (i + 1) - (j + 1);
    cout << m2 << endl;

    cout << m + m2 << endl;

    m += m2;
    cout << m << endl;

    Matrix<int> m3(3, 2);
    Matrix<int> m4(2, 4);

    for (int i = 0; i < m3.rows(); ++i)
        for (int j = 0 ; j < m3.columns(); ++j)
            m3(i, j) = 1;
    
    for (int i = 0; i < m4.rows(); ++i)
        for (int j = 0 ; j < m4.columns(); ++j)
            m4(i, j) = 2;
    
    cout << m3 << endl << m4 << endl << m3 * m4 << endl;

    m3 *= m4;
    cout << m3 << endl;

    Matrix<double> d(3);

    d(0, 2) = 4;
    d(0, 1) = 2;
    d(1, 0) = 5;
    d(2, 0) = 1;
    d(2, 2) = 2;

    cout << d << endl;
    cout << -d << endl;

    cout << d + 5.0 << endl;
    cout << d - 5.0 << endl;
    cout << d * 5.0 << endl;
    //d.transpositionSelf();
    cout << d << endl;
    
    cout << d * -d << endl;
    
    Matrix<double> mat(10);
    for (int i = 0; i < mat.rows(); ++i)
        for (int j = 0; j < mat.columns(); ++j)
            mat(i, j) = rand() % 10;
        
    cout << mat << endl;
    cout << -mat << endl;
    cout << mat * -mat << endl;

    cout << d << endl;
    cout << d.determinant() << endl;

    return 0;
}

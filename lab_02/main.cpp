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

    Matrix<int> a;
    cin >> a;
    cout << a;

    return 0;
}

#include <iostream>

#include "matrix.hpp"

using namespace std;

int main()
{
    Matrix<int> m(10);
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.columns(); ++j) {
            m[i][j] = (i + 1) * (j + 1);
        }
    }
    cout << m << endl;

    Matrix<int> m2(10);
    for (int i = 0; i < m2.rows(); ++i)
        for (int j = 0; j < m2.columns(); ++j)
            m2[i][j] = (i + 1) - (j + 1);
    cout << m2 << endl;

    cout << m + m2 << endl;

    m += m2;
    cout << m << endl;

    Matrix<int> m3(3, 2);
    Matrix<int> m4(2, 4);

    for (int i = 0; i < m3.rows(); ++i)
        for (int j = 0 ; j < m3.columns(); ++j)
            m3[i][j] = 1;

    for (int i = 0; i < m4.rows(); ++i)
        for (int j = 0 ; j < m4.columns(); ++j)
            m4[i][j] = 2;

    cout << m3 << endl << m4 << endl << m3 * m4 << endl;

    m3 *= m4;
    cout << m3 << endl;

    Matrix<double> d(3);

    d(0, 0) = 0;
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
    cout << d << endl;

    cout << d * -d << endl;

    Matrix<double> mat(10);
    for (int i = 0; i < mat.rows(); ++i)
        for (int j = 0; j < mat.columns(); ++j)
            mat[i][j] = rand() % 10;

    cout << mat << endl;
    cout << -mat << endl;
    cout << mat * -mat << endl;

    cout << d << endl;
    cout << d.determinant() << endl;

    Matrix<int> init {{1, 2}, {2, 5, 1}, {1}};
    cout << init << endl;

    init[1][1] = 2;

    cout << 2 * init << endl;
    cout << 4 + init << endl;

    try {
        MatrixIterator<int> iter = init.begin();
        iter++;

        for (int el : init)
            cout << el << ' ';
        cout << endl;

        for (int el : m)
            cout << el << ' ';
        cout << endl;

        MatrixIterator<int> it = init.begin();
        while (true) it++;
    } catch(IteratorException& e) {
        cout << e.what() << endl;
    }

    MatrixIterator<int> it;

    {
        Matrix<int> g {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        it = g.begin();
        cout << bool(it) << endl;
    }

    try {
        cout << bool(it) << endl;
        *it;
    } catch(IteratorException& e) {
        cout << e.what() << endl;
    }

    try {
        init(100, 100) = 0;
    } catch(IndexException& e) {
        cout << e.what() << endl;
    }

    try {
        init /= 0;
    } catch(ArifmeticException& e) {
        cout << e.what() << endl;
    }

    Matrix<int> empty;
    try {
        empty *= 1;
    } catch(IndexException& e) {
        cout << e.what() << endl;
    }

    return 0;
}

#include "input.h"

bool input(int& number, QString str)
{
    bool key;
    number = str.toInt(&key);
    return key;
}

bool input(double& number, QString str)
{
    bool key;
    number = str.toDouble(&key);
    return key;
}

void split(Vector<QString>& vec, QString str)
{
    createVector(vec);
    QList<QString> list = str.split(" ");
    for (QString s : list) {
        append(vec, s);
    }
}

Error inputPoint(Point& p, QString str)
{
    Vector<QString> vec;
    split(vec, str);

    if (size(vec) < 3)
        return incorrectFile;

    int x = 0, y = 0,z = 0;

    if (input(x, get(vec, 0)) &&
        input(y, get(vec, 1)) &&
        input(z, get(vec, 2))) {
        destructVector(vec);
        p = createPoint(x, y, z);

        return success;
    }

    destructVector(vec);
    return incorrectFile;
}

Error inputEdge(Edge& edge, QString str)
{
    Vector<QString> vec;
    split(vec, str);

    if (size(vec) < 2)
        return incorrectFile;

    int n1 = 0, n2 = 0;

    if (input(n1, get(vec, 0)) &&
        input(n2, get(vec, 1))) {
        destructVector(vec);
        edge = createEdge(n1, n2);
        return success;
    }

    destructVector(vec);
    return incorrectFile;
}

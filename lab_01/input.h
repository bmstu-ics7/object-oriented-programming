#ifndef INPUT_H
#define INPUT_H

#include <QString>
#include <QList>

#include "vector.h"
#include "point.h"
#include "error.h"

bool input(int&, QString);
bool input(double&, QString);
void split(Vector<QString>&, QString);
Error inputPoint(Point&, QString);
Error inputTwo(int&, int&, QString);

#endif // INPUT_H

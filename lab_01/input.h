#ifndef INPUT_H
#define INPUT_H

#include <QString>
#include <QList>

#include "vector.h"
#include "point.h"
#include "error.h"
#include "edge.h"

bool input(int&, QString);
bool input(double&, QString);
void split(Vector<QString>&, QString);
Error inputPoint(Point&, QString);
Error inputEdge(Edge&, QString);

#endif // INPUT_H

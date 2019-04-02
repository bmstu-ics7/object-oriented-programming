#ifndef INPUT_H
#define INPUT_H

#include <QString>
#include <QList>

#include "vector.h"
#include "point.h"
#include "error.h"
#include "edge.h"

bool input(int& number, QString str);
bool input(double& number, QString str);
void split(Vector<QString>& vec, QString str);
Error inputPoint(Point& point, QString str);
Error inputEdge(Edge& edge, QString str);

#endif // INPUT_H

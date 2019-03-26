#ifndef STREAM_H
#define STREAM_H

#include "input.h"
#include "edge.h"
#include "point.h"
#include "vector.h"
#include "error.h"

Error inputPoints(QTextStream&, Vector<Point>&, Error);
Error inputEdges(QTextStream&, Vector<Edge>&, Error);
void outputPoints(QTextStream&, const Vector<Point>);
void outputEdges(QTextStream&, const Vector<Edge>);

#endif // STREAM_H

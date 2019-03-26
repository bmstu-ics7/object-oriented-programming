#ifndef STREAM_H
#define STREAM_H

#include "input.h"
#include "edge.h"
#include "point.h"
#include "vector.h"
#include "error.h"
#include "file.h"

Error inputPoints(Vector<Point>&, File&);
Error inputEdges(Vector<Edge>&, File&);
void outputPoints(File&, const Vector<Point>);
void outputEdges(File&, const Vector<Edge>);
Error inputPoint(Point&, File&);

#endif // STREAM_H

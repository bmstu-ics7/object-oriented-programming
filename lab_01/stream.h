#ifndef STREAM_H
#define STREAM_H

#include "input.h"
#include "edge.h"
#include "point.h"
#include "vector.h"
#include "error.h"
#include "file.h"

Error inputPoints(Vector<Point>& points, File& file);
Error inputEdges(Vector<Edge>& edges, File& file);
void outputPoints(File& file, const Vector<Point> points);
void outputEdges(File& file, const Vector<Edge> edges);
Error inputPoint(Point& point, File& file);

#endif // STREAM_H

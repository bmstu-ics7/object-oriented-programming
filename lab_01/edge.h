#ifndef EDGE_H
#define EDGE_H

#include "point.h"

struct Edge
{
    Point a;
    Point b;
};

Edge createEdge(Point, Point);
void drawEdge(Painter&, const Edge);
void offsetEdge(Edge&, int, int, int);
void scaleEdge(Edge&, const Point, double);
void rotateEdge(Edge&, const Point, int, int, int);
Point findCenterEdge(const Edge);

#endif // EDGE_H

#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include "vector.h"
/*
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
*/

struct Edge
{
    int i1;
    int i2;
};

Edge createEdge(int, int);
void drawEdge(Painter&, Edge, Vector<Point>);
int i1(const Edge);
int i2(const Edge);

#endif // EDGE_H

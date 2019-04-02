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

Edge createEdge(int i1, int i2);
void drawEdge(Painter& painter, Edge edge, Vector<Point> points);
int i1(const Edge edge);
int i2(const Edge edge);

#endif // EDGE_H

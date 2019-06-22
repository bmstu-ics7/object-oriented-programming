#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include "vector.h"

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

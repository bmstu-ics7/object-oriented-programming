#include "edge.h"

Edge createEdge(int i1, int i2)
{
    return {i1, i2};
}

void drawEdge(Painter& painter, Edge edge, Vector<Point> points)
{
    Point2D p1 = get2D(get(points, edge.i1));
    Point2D p2 = get2D(get(points, edge.i2));
    drawLine(painter, p1.x, p1.y, p2.x, p2.y);
}

int i1(const Edge edge)
{
    return edge.i1;
}

int i2(const Edge edge)
{
    return edge.i2;
}

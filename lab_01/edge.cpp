#include "edge.h"

Edge createEdge(Point a, Point b)
{
    return {a, b};
}

void drawEdge(Painter& painter, const Edge edge)
{
    drawPoint(painter, edge.a);
    drawPoint(painter, edge.b);

    painter.paint->setPen(QPen(Qt::black, 1));
    painter.paint->drawLine(painter.width  / 2 + get2D(edge.a).first,
                            painter.height / 2 - get2D(edge.a).second,
                            painter.width  / 2 + get2D(edge.b).first,
                            painter.height / 2 - get2D(edge.b).second);
}

void offsetEdge(Edge& edge, int dx, int dy, int dz)
{
    offsetPoint(edge.a, dx, dy, dz);
    offsetPoint(edge.b, dx, dy, dz);
}

void scaleEdge(Edge& edge, const Point center, double k)
{
    scalePoint(edge.a, center, k);
    scalePoint(edge.b, center, k);
}

void rotateEdge(Edge& edge, const Point center, int ax, int ay, int az)
{
    rotatePoint(edge.a, center, ax, ay, az);
    rotatePoint(edge.b, center, ax, ay, az);
}

Point findCenterEdge(const Edge edge)
{
    return findCenterPoints(edge.a, edge.b);
}

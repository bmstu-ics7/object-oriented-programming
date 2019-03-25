#include "edge.h"

Edge createEdge(int i1, int i2)
{
    return {i1, i2};
}

void drawEdge(Painter& painter, Edge edge, Vector<Point> points)
{
    QPainter* p = painter.paint;
    int w = painter.width;
    int h = painter.height;

    Point2D p1 = get2D(get(points, edge.i1));
    Point2D p2 = get2D(get(points, edge.i2));

    p->setPen(QPen(Qt::white, 1));
    p->drawLine(w / 2 + p1.x, h / 2 - p1.y, w / 2 + p2.x, h / 2 - p2.y);
}

int i1(const Edge edge)
{
    return edge.i1;
}

int i2(const Edge edge)
{
    return edge.i2;
}

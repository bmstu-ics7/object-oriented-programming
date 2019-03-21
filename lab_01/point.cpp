#include "point.h"

Point createPoint(int x, int y, int z)
{
    return {x, y, z};
}

void drawPoint(Painter& painter, const Point point)
{
    int x = get2D(point).first;
    int y = get2D(point).second;

    painter.paint->setPen(QPen(Qt::black, 1));
    painter.paint->setBrush(QBrush(Qt::black));

    painter.paint->drawEllipse(painter.width  / 2 + x - 2,
                               painter.height / 2 - y - 2,
                               4, 4);
}

void offsetPoint(Point& point, int dx, int dy, int dz)
{
    point.x += dx;
    point.y += dy;
    point.z += dz;
}

int scale(int x, int cx, double k)
{
    return int(cx + (x - cx) * k);
}

void scalePoint(Point& point, const Point center, double k)
{
    point.x = scale(point.x, center.x, k);
    point.y = scale(point.y, center.y, k);
    point.z = scale(point.z, center.z, k);
}

void rotatePoint(Point& point, const Point center, int angleX, int angleY, int angleZ)
{
    double ax = (angleX * M_PI) / 180.0;
    double ay = (angleY * M_PI) / 180.0;
    double az = (angleZ * M_PI) / 180.0;

    int cx = center.x;
    int cy = center.y;
    int cz = center.z;

    // around x
    Point p = point;
    point.y = int(cy + (p.y - cy) * cos(ax) + (p.z - cz) * sin(ax));
    point.z = int(cz - (p.y - cy) * sin(ax) + (p.z - cz) * cos(ax));

    // around y
    p = point;
    point.x = int(cx + (p.z - cz) * sin(ay) + (p.x - cx) * cos(ay));
    point.z = int(cz - (p.z - cz) * cos(ay) + (p.x - cx) * sin(ay));

    // around z
    p = point;
    point.x = int(cx + (p.x - cx) * cos(az) - (p.y - cy) * sin(az));
    point.y = int(cy + (p.x - cx) * sin(az) + (p.y - cy) * cos(az));
}

QPair <int, int> get2D(Point point)
{
    int x = int(point.x + 0.4 * point.z);
    int y = int(point.y + 0.4 * point.z);
    return QPair <int, int> (x, y);
}

Point findCenterPoints(const Point a, const Point b)
{
    int x = (a.x + b.x) / 2;
    int y = (a.y + b.y) / 2;
    int z = (a.z + b.z) / 2;
    return createPoint(x, y, z);
}

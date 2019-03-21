#include "point.h"

#include <QDebug>

Point createPoint(double x, double y, double z)
{
    return {x, y, z};
}

void drawPoint(Painter& painter, const Point point)
{
    int x = get2D(point).x;
    int y = get2D(point).y;

    painter.paint->setPen(QPen(Qt::white, 1));
    painter.paint->setBrush(QBrush(Qt::white));

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

int scale(double x, double cx, double k)
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

    double cx = center.x;
    double cy = center.y;
    double cz = center.z;
    cx = 0;
    cy = 0;
    cz = 0;

    // around x
    Point p = createPoint(point.x, point.y, point.z);
    point.y = cy + (p.y - cy) * cos(ax) + (p.z - cz) * sin(ax);
    point.z = cz - (p.y - cy) * sin(ax) + (p.z - cz) * cos(ax);

    // around y
    p = createPoint(point.x, point.y, point.z);
    point.x = cx + (p.z - cz) * sin(ay) + (p.x - cx) * cos(ay);
    point.z = cz + (p.z - cz) * cos(ay) - (p.x - cx) * sin(ay);

    // around z
    p = createPoint(point.x, point.y, point.z);
    point.x = cx + (p.x - cx) * cos(az) + (p.y - cy) * sin(az);
    point.y = cy - (p.x - cx) * sin(az) + (p.y - cy) * cos(az);
}

Point2D createPoint2D(int x, int y)
{
    return {x, y};
}

Point2D get2D(Point point)
{
    int x = int(point.x + 0.4 * point.z);
    int y = int(point.y + 0.4 * point.z);
    return createPoint2D(x, y);
}

Point findCenterPoints(const Point a, const Point b)
{
    double x = double(a.x + b.x) / 2;
    double y = double(a.y + b.y) / 2;
    double z = double(a.z + b.z) / 2;
    return createPoint(x, y, z);
}

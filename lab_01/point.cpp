#include "point.h"

Point createPoint(int x, int y, int z)
{
    return {x, y, z};
}

void drawPoint(Painter& painter, const Point point)
{
    int x = get2D(point).first;
    int y = get2D(point).second;

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

int roundInt(double num)
{
    return int(num + 0.5 * (num / num));
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
    point.y = roundInt(cy + (p.y - cy) * cos(ax) + (p.z - cz) * sin(ax));
    point.z = roundInt(cz - (p.y - cy) * sin(ax) + (p.z - cz) * cos(ax));
    //y':=y*cos(L)+z*sin(L) ;
    //z':=-y*sin(L)+z*cos(L) ;

    // around y
    p = createPoint(point.x, point.y, point.z);
    point.x = roundInt(cx + (p.z - cz) * sin(ay) + (p.x - cx) * cos(ay));
    point.z = roundInt(cz + (p.z - cz) * cos(ay) - (p.x - cx) * sin(ay));
    //x'=x*cos(L)+z*sin(L);
    //z'=-x*sin(L)+z*cos(L);

    // around z
    p = createPoint(point.x, point.y, point.z);
    point.x = roundInt(cx + (p.x - cx) * cos(az) - (p.y - cy) * sin(az));
    point.y = roundInt(cy - (p.x - cx) * sin(az) + (p.y - cy) * cos(az));
    //x'=x*cos(L)-y*sin(L);
    //y'=-x*sin(L)+y*cos(L);
}

QPair <int, int> get2D(Point point)
{
    int x = int(point.x + 0.4 * point.z);
    int y = int(point.y + 0.4 * point.z);
    // int x = int(double(point.x) / point.z);
    // int y = int(double(point.x) / point.z);
    return QPair <int, int> (x, y);
}

Point findCenterPoints(const Point a, const Point b)
{
    int x = (a.x + b.x) / 2;
    int y = (a.y + b.y) / 2;
    int z = (a.z + b.z) / 2;
    return createPoint(x, y, z);
}

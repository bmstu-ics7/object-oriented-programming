#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <QPair>

#include "painter.h"

struct Point
{
    int x;
    int y;
    int z;
};

Point createPoint(int, int, int);
void drawPoint(Painter&, const Point);
void offsetPoint(Point&, int, int, int);
void scalePoint(Point&, const Point, double);
void rotatePoint(Point&, const Point, int, int, int);
QPair <int, int> get2D(Point);
Point findCenterPoints(const Point, const Point);

#endif // POINT_H

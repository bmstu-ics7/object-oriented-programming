#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <QPair>

#include "painter.h"

struct Point
{
    double x;
    double y;
    double z;
};

struct Point2D
{
    int x;
    int y;
};

Point createPoint(double, double, double);
void drawPoint(Painter&, const Point);
void offsetPoint(Point&, int, int, int);
void scalePoint(Point&, const Point, double);
void rotatePoint(Point&, const Point, int, int, int);
Point2D createPoint2D(int, int);
Point2D get2D(Point);
double x(const Point);
double y(const Point);
double z(const Point);

#endif // POINT_H

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

Point createPoint(double x, double y, double z);
void drawPoint(Painter& painter, const Point point);
void offsetPoint(Point& point, int dx, int dy, int dz);
void scalePoint(Point& point, const Point center, double k);
void rotatePoint(Point& point, const Point center, int ax, int ay, int az);
Point2D createPoint2D(int x, int y);
Point2D get2D(Point point);
double x(const Point point);
double y(const Point point);
double z(const Point point);

#endif // POINT_H

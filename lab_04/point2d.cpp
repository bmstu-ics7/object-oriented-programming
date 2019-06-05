#include "point2d.h"

Point2D::Point2D() : Point2D(0) { }

Point2D::Point2D(double x) : Point2D(x, x) { }

Point2D::Point2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point3D& point)
{
    x = int(point.getX() + 0.4 * point.getZ());
    y = int(point.getY() + 0.4 * point.getZ());
}

double Point2D::getX() const
{
    return x;
}

double Point2D::getY() const
{
    return y;
}

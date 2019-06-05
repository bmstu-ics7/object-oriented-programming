#ifndef POSITION_H
#define POSITION_H

#include <point3d.h>

class Position
{
public:
    Position(Point3D center);
    Position(const std::vector< Point3D >& points);
    void offset(double dx, double dy, double dz);
    Point3D get();

private:
    Point3D center;
};

#endif // POSITION_H

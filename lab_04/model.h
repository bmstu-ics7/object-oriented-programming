#ifndef MODEL_H
#define MODEL_H

#include "object.h"
#include "drawer.h"
#include "edge.h"
#include "point2d.h"

class Model : public VisibleObject
{
public:
    Model() : VisibleObject() { }

    void addPoint(Point3D point);
    void addEdge(Edge edge);

    std::vector< Point3D >& getPoints();
    std::vector< Edge >& getEdges();

    const std::vector< Point3D >& getPoints() const;
    const std::vector< Edge >& getEdges() const;

    std::vector< Point3D > getConstPoints();
    std::vector< Edge > getConstEdges();

private:
    std::vector< Edge > edges;
    std::vector< Point3D > points;
};

#endif // MODEL_H

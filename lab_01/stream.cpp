#include "stream.h"

Error inputPoints(Vector<Point>& points, File& file)
{
    Error code = success;
    int countPoints = 0;
    code = input(countPoints, file);
    Vector<Point> copy = points;
    createVector(points, countPoints);
    for (int i = 0; i < countPoints && code == success; i++) {
        Point p = createPoint(0, 0, 0);
        code = inputPoint(p, file);
        append(points, p);
    }

    if (code != success) {
        destructVector(points);
        points = copy;
    } else {
        destructVector(copy);
    }

    return code;
}

Error inputEdges(Vector<Edge>& edges, File& file)
{
    Error code = success;
    int countEdges = 0;
    code = input(countEdges, file);
    Vector<Edge> copy = edges;
    createVector(edges, countEdges);
    for (int i = 0; i < countEdges && code == success; i++) {
        Edge edge = createEdge(0, 0);
        code = inputEdge(edge, file);
        append(edges, edge);
    }

    if (code != success) {
        destructVector(edges);
        edges = copy;
    } else {
        destructVector(copy);
    }

    return code;
}

void outputPoints(File& file, const Vector<Point> points)
{
    print(file, size(points));
    print(file, "\n");
    for (int i = 0; i < size(points); i++) {
        print(file, int(x(get(points, i))));
        print(file, " ");
        print(file, int(y(get(points, i))));
        print(file, " ");
        print(file, int(z(get(points, i))));
        print(file, "\n");
    }
}

void outputEdges(File& file, const Vector<Edge> edges)
{
    print(file, size(edges));
    print(file, "\n");
    for (int i = 0; i < size(edges); i++) {
        print(file, i1(get(edges, i)));
        print(file, " ");
        print(file, i2(get(edges, i)));
        print(file, "\n");
    }
}

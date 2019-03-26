#include "stream.h"

Error inputPoints(QTextStream& instream, Vector<Point>& points, Error code)
{
    QString line = instream.readLine();
    int countPoints = 0;
    if (!input(countPoints, line))
        code = incorrectFile;

    createVector(points);
    for (int i = 0; i < countPoints && code == success; i++) {
        Point p;
        line = instream.readLine();

        if (inputPoint(p, line) != success)
            code = incorrectFile;

        append(points, p);
    }

    return code;
}

Error inputEdges(QTextStream& instream, Vector<Edge>& edges, Error code)
{
    QString line = instream.readLine();
    int countEdges = 0;
    if (!input(countEdges, line) && code == success)
        code = incorrectFile;

    createVector(edges);
    for (int i = 0; i < countEdges && code == success; i++) {
        int i1 = 0, i2 = 0;
        line = instream.readLine();

        if (inputTwo(i1, i2, line) != success)
            code = incorrectFile;

        Edge edge = createEdge(i1, i2);
        append(edges, edge);
    }

    return code;
}

void outputPoints(QTextStream& outstream, const Vector<Point> points)
{
    outstream << size(points) << endl;
    for (int i = 0; i < size(points); i++)
        outstream << int(x(get(points, i)))
                  << ' '
                  << int(y(get(points, i)))
                  << ' '
                  << int(z(get(points, i)))
                  << endl;
}

void outputEdges(QTextStream& outstream, const Vector<Edge> edges)
{
    outstream << size(edges) << endl;
    for (int i = 0; i < size(edges); i++)
        outstream << i1(get(edges, i))
                  << ' '
                  << i2(get(edges, i))
                  << endl;
}

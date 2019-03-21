#include "figure.h"

Error returnError(Figure& figure, const Figure copy, Error error)
{
    destructFigure(figure);
    figure = copy;
    return error;
}

Error inputFileFigure(Figure& figure, QFile* file)
{
    if (!file->exists())
        return fileNotOpen;

    Figure copy = figure;
    createVector(figure.edges);

    QTextStream instream(file);
    QString line = instream.readLine();
    int countPoints = 0;

    if (!input(countPoints, line))
        return returnError(figure, copy, incorrectFile);

    Vector<Point> points;
    createVector(points);
    for (int i = 0; i < countPoints; i++) {
        Point p;
        line = instream.readLine();

        if (inputPoint(p, line) != success)
            return returnError(figure, copy, incorrectFile);

        append(points, p);
    }

    line = instream.readLine();
    int countEdges = 0;

    if (!input(countEdges, line))
        return returnError(figure, copy, incorrectFile);

    for (int i = 0; i < countEdges; i++) {
        int i1 = 0, i2 = 0;
        line = instream.readLine();

        if (inputTwo(i1, i2, line) != success)
            return returnError(figure, copy, incorrectFile);

        Edge edge = createEdge(get(points, i1), get(points, i2));
        append(figure.edges, edge);
    }

    destructVector(points);
    destructVector(copy.edges);
    return success;
}

Error outputFileFigure(const Figure figure, QFile* file)
{
    if (!file->exists())
        return fileNotOpen;

    Vector<Point> points;

    for (int i = 0; i < size(figure.edges); i++) {
        Edge& edge = get(figure.edges, i);
        Point a = edge.a;
        Point b = edge.b;

        bool aWas = false;
        bool bWas = false;

        for (int i = 0; i < size(points); i++) {
            Point& point = get(points, i);
            if (abs(a.x - point.x) <= EPS &&
                abs(a.y - point.y) <= EPS &&
                abs(a.z - point.z) <= EPS)
                aWas = true;

            if (abs(b.x - point.x) <= EPS &&
                abs(b.y - point.y) <= EPS &&
                abs(b.z - point.z) <= EPS)
                bWas = true;

            if (aWas && bWas)
                break;
        }

        if (!aWas)
            append(points, a);

        if (!bWas)
            append(points, b);
    }

    QTextStream outstream(file);
    outstream << size(points) << endl;
    for (int i = 0; i < size(points); i++) {
        Point point = get(points, i);
        outstream << point.x << ' ' << point.y << ' ' << point.z << endl;
    }

    outstream << size(figure.edges)<< endl;
    for (int i = 0; i < size(figure.edges); i++) {
        Edge& edge = get(figure.edges, i);
        Point a = edge.a;
        Point b = edge.b;

        int aIndex = -1;
        int bIndex = -1;

        for (int i = 0; i < size(points); i++) {
            if (abs(a.x - get(points, i).x) <= EPS &&
                abs(a.y - get(points, i).y) <= EPS &&
                abs(a.z - get(points, i).z) <= EPS)
                aIndex = i;

            if (abs(b.x - get(points, i).x) <= EPS &&
                abs(b.y - get(points, i).y) <= EPS &&
                abs(b.z - get(points, i).z) <= EPS)
                bIndex = i;

            if (aIndex >= 0 && bIndex >= 0)
                break;
        }

        outstream << aIndex << ' ' << bIndex << endl;
    }

    destructVector(points);
    return success;
}

void drawFigure(Painter& painter, const Figure figure)
{
    for (int i = 0; i < size(figure.edges); i++) {
        drawEdge(painter, get(figure.edges, i));
    }
}

void offsetFigure(Figure& figure, int dx, int dy, int dz)
{
    for (int i = 0; i < size(figure.edges); i++) {
        offsetEdge(get(figure.edges, i), dx, dy, dz);
    }
}

void scaleFigure(Figure& figure, double k)
{
    Point center = findCenterFigure(figure);
    for (int i = 0; i < size(figure.edges); i++) {
        scaleEdge(get(figure.edges, i), center, k);
    }
}

void rotateFigure(Figure& figure, int ax, int ay, int az)
{
    Point center = findCenterFigure(figure);
    for (int i = 0; i < size(figure.edges); i++) {
        rotateEdge(get(figure.edges, i), center, ax, ay, az);
    }
}

Point findCenterFigure(const Figure figure)
{
    int sumX = 0;
    int sumY = 0;
    int sumZ = 0;
    int count = 0;

    for (int i = 0; i < size(figure.edges); i++) {
        Point p = findCenterEdge(get(figure.edges, i));
        sumX += p.x;
        sumY += p.y;
        sumZ += p.z;
        count++;
    }

    return createPoint(sumX / count, sumY / count, sumZ / count);
}

void destructFigure(Figure& figure)
{
    destructVector(figure.edges);
}

void copyFigure(Figure& figure, const Figure copied)
{
    copy(figure.edges, copied.edges);
}

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
    figure = {};

    QTextStream instream(file);

    QString line = instream.readLine();
    int countPoints = 0;
    if (!input(countPoints, line))
        return returnError(figure, copy, incorrectFile);

    createVector(figure.points);
    for (int i = 0; i < countPoints; i++) {
        Point p;
        line = instream.readLine();

        if (inputPoint(p, line) != success)
            return returnError(figure, copy, incorrectFile);

        append(figure.points, p);
    }

    line = instream.readLine();
    int countEdges = 0;
    if (!input(countEdges, line))
        return returnError(figure, copy, incorrectFile);

    createVector(figure.edges);
    for (int i = 0; i < countEdges; i++) {
        int i1 = 0, i2 = 0;
        line = instream.readLine();

        if (inputTwo(i1, i2, line) != success)
            return returnError(figure, copy, incorrectFile);

        Edge edge = createEdge(i1, i2);
        append(figure.edges, edge);
    }

    destructFigure(copy);
    return success;
}

Error outputFileFigure(const Figure figure, QFile* file)
{
    if (!file->exists())
        return fileNotOpen;

    QTextStream outstream(file);

    outstream << size(figure.points) << endl;
    for (int i = 0; i < size(figure.points); i++) {
        outstream << int(x(get(figure.points, i)))
                  << ' '
                  << int(y(get(figure.points, i)))
                  << ' '
                  << int(z(get(figure.points, i)))
                  << endl;
    }

    outstream << size(figure.edges) << endl;
    for (int i = 0; i < size(figure.edges); i++) {
        outstream << i1(get(figure.edges, i))
                  << ' '
                  << i2(get(figure.edges, i))
                  << endl;
    }

    return success;
}

void drawFigure(Painter& painter, const Figure figure)
{
    for (int i = 0; i < size(figure.points); i++)
        drawPoint(painter, get(figure.points, i));

    for (int i = 0; i < size(figure.edges); i++)
        drawEdge(painter, get(figure.edges, i), figure.points);
}

void offsetFigure(Figure& figure, int x, int y , int z)
{
    for (int i = 0; i < size(figure.points); i++)
        offsetPoint(get(figure.points, i), x, y, z);
}

void scaleFigure(Figure& figure, double k)
{
    Point center = findCenterFigure(figure);
    for (int i = 0; i < size(figure.points); i++)
        scalePoint(get(figure.points, i), center, k);
}

void rotateFigure(Figure& figure, int ax, int ay, int az)
{
    Point center = findCenterFigure(figure);
    for (int i = 0; i < size(figure.points); i++)
        rotatePoint(get(figure.points, i), center, ax, ay, az);
}

Point findCenterFigure(const Figure figure)
{
    double sumX = 0;
    double sumY = 0;
    double sumZ = 0;
    int count = size(figure.points);

    for (int i = 0; i < count; i++) {
        sumX += x(get(figure.points, i));
        sumY += y(get(figure.points, i));
        sumZ += z(get(figure.points, i));
    }

    return createPoint(sumX / count, sumY / count, sumZ / count);
}

void destructFigure(Figure& figure)
{
    destructVector(figure.points);
    destructVector(figure.edges);
}

void copyFigure(Figure& figure, const Figure& copied)
{
    copy(figure.points, copied.points);
    copy(figure.edges, copied.edges);
}

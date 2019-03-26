#include "figure.h"

Error returnError(Figure& figure, Figure& copy, Error error)
{
    if (error == success) {
        destructFigure(copy);
        return error;
    }

    destructFigure(figure);
    figure = copy;
    return error;
}

Error inputFileFigure(Figure& figure, QFile* file)
{
    if (!file->exists())
        return fileNotOpen;

    Error code = success;

    Figure copy = figure;
    figure = {};

    QTextStream instream(file);
    code = inputPoints(instream, figure.points, code);
    code = inputEdges(instream, figure.edges, code);

    return returnError(figure, copy, code);
}

Error outputFileFigure(const Figure figure, QFile* file)
{
    if (!file->exists())
        return fileNotOpen;

    QTextStream outstream(file);
    outputPoints(outstream, figure.points);
    outputEdges(outstream, figure.edges);

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

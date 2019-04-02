#ifndef FIGURE_H
#define FIGURE_H

#include <QFile>
#include <QTextStream>

#include "point.h"
#include "edge.h"
#include "error.h"
#include "stream.h"

#define EPS 1e-6

struct Figure
{
    Vector<Point> points;
    Vector<Edge> edges;
};

Figure createFigure();
Error inputFileFigure(Figure& figure, File* file);
Error outputFileFigure(const Figure figure, File* file);
void drawFigure(Painter& painter, const Figure figure);
void offsetFigure(Figure& figure, int dx, int dy, int dz);
void scaleFigure(Figure& figure, double k);
void rotateFigure(Figure& figure, int ax, int ay, int az);
Point findCenterFigure(const Figure figure);
void destructFigure(Figure& figure);
void copyFigure(Figure& figure, const Figure& copied);

#endif // FIGURE_H

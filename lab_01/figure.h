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
Error inputFileFigure(Figure&, File*);
Error outputFileFigure(const Figure, File*);
void drawFigure(Painter&, const Figure);
void offsetFigure(Figure&, int, int, int);
void scaleFigure(Figure&, double);
void rotateFigure(Figure&, int, int, int);
Point findCenterFigure(const Figure);
void destructFigure(Figure&);
void copyFigure(Figure&, const Figure&);

#endif // FIGURE_H

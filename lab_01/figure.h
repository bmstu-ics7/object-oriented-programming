#ifndef FIGURE_H
#define FIGURE_H

#include <QFile>
#include <QTextStream>

#include "edge.h"
#include "error.h"
#include "input.h"

#define EPS 1e-6

struct Figure
{
    Vector<Edge> edges;
};

Error inputFileFigure(Figure&, QFile*);
Error outputFileFigure(const Figure, QFile*);
void drawFigure(Painter&, const Figure);
void offsetFigure(Figure&, int, int, int);
void scaleFigure(Figure&, double);
void rotateFigure(Figure&, int, int, int);
Point findCenterFigure(const Figure);
void destructFigure(Figure&);
void copyFigure(Figure&, const Figure);

#endif // FIGURE_H

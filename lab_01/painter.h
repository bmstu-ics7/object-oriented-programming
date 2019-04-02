#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>

struct Painter
{
    QPainter* paint;
    int width;
    int height;
};

void setPen(Painter& painter);
void setBrush(Painter& painter);
void drawLine(Painter& painter, int x1, int y1, int x2, int y2);
void drawPoint(Painter& painter, int x, int y);

#endif // PAINTER_H

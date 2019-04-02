#include "painter.h"

void setPen(Painter& painter)
{
    painter.paint->setPen(QPen(Qt::white, 1));
}

void setBrush(Painter& painter)
{
    painter.paint->setBrush(QBrush(Qt::white));
}

void drawLine(Painter& painter, int x1, int y1, int x2, int y2)
{
    int w = painter.width;
    int h = painter.height;
    painter.paint->drawLine(w / 2 + x1, h / 2 - y1, w / 2 + x2, h / 2 - y2);
}

void drawPoint(Painter& painter, int x, int y)
{
    painter.paint->drawEllipse(painter.width  / 2 + x - 2,
                               painter.height / 2 - y - 2,
                               4, 4);
}



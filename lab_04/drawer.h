#ifndef DRAWER_H
#define DRAWER_H

#include <QPainter>

#include "point2d.h"

class Drawer
{
public:
    virtual ~Drawer() = default;
    virtual void drawLine(const Point2D& a, const Point2D& b) = 0;

protected:
    Drawer(const size_t w, const size_t h) : w(w), h(h) { }
    const size_t w;
    const size_t h;
};

class QtDraw : public Drawer
{
public:
    QtDraw(QPainter& painter, const size_t w, const size_t h);
    void drawLine(const Point2D& a, const Point2D& b) override;

private:
    int round(double x);

    QPainter& painter;
};

#endif // DRAWER_H

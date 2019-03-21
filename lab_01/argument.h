#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "figure.h"

struct DrawArg
{
    Painter* painter;
};

struct ChangeArg
{
    int x;
    int y;
    int z;
};

struct ScaleArg
{
    double k;
};

struct FileArg
{
    QFile* file;
};

struct Argument
{
    DrawArg draw;
    ChangeArg change;
    ScaleArg scale;
    FileArg file;
};

#endif // ARGUMENT_H

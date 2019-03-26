#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>

#include "error.h"
#include "input.h"
#include "edge.h"

struct File
{
    QString fileName;
    QFile* data;
    QTextStream* stream;
};

void openFile(File&, QString);
void closeFile(File&);
Error input(int&, File&);
void print(File&, int);
void print(File&, char*);
void print(File&, const char*);
Error inputPoint(Point& p, File& file);
Error inputEdge(Edge&, File&);

#endif // FILE_H

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

void openFile(File& file, QString filename);
void closeFile(File& file);
Error input(int& number, File& file);
void print(File& file, int number);
void print(File& file, char* str);
void print(File& file, const char* str);
Error inputPoint(Point& point, File& file);
Error inputEdge(Edge& edge, File& file);

#endif // FILE_H

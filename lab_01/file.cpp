#include "file.h"

void openFile(File& file, QString fileName)
{
    file.fileName = fileName;
    file.data = new QFile(file.fileName);
    file.data->open(QIODevice::ReadWrite);
    file.stream = new QTextStream(file.data);
}

void closeFile(File& file)
{
    file.data->close();
    delete file.data;
    delete file.stream;
}

Error input(int& num, File& file)
{
    QString str = file.stream->readLine();
    if (input(num, str))
        return success;

    return incorrectFile;
}

Error inputPoint(Point& p, File& file)
{
    QString str = file.stream->readLine();
    return inputPoint(p, str);
}

Error inputEdge(Edge& edge, File& file)
{
    QString str = file.stream->readLine();
    return inputEdge(edge, str);
}

void print(File& file, int num)
{
    *file.stream << num;
}

void print(File& file, const char* c)
{
    *file.stream << c;
}

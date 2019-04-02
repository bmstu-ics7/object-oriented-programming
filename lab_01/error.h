#ifndef ERROR_H
#define ERROR_H

#include <QDebug>

enum Error
{
    success = 0,
    fileNotOpen,
    incorrectFile,
    unknownEvent
};

Error readError(Error error);

#endif // ERROR_H

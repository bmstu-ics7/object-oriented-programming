#include "error.h"

Error readError(Error error)
{
    switch(error) {
    case success:
        break;
    case fileNotOpen:
        qDebug() << "File not open";
        break;
    case incorrectFile:
        qDebug() << "Incorrect file";
        break;
    case unknownEvent:
        qDebug() << "Unknown event";
        break;
    }

    return error;
}

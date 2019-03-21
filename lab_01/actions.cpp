#include "actions.h"

Error drawEvent(Figure& figure, DrawArg arg, Event event)
{
    switch (event) {
    case draw:
        drawFigure(*arg.painter, figure);
        break;
    default:
        return unknownEvent;
    }

    return success;
}

Error changeEvent(Figure& figure, ChangeArg arg, Event event)
{
    switch (event) {
    case offset:
        offsetFigure(figure, arg.x, arg.y, arg.z);
        break;
    case rotate:
        rotateFigure(figure, arg.x, arg.y, arg.z);
        break;
    default:
        return unknownEvent;
    }

    return success;
}

Error scaleEvent(Figure& figure, ScaleArg arg, Event event)
{
    switch (event) {
    case scale:
        scaleFigure(figure, arg.k);
        break;
    default:
        return unknownEvent;
    }

    return success;
}

Error fileEvent(Figure& figure, FileArg arg, Event event)
{
    switch (event) {
    case load:
        return inputFileFigure(figure, arg.file);
    case save:
        return outputFileFigure(figure, arg.file);
    default:
        return unknownEvent;
    }
}

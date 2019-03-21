#include "action.h"

Error action(Argument& argument, Event event)
{
    Error error = success;
    static Figure figure;

    switch (event) {
    case draw:
        drawEvent(figure, argument.draw, event);
        break;
    case offset:
        changeEvent(figure, argument.change, event);
        break;
    case scale:
        scaleEvent(figure, argument.scale, event);
        break;
    case rotate:
        changeEvent(figure, argument.change, event);
        break;
    case load:
        error = fileEvent(figure, argument.file, event);
        break;
    case save:
        error = fileEvent(figure, argument.file, event);
        break;
    case exit_:
        destructFigure(figure);
    }

    return readError(error);
}

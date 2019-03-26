#include "action.h"

Error action(Argument& argument, Event event)
{
    Error error = success;
    static Figure figure = createFigure();

    switch (event) {
    case draw:
        error = drawEvent(figure, argument.draw, event);
        break;
    case offset:
        error = changeEvent(figure, argument.change, event);
        break;
    case scale:
        error = scaleEvent(figure, argument.scale, event);
        break;
    case rotate:
        error = changeEvent(figure, argument.change, event);
        break;
    case load:
        error = fileEvent(figure, argument.file, event);
        break;
    case save:
        error = fileEvent(figure, argument.file, event);
        break;
    case exit_:
        destructFigure(figure);
        break;
    default:
        error = unknownEvent;
        break;
    }

    return readError(error);
}

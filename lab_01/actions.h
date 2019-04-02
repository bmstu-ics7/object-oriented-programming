#ifndef ACTIONS_H
#define ACTIONS_H

#include "argument.h"
#include "event.h"

Error drawEvent(Figure& figure, DrawArg argument, Event event);
Error changeEvent(Figure& figure, ChangeArg argument, Event event);
Error scaleEvent(Figure& figure, ScaleArg argument, Event event);
Error fileEvent(Figure& figure, FileArg argument, Event event);

#endif // ACTIONS_H

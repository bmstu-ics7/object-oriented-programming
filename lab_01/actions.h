#ifndef ACTIONS_H
#define ACTIONS_H

#include "argument.h"
#include "event.h"

Error drawEvent(Figure&, DrawArg, Event);
Error changeEvent(Figure&, ChangeArg, Event);
Error scaleEvent(Figure&, ScaleArg, Event);
Error fileEvent(Figure&, FileArg, Event);

#endif // ACTIONS_H

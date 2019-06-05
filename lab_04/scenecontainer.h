#ifndef SCENECONTAINER_H
#define SCENECONTAINER_H

#include <stdlib.h>
#include <vector>

#include "model.h"
#include "position.h"
#include "iterator.h"

class SceneContainer
{
public:
    SceneContainer();

    size_t size();

    void add(std::shared_ptr< Object > obj);
    void addPosition(std::shared_ptr< Position > pos);

    PositionIterator find(ObjectIterator iter);

    ObjectIterator beginObjects();
    ObjectIterator endObjects();
    PositionIterator beginPositions();
    PositionIterator endPositions();

private:
    std::vector< std::shared_ptr< Object > > objects;
    std::vector< std::shared_ptr< Position > > positions;
};

#endif // SCENECONTAINER_H

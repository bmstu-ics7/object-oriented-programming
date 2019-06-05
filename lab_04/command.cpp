#include "command.h"

void Load::execute(Scene& facade)
{
    FileManager manager = facade.getFileManager();
    std::shared_ptr< Model > model = manager.load(loader, builder);
    facade.getObjects().add(model);

    std::shared_ptr< Position > pos;
    pos.reset(new Position(model->getPoints()));
    facade.getObjects().addPosition(pos);
}

void Save::execute(Scene& facade)
{
    FileManager manager = facade.getFileManager();
    manager.save(begin, end, saver);
}

void Draw::execute(Scene& facade)
{
    DrawManager manager = facade.getDrawManager();
    manager.draw(begin, end, drawer);
}

void Scale::execute(Scene& facade)
{
    TransformManager manager = facade.getTransformManager();
    PositionIterator beginP = facade.getObjects().find(begin);
    PositionIterator endP = facade.getObjects().find(end);
    manager.scale(begin, end, beginP, endP, k);
}

void Offset::execute(Scene& facade)
{
    TransformManager manager = facade.getTransformManager();
    PositionIterator beginP = facade.getObjects().find(begin);
    PositionIterator endP = facade.getObjects().find(end);
    manager.offset(begin, end, beginP, endP, dx, dy, dz);
}

void Rotate::execute(Scene& facade)
{
    TransformManager manager = facade.getTransformManager();
    PositionIterator beginP = facade.getObjects().find(begin);
    PositionIterator endP = facade.getObjects().find(end);
    manager.rotateX(begin, end, beginP, endP, ax);
    manager.rotateY(begin, end, beginP, endP, ay);
    manager.rotateZ(begin, end, beginP, endP, az);
}



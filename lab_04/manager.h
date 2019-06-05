#ifndef MANAGER_H
#define MANAGER_H

#include "iterator.h"
#include "model.h"
#include "position.h"
#include "file.h"

class Manager
{
public:
    Manager() { }
};

class FileManager : public Manager
{
public:
    FileManager() { }

    std::shared_ptr< Model > load(File& loader, ModelBuilder& builder);
    void save(ObjectIterator begin, ObjectIterator end, File& saver);
};

class DrawManager : public Manager
{
public:
    DrawManager() { }

    void draw(ObjectIterator begin, ObjectIterator end, Drawer& drawer);
};

class TransformManager : public Manager
{
public:
    TransformManager() { }

    void offset(ObjectIterator beginO, ObjectIterator endO,
                PositionIterator beginP, PositionIterator endP,
                const double dx, const double dy, const double dz);
    void scale(ObjectIterator beginO, ObjectIterator endO,
               PositionIterator beginP, PositionIterator endP,
               const double k);
    void rotateX(ObjectIterator beginO, ObjectIterator endO,
                 PositionIterator beginP, PositionIterator endP,
                 const double angle);
    void rotateY(ObjectIterator beginO, ObjectIterator endO,
                 PositionIterator beginP, PositionIterator endP,
                 const double angke);
    void rotateZ(ObjectIterator beginO, ObjectIterator endO,
                 PositionIterator beginP, PositionIterator endP,
                 const double angle);
};

class DeleteManager : public Manager
{
public:
    DeleteManager() { }
};

#endif // MANAGER_H

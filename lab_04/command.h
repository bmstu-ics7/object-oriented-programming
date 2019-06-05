#ifndef COMMAND_H
#define COMMAND_H

#include <iterator.h>
#include <drawer.h>

#include "scene.h"

class Command
{
public:
    virtual void execute(Scene& facade) = 0;
    virtual ~Command() = default;

protected:
    Command() { }
    Command(ObjectIterator begin) : begin(begin) { end = begin + 1; }
    Command(ObjectIterator begin, ObjectIterator end) : begin(begin), end(end) { }

    ObjectIterator begin;
    ObjectIterator end;
};

class Load : Command
{
public:
    Load(File& loader, ModelBuilder& builder)
         : loader(loader), builder(builder) { }

    void execute(Scene& facade) override;

private:
    File& loader;
    ModelBuilder& builder;
};

class Save : Command
{
public:
    Save(ObjectIterator begin,
         File& file)
        : Command(begin), saver(file) { }

    Save(ObjectIterator begin, ObjectIterator end,
         File& file)
        : Command(begin, end), saver(file) { }

    void execute(Scene& facade) override;

private:
    File& saver;
};

class Draw : Command
{
public:
    Draw(ObjectIterator begin,
         Drawer& drawer)
        : Command(begin), drawer(drawer) { }

    Draw(ObjectIterator begin, ObjectIterator end,
         Drawer& drawer)
        : Command(begin, end), drawer(drawer) { }

    void execute(Scene& facade) override;

private:
    Drawer& drawer;
};

class Scale : Command
{
public:
    Scale(ObjectIterator begin,
          const double k)
        : Command(begin), k(k) { }

    Scale(ObjectIterator begin, ObjectIterator end,
          const double k)
        : Command(begin, end), k(k) { }

    void execute(Scene& facade) override;

private:
    const double k;
};

class Offset : Command
{
public:
    Offset(ObjectIterator begin,
           const double dx, const double dy, const double dz)
        : Command(begin), dx(dx), dy(dy), dz(dz) { }

    Offset(ObjectIterator begin, ObjectIterator end,
           const double dx, const double dy, const double dz)
        : Command(begin, end), dx(dx), dy(dy), dz(dz) { }

    void execute(Scene& facade) override;

private:
    const double dx;
    const double dy;
    const double dz;
};

class Rotate : Command
{
public:
    Rotate(ObjectIterator begin,
           const double ax, const double ay, const double az)
        : Command(begin), ax(ax), ay(ay), az(az) { }

    Rotate(ObjectIterator begin, ObjectIterator end,
           const double ax, const double ay, const double az)
        : Command(begin, end), ax(ax), ay(ay), az(az) { }

    void execute(Scene& facade) override;

private:
    const double ax;
    const double ay;
    const double az;
};

class AddCamera : Command
{
public:
    AddCamera();
};

class Delete : Command
{
public:
    Delete();
};

#endif // COMMAND_H

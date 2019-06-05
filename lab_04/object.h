#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object() { }
    bool isVisible() { return visible; }
    bool isCompose() { return compose; }

protected:
    bool visible;
    bool compose;
};

class VisibleObject : public Object
{
public:
    VisibleObject() { visible = true; compose = false; }
};

class UnvisibleObject : public Object
{
public:
    UnvisibleObject() { visible = false; compose = false; }
};

class Compose : public Object
{
public:
    Compose() {}
};

#endif // OBJECT_H

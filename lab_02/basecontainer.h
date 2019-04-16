#ifndef __BASECONTAINER_H
#define __BASECONTAINER_H

class BaseContainer
{
public:
    virtual int rows() const = 0;
    virtual int columns() const = 0;
    virtual operator bool() const = 0;
    virtual ~BaseContainer() = default;
protected:
    int n;
    int m;
    int allocateLen;
};

#endif // __BASECONTAINER_H

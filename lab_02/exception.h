#ifndef __EXEPTION_H
#define __EXEPTION_H

#include <exception>

class BaseException : public std::exception
{
public:
    BaseException(const char* msg) : message(msg) {}
    virtual const char* what() const noexcept = 0;
protected: 
    const char* message;
};

class IndexException : public BaseException
{
public: 
    IndexException(const char* msg) : BaseException(msg) {}
    const char* what() const noexcept override;
};

class ArifmeticException : public BaseException
{
public: 
    ArifmeticException(const char* msg) : BaseException(msg) {}
    const char* what() const noexcept override;
};

class EmptyException : public BaseException
{
public: 
    EmptyException(const char* msg) : BaseException(msg) {}
    const char* what() const noexcept override;
};

class IteratorException : public BaseException
{
public: 
    IteratorException(const char* msg) : BaseException(msg) {}
    const char* what() const noexcept override;
};

#endif // __EXEPTION_H

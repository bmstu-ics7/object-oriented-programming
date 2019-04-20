#ifndef __EXEPTION_HPP
#define __EXEPTION_HPP

#include "exception.h"

const char* IndexException::what() const noexcept
{
    return message;
}

const char* ArifmeticException::what() const noexcept
{
    return message;
}

const char* EmptyException::what() const noexcept
{
    return message;
}

const char* IteratorException::what() const noexcept
{
    return message;
}

#endif // __EXEPTION_HPP

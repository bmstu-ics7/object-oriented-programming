#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdlib.h>
#include <vector>

class Object;
class Position;

typedef std::vector< std::shared_ptr< Object > >::iterator ObjectIterator;
typedef std::vector< std::shared_ptr< Position > >::iterator PositionIterator;

#endif // ITERATOR_H

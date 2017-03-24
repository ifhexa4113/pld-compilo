#include "Array.h"

Array::Array(std::string name_, Type type_, int size_) :
    LValue(name_, type_),
    size(size_)
{
    // Nothing else to so
}

Array::~Array()
{
    // Nothing else to do
}

int Array::getSize()
{
    return size;
}
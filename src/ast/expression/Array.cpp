#include "Array.h"

Array::Array(std::string name, Expression* index) :
    LValue(name),
    this->index(index)
{

}

Array::~Array()
{
    delete index;
}

int Array::walkTree()
{
    
}
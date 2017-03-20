#include "Function.h"

Function::Function(Type type) : type(type)
{

}

Function::~Function()
{

}

Type Function::getType()
{
    return type;
}

int Function::getNbArgs()
{
    return nbArgs;
}
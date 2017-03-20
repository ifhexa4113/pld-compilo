#include "Function.h"

Function::Function(Type type) : returnType(type)
{

}

Function::~Function()
{

}

Type Function::getType()
{
    return returnType;
}

int Function::getNbArgs()
{
    return nbArgs;
}
#include "Function.h"

Function::Function(std::string name_, Type type_, int nbArgs_) :
    Symbol(name_, type_),
    nbArgs(nbArgs_)
{
    // Nothing else to do
}

Function::~Function()
{
    // Nothing else to do
}

int Function::getNbArgs()
{
    return nbArgs;
}
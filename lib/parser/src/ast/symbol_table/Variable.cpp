#include "Variable.h"

Variable::Variable(std::string name_, Type type_) : LValue(name_, type_)
{
    // Nothing else to so
}

Variable::~Variable()
{
    // Nothing else to do
}
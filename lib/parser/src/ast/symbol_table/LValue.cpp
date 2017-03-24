#include "LValue.h"

LValue::LValue(std::string name_, Type type_) :
    Symbol(name_, type_)
{
    // Nothing else to do
}

LValue::~LValue()
{
    // Nothing else to do
}
#include "LValue.h"

LValue::LValue(Type type) : type(type)
{

}

LValue::~LValue()
{

}

Type LValue::getType()
{
    return type;
}
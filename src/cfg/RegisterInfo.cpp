#include "RegisterInfo.h"

RegisterInfo::RegisterInfo(Type type_, int offset_) :
    type(type_), offset(offset_)
{
    // Nothing else to do
}

RegisterInfo::~RegisterInfo()
{
    // Nothing else to do
}

int RegisterInfo::getOffset() const
{
    return offset;
}

Type RegisterInfo::getType() const
{
    return type;
}

void RegisterInfo::setOffset(int offset_)
{
    offset = offset_;
}

void RegisterInfo::setType(Type type_)
{
    type = type_;
}
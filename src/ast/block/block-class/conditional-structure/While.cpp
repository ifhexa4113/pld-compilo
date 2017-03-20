#include "While.h"

BlockClass::BlockClass()
{
#ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating While node, id: " << id << std::endl;
#endif
}

BlockClass::~BlockClass()
{
}
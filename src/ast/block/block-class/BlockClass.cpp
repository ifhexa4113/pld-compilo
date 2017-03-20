#include "BlockClass.h"

BlockClass::BlockClass()
{
#ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating BlockClass node, id: " << id << std::endl;
#endif
}

BlockClass::~BlockClass()
{
        delete block;
}
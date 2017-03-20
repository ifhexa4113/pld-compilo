#include "ConditionalStructure.h"

BlockClass::BlockClass()
{
#ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating ConditionalStructure node, id: " << id << std::endl;
#endif
}

BlockClass::~BlockClass()
{

}
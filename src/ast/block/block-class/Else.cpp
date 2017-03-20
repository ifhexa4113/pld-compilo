#include "Else.h"

Else::Else()
{
#ifdef DEBUG
    id = AstNode.IdMax++;
        std::cout << "Creating Else node, id: " << id << std::endl;
#endif
}

Else::~Else()
{

}


#include "For.h"

For::For()
{
#ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating For node, id: " << id << std::endl;
#endif
}

For::~For()
{

}
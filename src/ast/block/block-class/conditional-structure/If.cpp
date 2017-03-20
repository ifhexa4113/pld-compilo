
#include "If.h"

If::If()
{
#ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating If node, id: " << id << std::endl;
#endif
}

If::~If()
{

}
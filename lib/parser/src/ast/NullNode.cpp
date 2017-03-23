#include "NullNode.h"

NullNode::NullNode() : AstNode()
{
    // Nothing else to do
}

NullNode::~NullNode()
{
    // Nothing else to do
}

int NullNode::walkTree()
{
    return 0;
}
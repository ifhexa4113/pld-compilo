#include <vector>
#include "catch.h"
#include "ast/AstNode.h"
#include "ast/block/Block.h"

TEST_CASE("Simple test for Block", "")
{
    Block* block = new Block();

    SECTION("It should properly initialize an empty vector of children")
    {
        std::vector<AstNode*> v = block->getChildren();
        REQUIRE(v.size() == 0);
    }

    delete block;
}


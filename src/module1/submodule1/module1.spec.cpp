#include "module1.h"
#include "catch.h"

TEST_CASE("Simple submodule1 test", "")
{
    REQUIRE(test2() == 43);
}


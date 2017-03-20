#include "module1.h"
#include "catch.h"

TEST_CASE("Simple module1 test", "")
{
    REQUIRE(test() == 42);
}
#include <string>
#include "catch.h"
#include "ast/SymbolTable.h"
#include "ast/definition/VariableDefinition.h"
#include "ast/declaration/VariableDeclaration.h"
#include "ast/declaration/Type.h"

TEST_CASE("It should state that the table contains an element", "SymbolTable")
{
    std::string id = "a";
    VariableDeclaration* a = new VariableDeclaration(id, Type::CHAR_T);
    SymbolTable st;

    SECTION("It should insert a Symbol") {
        st.put(id, a);
        REQUIRE(st.contains(id));

        SECTION("It should gather the Symbol") {
            REQUIRE(st.get(id) == a);
        }
    }

    SECTION("It should not fail when trying to delete a declaration already deleted somewhere else")
    {
        SymbolTable* st2 = new SymbolTable();
        VariableDefinition* def = new VariableDefinition(a, nullptr);
        st2->put(id, def->getDeclaration());
        REQUIRE(st2->contains(id));
        delete def;
        delete st2;
    }

    // NOTE: no need to delete a since the SymbolTable will do it for us
}
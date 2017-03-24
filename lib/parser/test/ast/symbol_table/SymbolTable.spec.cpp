#include <string>
#include "catch.h"
#include "ast/symbol_table/SymbolTable.h"
#include "ast/symbol_table/Variable.h"
#include "ast/symbol_table/Type.h"

TEST_CASE("It should state that the table contains an element", "SymbolTable")
{
    std::string id = "a";
    Variable* a = new Variable(id, Type::CHAR_T);
    SymbolTable st;

    SECTION("It should insert a Symbol") {
        st.put(id, a);
        REQUIRE(st.contains(id));

        SECTION("It should gather the Symbol") {
            REQUIRE(st.get(id) == a);
        }
    }

    // NOTE: no need to delete a since the SymbolTable will do it for us
}
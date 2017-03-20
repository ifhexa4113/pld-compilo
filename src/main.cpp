#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include <cassert>
#include "ast/symbol_table/SymbolTable.h"
#include "ast/symbol_table/Symbol.h"

int main()
{
    SymbolTable* tab = new SymbolTable();
    Symbol* symbol = new Symbol("test", 23);
    tab->put("test", symbol);

    assert(tab->get("test") == symbol);
    assert(tab->get("") == 0);
    assert(symbol->getAddress() == 23);
    assert(symbol->getName() == "test");

    delete symbol;
    delete tab;


    std::cout << "Hello, World!" << std::endl;
    std::cout << test() << std::endl;
    std::cout << test2() << std::endl;

    int res = 0;

    yyparse(&res);

    printf("Result : %d\n",res);

    return 0;
}
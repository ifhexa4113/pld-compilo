#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include <cassert>

#include "ast/Ast.h"
#include "ast/CmmProgram.h"

void yyerror(CmmProgram& program, const char * message)
{
    std::cout << "yyerror: " << message << std::endl;
}

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    yyparse(program);

    program.walkTree();

    return 0;
}
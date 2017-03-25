#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include <cassert>

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    int result = yyparse(program);

    program.walkTree();

    return result;
}
#include <iostream>
#include <cstdio>
#include <cassert>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "cfg/CFG.h"

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    int result = yyparse(program);
    program.walkTree(); // TODO: this will be obsolete soon

    // CFG cfg(&ast);
    // cfg.print(std::cout);

    return result;
}
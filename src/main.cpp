#include <iostream>
#include <cstdio>
#include <cassert>
#include <assembler/x86/x86BasicBlockAssembler.h>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "cfg/CFG.h"

using namespace std;

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    cout << "Creating AST..." << endl;
    int result = yyparse(program);
    cout << "AST done" << endl;

    cout << "Creating CFG..." << endl;
    CFG cfg(&ast);
    cout << "CFG done:" << endl;
    cfg.print(cout);

    x86BasicBlockAssembler assembler(cfg.getInput());
    cout << assembler.translate();

    return result;
}
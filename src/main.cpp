#include <iostream>
#include <cstdio>
#include <cassert>
#include <assembler/x86/x86BasicBlockAssembler.h>
#include <fstream>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "cfg/CFG.h"
#include "../lib/parser/src/ast/block/CmmProgram.h"

using namespace std;

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    //cout << "Creating AST..." << endl;
    int result = yyparse(program);
    //cout << "AST done" << endl;

    //cout << "Creating CFG..." << endl;
    CFG cfg(&ast);
    //cout << "CFG done:" << endl;
    //cfg.print(cout);

    x86BasicBlockAssembler assembler(cfg.getInput(), true);

    ofstream stream;

    stream.open("out.s");

    stream << assembler.translate();

    stream.close();
    return result;
}
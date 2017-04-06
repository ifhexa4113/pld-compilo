#include <iostream>
#include <cstdio>
#include <cassert>
#include <assembler/x86/x86BasicBlockAssembler.h>
#include <fstream>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/SymbolTableStack.h"
#include "ast/ErrorManager.h"
#include "cfg/CFG.h"
#include "../lib/parser/src/ast/block/CmmProgram.h"

using namespace std;

int main()
{
    // Parse program
    Ast ast;
    CmmProgram& program = ast.getProgram();
    int result = yyparse(program);
    SymbolTableStack stack;
    program.fillSymbolTable(stack);

    // Show errors
    ErrorManager& errorManager = ErrorManager::getInstance();
    errorManager.printEncounteredErrorsNumber();
    errorManager.printEncounteredErrors();

    // Create CFG (IR)
    CFG cfg(&ast);

    // Generate Assembly code
    x86BasicBlockAssembler assembler(cfg.getInput(), true);
    ofstream stream;
    stream.open("out.s");
    stream << assembler.translate();
    stream.close();

    return result;
}
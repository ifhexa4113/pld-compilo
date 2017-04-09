#include <iostream>
#include <cstdio>
#include <cassert>
#include <assembler/x86/x86BasicBlockAssembler.h>
#include <fstream>
#include <cfg/ir/basic/AddInstruction.h>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/ErrorManager.h"
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

    ErrorManager& errorManager = ErrorManager::getInstance();
    int encounteredErrorsNumber = errorManager.getEncounteredErrorsNumber();
    if (encounteredErrorsNumber > 0) 
    {
        errorManager.printEncounteredErrors();
        return encounteredErrorsNumber;
    }


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
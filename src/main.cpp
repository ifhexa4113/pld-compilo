#include <iostream>
#include <cstdio>
#include <cassert>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/SymbolTableStack.h"
#include "ast/ErrorManager.h"
#include "cfg/CFG.h"

using namespace std;

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    cout << "Creating AST..." << endl;
    int result = yyparse(program);
    cout << "AST done" << endl;

//    cout << "Creating CFG..." << endl;
//    CFG cfg(&ast);
//    cout << "CFG done:" << endl;
//    cfg.print(cout);

    SymbolTableStack stack;
    program.fillSymbolTable(stack);

	ErrorManager& errorManager = ErrorManager::getInstance();
	errorManager.printEncounteredErrorsNumber();
	errorManager.printEncounteredErrors();

    return result;
}
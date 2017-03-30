#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include <cassert>

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/SymbolTableStack.h"
#include "ast/ErrorManager.h"

int main()
{
    Ast ast;
    CmmProgram& program = ast.getProgram();

    int result = yyparse(program);

    program.walkTree();

    SymbolTableStack stack;
    program.fillSymbolTable(stack);

	ErrorManager& errorManager = ErrorManager::getInstance();
	errorManager.printEncounteredErrorsNumber();
	errorManager.printEncounteredErrors();

    return result;
}
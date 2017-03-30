#include <iostream>
#include <cstdio>
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include <cassert>

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/SymbolTableStack.h"
#include "ast/AstNode.h"
#include "ast/ErrorManager.h"

bool errorManagerTest(std::string expectedErrorsTrace) {
	ErrorManager& errorManager = ErrorManager::getInstance();
	std::string errorsTrace = errorManager.getErrorsTrace();
	return expectedErrorsTrace.compare(errorsTrace) == 0;
}

bool astTest(AstNode* astNode, vector<string>) {
	// TODO
}

int main() {
	Ast ast;
	CmmProgram& program = ast.getProgram();

	int result = yyparse(program);

	program.walkTree();

	SymbolTableStack stack;
	program.fillSymbolTable(stack);

	return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include "module/module.h"
#include "module1/module1.h"
#include "module1/submodule1/module1.h"
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/SymbolTableStack.h"
#include "ast/AstNode.h"
#include "ast/ErrorManager.h"

using namespace std;

bool errorManagerTest(string expectedErrorsTrace) {
	ErrorManager& errorManager = ErrorManager::getInstance();
	string errorsTrace = errorManager.getErrorsTrace();
	std::cerr << std::endl << errorsTrace << std::endl; // to remove
	return expectedErrorsTrace.compare(errorsTrace) == 0;
}

bool astTest(AstNode* astNode, vector<string>) {
	// TODO
    return true;
}

int main(int argc, char *argv[]) {

	Ast ast;
	CmmProgram& program = ast.getProgram();

	int result = yyparse(program);

	program.walkTree();

	SymbolTableStack stack;
	program.fillSymbolTable(stack); 


	// Symbol table test by checking ErrorManager behaviour
	std::ifstream errorsInputStream;
	errorsInputStream.open(argv[1]);

	bool symbolTableTest;
	if (errorsInputStream.is_open())
	{
		std::stringstream errorsStringStream;
		errorsStringStream << errorsInputStream.rdbuf();
		symbolTableTest = errorManagerTest(errorsStringStream.str());
	}
	else
	{
		symbolTableTest = errorManagerTest("");
	}
	if (symbolTableTest)
	{
		std::cerr << "Symbol table test : SUCCESS" << std::endl;
	}
	else
	{
		std::cerr << "Symbol table test : FAIL" << std::endl;
	}




	return 0;
}
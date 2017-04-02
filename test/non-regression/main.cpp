#include <iostream>
#include <fstream>
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
	std::cout << errorsTrace << std::endl; // to remove
	return expectedErrorsTrace.compare(errorsTrace) == 0;
}

bool astTest(AstNode* astNode, vector<string>) {
	// TODO
    return true;
}

int main() {
	/*FILE* file = fopen("test/set/for-0/input.cmm", "r");

	std::ifstream in("test/set/for-0/input.cmm", std::ifstream::in);
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buffer
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to "test/set/for-0/input.cmm"
	*/


	/*
	// Save original std::cin
	std::streambuf *cinbuf = std::cin.rdbuf();

	std::ifstream in("test/set/for-0/input.cmm");

	//Read from "test/set/for-0/input.cmm" using std::cin
	std::cin.rdbuf(in.rdbuf());
	*/

	//yyin = fopen("test/set/for-0/input.cmm", "r");

	/*Ast ast;
	CmmProgram& program = ast.getProgram();

	int result = yyparse(program);

	program.walkTree();

	SymbolTableStack stack;
	program.fillSymbolTable(stack); */

	//errorManagerTest("");

	//fclose(yyin);

	std::cout << "Bonjour" << std::endl;


	return 0;
}
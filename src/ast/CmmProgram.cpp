#include <iostream>

#include "CmmProgram.h"

CmmProgram::CmmProgram()
{
    #ifdef DEBUG
        id = AstNode.IdMax++;
        std::cout << "Creating CmmProgram node, id: " << id << std::endl;
    #endif
}

CmmProgram::~CmmProgram()
{
    delete symbolTable;
    for(auto function : functions)
        delete function;
}

int CmmProgram::walkTree()
{

}

void CmmProgram::addFunction(FunctionDefinition* function)
{
    functions.push_back(function);
}
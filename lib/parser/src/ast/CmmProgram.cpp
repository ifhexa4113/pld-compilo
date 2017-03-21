#include <iostream>

#include "CmmProgram.h"

CmmProgram::CmmProgram() : AstNode()
{

}

CmmProgram::~CmmProgram()
{
    for(auto function : functions)
        delete function;
}

int CmmProgram::walkTree()
{
    std::cout << "Entering C--Program, iterating through the function" << std::endl;
    for(auto function : functions)
    {
        function->walkTree();
    }
    return 0;
}

void CmmProgram::addFunction(FunctionDefinition* function)
{
    functions.push_back(function);
}
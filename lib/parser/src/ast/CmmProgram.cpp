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

}

void CmmProgram::addFunction(FunctionDefinition* function)
{
    functions.push_back(function);
}
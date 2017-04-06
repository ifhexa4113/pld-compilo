#include <iostream>
#include "CmmProgram.h"

#include "ast/declaration/FunctionDeclaration.h"
#include "ast/declaration/LValueDeclaration.h"
#include "ast/SymbolTable.h"

CmmProgram::CmmProgram() : Block()
{
    FunctionDeclaration* putcharFunc = new FunctionDeclaration("putchar", Type::VOID_T, std::vector<LValueDeclaration*>(1));
    FunctionDeclaration* getcharFunc = new FunctionDeclaration("getchar", Type::CHAR_T, std::vector<LValueDeclaration*>(0));

    symbolTable.put(putcharFunc->getName(), putcharFunc);
    symbolTable.put(getcharFunc->getName(), getcharFunc);
}

CmmProgram::CmmProgram(std::vector<AstNode*> children_) :
    Block(children_)
{
    FunctionDeclaration* putcharFunc = new FunctionDeclaration("putchar", Type::VOID_T, std::vector<LValueDeclaration*>(1));
    FunctionDeclaration* getcharFunc = new FunctionDeclaration("getchar", Type::CHAR_T, std::vector<LValueDeclaration*>(0));

    symbolTable.put(putcharFunc->getName(), putcharFunc);
    symbolTable.put(getcharFunc->getName(), getcharFunc);
}

CmmProgram::~CmmProgram()
{
    // Nothing else to do
}

int CmmProgram::walkTree()
{
    std::cout << "Entering C--Program, iterating through children" << std::endl;
    Block::walkTree();
    return 0;
}

void CmmProgram::addFunction(FunctionDefinition* function)
{
    children.push_back(function);
}

void CmmProgram::fillAstTrace(std::string& astTrace)
{
    astTrace += "PROG\n";
    for (auto child : children)
        child->fillAstTrace(astTrace);
}

#include "Definition.h"
#include "ast/declaration/Declaration.h"
#include "ast/ErrorManager.h"

Definition::Definition(Declaration* declaration_) :
    AstNode(),
    declaration(declaration_)
{
    // Nothing else to do
}

Definition::~Definition()
{
    if(declaration != nullptr)
    {
        delete declaration;
    }
}

Declaration * Definition::getDeclaration()
{
    return declaration;
}

Type Definition::getType()
{
    return declaration->getType();
}

void Definition::fillSymbolTable(SymbolTableStack& stack)
{
    if(stack.checkSymbolImmediate(declaration->getName()))
    {
		ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::SYMBOL_REDECLARATION, declaration->getName());
    }
    if(!stack.checkSymbolImmediate(declaration->getName()))
        stack.addEntry(declaration->getName(), declaration);
}

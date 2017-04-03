#ifndef DECLARATION_H
#define DECLARATION_H

#include <string>
#include "Type.h"
#include "ast/AstNode.h"
#include "ast/definition/Definition.h"

class Declaration: public AstNode
{
public:
    Declaration(std::string name, Type type, int address = 0);
    virtual ~Declaration();

    virtual int walkTree() = 0;
    virtual Definition* toEmptyDefinition() = 0;
    std::string getName() const;
    Type getType() const;
    int getAddress() const;

    virtual void fillSymbolTable(SymbolTableStack& stack);
    bool checkNonVoidType(SymbolTableStack& stack);

protected:
    std::string name;
    Type type;
    int address;
};

#endif

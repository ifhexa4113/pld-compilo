#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "Type.h"
#include "ast/AstNode.h"
#include "ast/definition/Definition.h"
#include <memory>
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
    virtual const std::shared_ptr<Declaration> clone() const =0;
protected:
    std::string name;
    Type type;
    int address;
};

#endif

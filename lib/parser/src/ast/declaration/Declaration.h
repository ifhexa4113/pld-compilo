#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "Type.h"
#include "ast/AstNode.h"
#include "ast/definition/Definition.h"
#include <memory>
class Clonable {
    virtual ~clonable() {}
    virtual clonable* clone() const = 0;
};
class Declaration: public AstNode, public Clonable
{
public:
    Declaration(std::string name, Type type, int address = 0);
    virtual ~Declaration();
    virtual Declaration* clone() const
    { return new Declaration( *this ); }
    virtual int walkTree() = 0;
    virtual Definition* toEmptyDefinition() = 0;
    std::string getName() const;
    Type getType() const;
    int getAddress() const;

private:
    virtual Declaration* doClone() { return new Declaration(*this); }
protected:
    std::string name;
    Type type;
    int address;
};

#endif

#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "Type.h"
#include "ast/AstNode.h"

class Declaration: public AstNode
{
public:
    Declaration(std::string name, Type type, int address = 0);
    virtual ~Declaration();

    virtual int walkTree() = 0;
    std::string getName() const;
    Type getType() const;
    int getAddress() const;

protected:
    std::string name;
    Type type;
    int address;
};

#endif

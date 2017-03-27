#ifndef AST_NODE_H
#define AST_NODE_H

#ifdef DEBUG
    #include <iostream>
#endif

#include "SymbolTableStack.h"

class AstNode {

public:
    AstNode() 
    {
        #ifdef DEBUG 
            id = IdMax++;
            printConstDebug();
        #endif
    };
    virtual ~AstNode(){};

#ifdef DEBUG
    static unsigned int IdMax = 0;
    int getId() { return id; };
    virtual printConstDebug() const
    {
        std::cout << "Creating node, id: " << id << std::endl;
    }
#endif
    
    virtual int walkTree() = 0;
    virtual void fillSymbolTable(SymbolTableStack& stack){};

protected:
#ifdef DEBUG
    unsigned int id;
#endif
};

#endif
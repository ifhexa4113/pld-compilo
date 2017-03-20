#ifndef AST_NODE_H
#define AST_NODE_H

class AstNode {

public:
    static unsigned int IdMax = 0;
    int getId() { return id; };

    virtual int walkTree() = 0;

protected:
    unsigned int id;

};

#endif
#ifndef AST_NODE_H
#define AST_NODE_H

#ifdef DEBUG
    #include <iostream>
#endif

class AstNode {

public:
    AstNode() 
    {
        #ifdef DEBUG 
            id = IdMax++;
            printConstDebug();
        #endif
    };

#ifdef DEBUG
    static unsigned int IdMax = 0;
    int getId() { return id; };
    virtual printConstDebug() const
    {
        std::cout << "Creating node, id: " << id << std::endl;
    }
#endif
    
    virtual int walkTree() = 0;

protected:
#ifdef DEBUG
    unsigned int id;
#endif
};

#endif
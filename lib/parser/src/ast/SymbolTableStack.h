#ifndef SYMBOL_TABLE_STACK_H
#define SYMBOL_TABLE_STACK_H

#include <deque>
#include <string>

#include "SymbolTable.h"

class SymbolTableStack
{

public:

    /**
     *  Verify whether the SymbolTable at the top of the stack contains
     *  the symbol.
     *  @param name the name of the symbol
    **/
    bool checkSymbolImmediate(std::string name) const;

    /**
     *  Verify whether one of the SymbolTable contained in the stack contain the symbol 
     *  @param name the name of the symbol
    **/
    bool checkSymbol(std::string name) const;

    /**
     *  Add a SymbolTable on top of the stack
     *  @param table the table to add
    **/
    void push(SymbolTable& table);

    /**
     *  Add a Symbol to the table on top of the stack
     *  The method do NOT test if there is a table on top of the stack
     *  The method REPLACE the symbol whith the new symbol if there is already an entry with this key
     *  @param name the name of the symbol to add
     *  @param symbol the symbol to add
    **/
    void addEntry(std::string name, Declaration* symbol);

    /**
     *  Pop the symbol on top of the stack
     *  @return the table on top of the stack
    **/
    SymbolTable& pop();

    /**
     *  Return the table on top of the stack without removing it
     *  @return the table on top of the stack
    **/
    SymbolTable& peek();

    /**
     *  Check if the stack contains a table
     *  @return the whether the stack contains a table
    **/
    bool isEmpty() const;

    /**
     *  Get the Symbol with the given name
     *  @param name the name of the symbol
     *  @return the symbol if found or nullptr otherwise
    **/
    Declaration* getSymbol(std::string name);


protected:
    std::deque<SymbolTable*> stack;

};


#endif
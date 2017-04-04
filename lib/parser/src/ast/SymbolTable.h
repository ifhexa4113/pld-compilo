#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>
#include "declaration/Declaration.h"

class SymbolTable
{
public:
    SymbolTable();
    ~SymbolTable();

    /**
     * Returns a pointer to the symbol if the entry exists,
     * or a nullptr otherwise.
     * @param name The key to the symbol
     */
    Declaration* get(std::string name);

    /**
     * Inserts or replaces a symbol in the table,
     * using the provided name as identifier.
     * If a symbol already exists for the given key,
     * it is overwritten and the previous Symbol's pointer is erased from memory.
     * @param name The key to the symbol
     * @param symbol The symbol to insert
     */
    void put(std::string name, Declaration* symbol);

    /**
     * Returns true if the table contains a Symbol under the given key.
     * @param name The key to the symbol
     */
    bool contains(std::string name);

    /**
     * Returns an iterator on the first item of the table.
     */
    std::map<std::string,Declaration*>::iterator begin();

    /**
     * Returns an iterator on en empty item.
     */
    std::map<std::string,Declaration*>::iterator end();

private:
    std::map<std::string,Declaration*> table;
};

#endif

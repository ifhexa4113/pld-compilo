#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>

class Declaration;

class SymbolTable
{
public:
    SymbolTable();
    virtual ~SymbolTable();

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

private:
    std::map<std::string,Declaration*> table;
};

#endif

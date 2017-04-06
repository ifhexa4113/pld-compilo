#ifndef PLD_COMPILO_TABLE_H
#define PLD_COMPILO_TABLE_H

#include <map>
#include <string>
#include <ostream>

#include "RegisterInfo.h"
#include "ir/operand/Register.h"
#include "ir/operand/LiteralNumber.h"
#include "ast/declaration/LValueDeclaration.h"

class BasicBlock;

class Table
{
public:
    Table();
    ~Table();

    /**
     * Returns the register associated to the var if it already exists,
     * or a nullptr otherwise.
     * @param associatedVar The var UNIQUE name you're looking for
     */
    Register* getRegister(std::string associatedVar);

    /**
     * Returns the info associated to the given register if it already exists,
     * or an empty RegisterInfo otherwise ({type: Type::VOID_T, offset: -1}).
     * @param reg The register you're looking for.
     */
    RegisterInfo getRegisterInfo(Register* reg);

    /**
     * Inserts a register into the table.
     * This does NOT ensure that the register / variable already exists in the table,
     * i.e. it will overwrite any existing register / variable.
     * If no name is provided, the default one is "$tempX",
     * where X is an unsigned int from 0 to max(unsigned int).
     * @param reg The register to insert.
     * @param associatedVar The variable's UNIQUE name to insert.
     * @param type The variable's type. Default to Type::INT64_T.
     */
    void addRegister(Register* reg, std::string associatedVar = Table::TEMP_VAR, Type type = Type::INT64_T);

    /**
     * If a register already exists for the given variable,
     * then returns it.
     * Otherwise, it creates it and inserts it in the table.
     * If no associatedVar is provided (default to nullptr),
     * then a variable and a register marked as temporary is created
     * with Table::TEMP_VAR and will have the following shape:
     * "$tempX", where X is an unsigned int from 0 to max(unsigned int).
     * @param declaration The variable to associate to a register.
     */
    Register* getOrCreateRegister(LValueDeclaration* declaration = nullptr);

    /**
     * If there is already a literal number operand for the given
     * value, returns it.
     * Otherwise creates and returns it.
     * @param value The value from which create the Operand.
     */
    LiteralNumber* getOrCreateNumberOperand(int value);

    /**
     * Returns the last destination register of the given basic block,
     * or a nullptr if the last destination wasn't a register or even worst was
     * not known by the table (which would be a HUGE issue).
     * @param bb The basic block from which extract the destination register.
     */
    Register* getLastDestination(BasicBlock* bb);

    /**
     * Returns all the registers and their associated information,
     * in the shape of a map.
     */
    std::map<Register*, RegisterInfo>& getAllRegisters();

    /**
     * Prints the table in the given stream.
     * @param stream The stream where to print the table.
     */
    void print(std::ostream& stream);

protected:
    std::map<std::string, Register*> varToReg;
    std::map<Register*, RegisterInfo> regToInfo;
    std::map<int, LiteralNumber*> numbers;

    static unsigned int tempCounter;
    static const std::string TEMP_VAR;
};


#endif //PLD_COMPILO_TABLE_H

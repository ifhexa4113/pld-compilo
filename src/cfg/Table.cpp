#include "Table.h"
#include "BasicBlock.h"
#include "cfg/ir/RegisterInstruction.h"

#include <sstream>
#include <iostream>

unsigned int Table::tempCounter = 0;
const std::string Table::TEMP_VAR = "$temp";

Table::Table() : varToReg(), regToInfo(), numbers()
{
    // Nothing else to do
}

Table::~Table()
{
    // Delete all registers
    for(auto it = varToReg.begin(); it != varToReg.end(); it++)
    {
        delete it->second;
    }
    // Delete all other operands
    for(auto it = numbers.begin(); it != numbers.end(); it++)
    {
        delete it->second;
    }
}

Register* Table::getRegister(std::string associatedVar)
{
    return varToReg.count(associatedVar) > 0 ? varToReg[associatedVar] : nullptr;
}

RegisterInfo Table::getRegisterInfo(Register *reg)
{
    return regToInfo.count(reg) > 0 ? regToInfo[reg] : RegisterInfo();
}

void Table::addRegister(Register * reg, std::string associatedVar, Type type)
{
    if(associatedVar == Table::TEMP_VAR)
    {
        std::stringstream ss;
        ss << associatedVar << Table::tempCounter++;
        associatedVar = ss.str();
    }

    varToReg.insert(std::make_pair(associatedVar, reg));
    regToInfo.insert(std::make_pair(reg, RegisterInfo(type)));
}

Register* Table::getOrCreateRegister(LValueDeclaration* declaration)
{
    std::string associatedVar;
    Type type;
    if(declaration == nullptr)
    {
        std::stringstream ss;
        ss << Table::TEMP_VAR << Table::tempCounter++;
        associatedVar = ss.str();
        type = Type::INT64_T;
    } else {
        associatedVar = declaration->getName();
        declaration->getType();
    }

    if(getRegister(associatedVar))
    {
        return getRegister(associatedVar);
    }

    Register* reg = new Register();
    varToReg.insert(std::make_pair(associatedVar, reg));
    regToInfo.insert(std::make_pair(reg, RegisterInfo(type)));
    return reg;
}

LiteralNumber* Table::getOrCreateNumberOperand(int value)
{
    if(numbers.count(value) == 0)
    {
        // No operand exists.
        // Let's create it, insert it and return it
        LiteralNumber* ln = new LiteralNumber(value);
        numbers.insert(std::make_pair(value, ln));
        return ln;
    }
    // We're sure that it exists.
    // Let's return it
    return numbers[value];
}

Register* Table::getLastDestination(BasicBlock *bb)
{
    if(RegisterInstruction* ri = dynamic_cast<RegisterInstruction*>(bb->getInstructions().back()))
    {
        if(regToInfo.count(ri->getDestination()) > 0)
        {
            return ri->getDestination();
        }
        std::cerr << "ERROR - HUGE: last register of the last instruction of the given BasicBlock is UNKNOWN by the Table." << std::endl;
        return nullptr;
    }
    std::cerr << "ERROR: last instruction of the given BasicBlock is not a RegisterInstruction." << std::endl;
    return nullptr;
}

std::map<Register *, RegisterInfo> * Table::getAllRegisters()
{
    return &regToInfo;
}

void Table::print(std::ostream &stream)
{
    stream << "var\treg\toffset" << std::endl;
    stream << "-------------------------" << std::endl;
    for(auto it = varToReg.cbegin(); it != varToReg.cend(); it++)
    {
        stream << it->first << "\t" << it->second->getName() << "\t" << regToInfo[it->second].getOffset() << std::endl;
    }
}
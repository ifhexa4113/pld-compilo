#include "Table.h"

#include <sstream>

unsigned int Table::tempCounter = 0;
const std::string Table::TEMP_VAR = "$temp";

Table::Table() : varToReg(), regToInfo()
{
    // Nothing else to do
}

Table::~Table()
{
    // Nothing else to do
    for(auto it = varToReg.begin(); it != varToReg.end(); it++)
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
    if(declaration == nullptr)
    {
        std::stringstream ss;
        ss << associatedVar << Table::tempCounter++;
        associatedVar = ss.str();
    } else {
        associatedVar = declaration->getName();
    }

    if(getRegister(associatedVar))
    {
        return getRegister(associatedVar);
    }

    Register* reg = new Register();
    varToReg.insert(std::make_pair(associatedVar, reg));
    regToInfo.insert(std::make_pair(reg, RegisterInfo(declaration->getType())));
    return reg;
}

std::map<Register *, RegisterInfo> & Table::getAllRegisters()
{
    return regToInfo;
}
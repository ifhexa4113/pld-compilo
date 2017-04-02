//
// Created by Element on 29/03/2017.
//

#include "CmpInstruction.h"

CmpInstruction::CmpInstruction(Operand *param1_, Operand *param2_) : 
    IRInstruction(), 
    param1(param1_), 
    param2(param2_) 
{

}

CmpInstruction::~CmpInstruction() 
{
    delete param1;
    delete param1;
}

void CmpInstruction::print(std::ostream &ost) const 
{
    ost << "CMP\t" << param1 << ", " << param2;
}

const Operand *CmpInstruction::getParam1() const
{
    return param1;
}

const Operand *CmpInstruction::getParam2() const 
{
    return param2;
}

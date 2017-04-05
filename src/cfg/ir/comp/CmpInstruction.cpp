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
    // Nothing else to do (the Table handles it)
}

void CmpInstruction::print(std::ostream &ost) const 
{
    ost << "CMP\t" << *param1 << ", " << *param2 << std::endl;
}

Operand * CmpInstruction::getParam1() const
{
    return param1;
}

Operand * CmpInstruction::getParam2() const
{
    return param2;
}

//
// Created by Element on 03/04/2017.
//

#include "cfg/ir/basic/AddInstruction.h"
#include "catch.h"
#include "assembler/x86/x86BasicBlockAssembler.h"
#include <iostream>

TEST_CASE("Addx86Assembler tests", "[x86]")
{
    BasicBlock * block = new BasicBlock("foo");


    Table mahTable;
    block->setTable(&mahTable);

    block->addInstruction(new AddInstruction(mahTable.getOrCreateRegister(),mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));
    block->setPrologable(true);

    x86BasicBlockAssembler blockAssembler(block,false);

    std::cout << "CFG \n";

    block->print(std::cout);

    std::string value = blockAssembler.translate();
    std::cout << "Block output : \n" << value << std::endl;
    REQUIRE(1 == 1);


}
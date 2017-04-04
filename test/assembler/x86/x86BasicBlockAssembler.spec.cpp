//
// Created by Element on 03/04/2017.
//

#include <cfg/ir/basic/MovInstruction.h>
#include "catch.h"
#include "assembler/x86/x86BasicBlockAssembler.h"
#include <iostream>

TEST_CASE("Addx86Assembler tests", "[x86]")
{
    BasicBlock * block = new BasicBlock("foo");


    Table mahTable;
    block->setTable(&mahTable);

    block->addInstruction(new MovInstruction(mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));
    x86BasicBlockAssembler blockAssembler(block);

    std::string value = blockAssembler.translate();
    std::cout << "Block output : \n" << value << std::endl;
    REQUIRE(1 == 1);


}
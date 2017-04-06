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
    BasicBlock * jump_true = new BasicBlock("bar");
    BasicBlock * jump_false = new BasicBlock("bor");
    BasicBlock * end = new BasicBlock("end");

    jump_true->setExitTrue(end);
    jump_false->setExitFalse(end);



    Table mahTable;
    block->setTable(&mahTable);

    jump_true->setTable(&mahTable);
    jump_false->setTable(&mahTable);
    end->setTable(&mahTable);

    block->addInstruction(new AddInstruction(mahTable.getOrCreateRegister(),mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));
    block->setPrologable(true);

    jump_true->addInstruction(new AddInstruction(mahTable.getOrCreateRegister(),mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));
    jump_false->addInstruction(new AddInstruction(mahTable.getOrCreateRegister(),mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));

    end->addInstruction(new AddInstruction(mahTable.getOrCreateRegister(),mahTable.getOrCreateRegister(), mahTable.getOrCreateRegister()));


    block->setExitTrue(jump_true);
    block->setExitFalse(jump_false);

    x86BasicBlockAssembler blockAssembler(block,false);

    //std::cout << "CFG \n";

    //block->print(std::cout);

    std::string value = blockAssembler.translate();
    std::cout << "Block output : \n" << value << std::endl;
    REQUIRE(1 == 1);


}
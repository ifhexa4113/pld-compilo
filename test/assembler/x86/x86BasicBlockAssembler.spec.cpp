//
// Created by Element on 03/04/2017.
//

#include <cfg/ir/basic/MovInstruction.h>
#include "catch.h"
#include "assembler/x86/x86BasicBlockAssembler.h"

TEST_CASE("Addx86Assembler tests", "[x86]")
{
    BasicBlock * block = new BasicBlock("foo");
    block->addInstruction(new MovInstruction(new Register("%reg0",0), new Register("%reg1",0)));
    x86BasicBlockAssembler blockAssembler(block);

    std::string value = blockAssembler.translate();
    INFO("Block output : \n" << value);

    REQUIRE(1 == 0);
}
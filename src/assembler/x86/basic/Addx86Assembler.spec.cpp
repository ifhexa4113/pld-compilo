//
// Created by Element on 03/04/2017.
//
#include "catch.h"
#include "Addx86Assembler.h"

TEST_CASE("Addx86Assembler tests", "[x86]")
{
    AddInstruction ir_instr(new Register(1), new Register(2), new Register(3));

    Addx86Assembler add_instr(&ir_instr);

    std::string result = add_instr.translate();

    std::string expected_result =
            "mov eax, ecx\n"
            "add eax, edx\n";

    REQUIRE(result.compare(expected_result) == 0);
}
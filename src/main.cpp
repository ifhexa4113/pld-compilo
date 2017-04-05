#include <iostream>
#include <cstdio>
#include <cassert>
#include <assembler/x86/x86BasicBlockAssembler.h>
#include <fstream>
#include <cfg/ir/basic/AddInstruction.h>
#include "calc.tab.h"

#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "cfg/CFG.h"
#include "../lib/parser/src/ast/block/CmmProgram.h"

using namespace std;

int main()
{
    /*Ast ast;
    CmmProgram& program = ast.getProgram();

    //cout << "Creating AST..." << endl;
    int result = yyparse(program);
    //cout << "AST done" << endl;

    //cout << "Creating CFG..." << endl;
    CFG cfg(&ast);
    //cout << "CFG done:" << endl;
    cfg.print(cout);

    x86BasicBlockAssembler assembler(cfg.getInput(), true);

    ofstream stream;

    stream.open("out.s");

    stream << assembler.translate();

    stream.close();
    return result;*/

    BasicBlock * block = new BasicBlock("foo");
    BasicBlock * jump_true = new BasicBlock("bar");
    BasicBlock * jump_false = new BasicBlock("bor");
    BasicBlock * end = new BasicBlock("end");

    jump_true->setExitTrue(end);
    jump_false->setExitTrue(end);



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
    return 0;
}
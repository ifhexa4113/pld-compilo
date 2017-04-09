#include <iostream>
#include <cstdio>
#include <cassert>
#include <fstream>
//#include <stdio.h>

#include "calc.tab.h"
#include "assembler/x86/x86BasicBlockAssembler.h"
#include "cfg/ir/basic/AddInstruction.h"
#include "ast/Ast.h"
#include "ast/block/CmmProgram.h"
#include "ast/ErrorManager.h"
#include "cfg/CFG.h"
#include "ast/block/CmmProgram.h"

using namespace std;

extern FILE *yyin;
void usage();

int main(int argc, char** argv)
{
    // Check the number of parameters
    if(argc > 3) {
        cerr << "ERROR: Too many parameters" << endl;
        usage();
        return -1;
    }

    bool ir = false;
    bool assembly = false;
    bool customPath = false;
    string path(argv[0]);

    // There are enough parameters
    for(int i = 1; i < argc; i++){
        string param = argv[i];

        // It's the help
        if(param == "-h" || param == "--help")
        {
            if(ir || assembly || customPath || argc > 2)
            {
                cerr << "ERROR: you can't use help with other parameters." << endl;
                usage();
                return -2;
            }
            usage();
            return 0;
        }

        if(!(ir || assembly))
        {
            // Print the ir
            if(param == "-i") {
                ir = true;
                continue;
            }
            // Print the assembly
            if(param == "-c") {
                assembly = true;
                continue;
            }
        }
        else {
            if(param == "-c" || param == "-i")
            {
                cerr << "ERROR: options are exclusive." << endl;
                usage();
                return -1;
            }
        }

        if(!customPath)
        {
            customPath = true;
            path = param;
        }
        else {
            cerr << "ERROR: you can't provide more than one path." << endl;
            usage();
            return -3;
        }
    }

    Ast ast;
    CmmProgram& program = ast.getProgram();
    if(customPath)
    {
        yyin = fopen(path.c_str(), "r");
    }
    yyparse(program);
    if(customPath)
    {
        fclose(yyin);
    }

    ErrorManager& errorManager = ErrorManager::getInstance();
    int encounteredErrorsNumber = errorManager.getEncounteredErrorsNumber();
    if (encounteredErrorsNumber > 0)
    {
        errorManager.printEncounteredErrors();
        return encounteredErrorsNumber;
    }

    if(ir || assembly)
    {
        ofstream stream;
        CFG cfg(&ast);
        if(ir)
        {
            stream.open("ir.out");
            cfg.print(stream);
            stream.close();
            return 0;
        }

        x86BasicBlockAssembler assembler(cfg.getInput(), true);
        stream.open("out.s");
        stream << assembler.translate();
        stream.close();
    }

    return 0;
}

void usage() {
    cout << "gmm.exe --- Help" << endl << endl;
    cout << "--- Usage --- " << endl;
    cout << "No parameters:\t\tdefault input is stdout." << endl;
    cout << "One parameter:\t\tthe path to the file to read, or an option." << endl;
    cout << "Two parameters:\t\tthe path to the file to read and an option." << endl;
    cout << "More parameters:\terror. You can't do that." << endl << endl;
    cout << "--- Options ---" << endl;
    cout << "-h\t(or --help) prints the help." << endl;
    cout << "-i\tgenerates IR code into ir.out" << endl;
    cout << "-c\tgenerates assembly code into out.s" << endl;
    cout << "NOTE: these options are exclusive." << endl;
}
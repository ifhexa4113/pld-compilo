#ifndef CMM_PROGRAM_TRANSLATOR_H
#define CMM_PROGRAM_TRANSLATOR_H

#include "Translator.h"
#include "ast/block/CmmProgram.h"

class CmmProgramTranslator : public Translator {
public:
    CmmProgramTranslator(CmmProgram* program, CFG* cfg);
    ~CmmProgramTranslator();
    BasicBlock* translate();
};


#endif //CMM_PROGRAM_TRANSLATOR_H

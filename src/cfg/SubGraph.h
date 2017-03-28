#ifndef SUB_GRAPH_H
#define SUB_GRAPH_H

#include <vector>
#include "BasicBlock.h"

class SubGraph {
public:
    SubGraph(BasicBlock* input_, std::vector<BasicBlock*> outputs_);
    ~SubGraph();
    BasicBlock* getInput();
    std::vector<BasicBlock*> getOutputs();

protected:
    BasicBlock* input;
    std::vector<BasicBlock*> outputs;
};


#endif //SUB_GRAPH_H

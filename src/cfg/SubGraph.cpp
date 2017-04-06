#include "SubGraph.h"

SubGraph::SubGraph(BasicBlock *input_, std::vector<BasicBlock *> outputs_) :
    input(input_), outputs(outputs_)
{
    // Nothing else to do
}
SubGraph::~SubGraph()
{
    // Nothing else to do
    // NOTE: basic blocks must be deleted by someone else
}

BasicBlock* SubGraph::getInput()
{
    return input;
}

std::vector<BasicBlock *> SubGraph::getOutputs()
{
    return outputs;
}
#ifndef A_H
#define A_H

#include "node.h"
#include "tree.h"

class A:public Tree 
{
    public:
        A(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~A(){}
        std::deque<Node> Solve();


};

#endif
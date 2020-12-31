#ifndef BFS_H
#define BFS_H

#include "tree.h"
#include "node.h"
#include <iostream>
#include <deque>
#include <list>

class BFS:public Tree
{
    public:
        BFS(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~BFS(){};
        std::deque<Node> Solve();
};

#endif
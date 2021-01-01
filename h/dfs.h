#ifndef DFS_H
#define DFS_H

#include "tree.h"
#include "node.h"
#include "color.h"

class DFS: public Tree
{
    public:
        int limit{};
        int depth{};
        int test;

        DFS(Node _root,int _limit,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~DFS(){};
        std::deque<Node> Solve();
        bool recDLS(Node node,int l,int d);
};
#endif
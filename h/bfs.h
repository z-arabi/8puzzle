#ifndef BFS_H
#define BFS_H

#include "node.h"
#include <iostream>
#include <bits/stdc++.h>

class BFS
{
    private:
        Node root;
        std::vector<std::shared_ptr<Node>> path{};
        std::vector<std::shared_ptr<Node>> frontier{};
        std::vector<int> nfrontier{};
        std::vector<int> nexplored{};
        std::vector<std::shared_ptr<Node>> actions{};
        std::vector<int> goalpuzzle{};
    
    public:
        BFS(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~BFS(){};
        std::vector<std::shared_ptr<Node>> Solve();

        bool contains(std::vector<int> l,int idp);
        void pathtrace(Node n);
        void showPathInfo();
};

#endif
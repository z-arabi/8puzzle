#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <vector>
#include <queue>

class Tree
{
    public:
        Node root;
        std::deque<std::shared_ptr<Node>> path{};
        std::vector<std::shared_ptr<Node>> frontier{};
        std::vector<std::shared_ptr<Node>> explored{};
        std::vector<std::shared_ptr<Node>> actions{};
        std::vector<int> goalpuzzle{};

        Tree(){ /*std::cout << "tree constructor\n";*/ }
        ~Tree(){};
        bool contains(std::vector<std::shared_ptr<Node>> l,Node c);
        void pathtrace(Node n);
        void showPathInfo();
        int getInvCount(std::vector<int> p,int _s);        
        bool isSolvable(std::vector<int> _puzzle,int _s);
};

#endif
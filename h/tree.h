#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>

class Tree
{
    public:
        Node root;
        std::deque<Node> path{};
        std::deque<Node> frontier{};
        std::deque<Node> explored{};
        std::deque<std::string> actions{};
        std::vector<int> goalpuzzle{};

        Tree(){ /*std::cout << "tree constructor\n";*/ }
        ~Tree(){};
        bool contains(std::deque<Node> l,Node c);
        void pathtrace(Node n);
        void showPathInfo();
        int getInvCount(std::vector<int> p,int _s);        
        bool isSolvable(std::vector<int> _puzzle,int _s);
};

#endif
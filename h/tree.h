#ifndef TREE_H
#define TREE_H

// #include <iostream>
// #include <vector>
// #include <string>

#include "node.h"

class Tree
{
    protected:
        Node root;
        std::deque<Node> path{};
        std::deque<Node> frontier{};
        std::deque<Node> explored{};
        std::deque<std::string> actions{};
        std::vector<int> goalpuzzle{};

        Tree()
        {
            std::cout << "tree constructor\n";
        }
        ~Tree(){};
        bool contains(std::deque<Node> l,Node c)
        {
            std::cout << "contains..." << l.size() << "\n";
            for(int i = 0;i<l.size();i++)
            {
                if(l[i].puzzle==c.puzzle)
                {
                    return true;
                }
            }
            return false;
        }
        void pathtrace(Node n)
        {
            std::cout << "tracing path...\n";
            path = {};
            actions = {};
            Node current = n;
            path.push_front(current);
            while(current.parent!=nullptr && current!=*(current.parent))
            {
                Node cc = *(current.parent);
                current = cc;
                current.parent = {};
                current.parent = cc.parent;
                path.push_front(current);
            }
            std::cout << path.size() << "\n";
        }
        void showPathInfo()
        {
            for(int i{};i<path.size();i++)
            {
                std::cout << path[i].action << " =>\n";
                path[i].show();
            }
        }
        
};

#endif
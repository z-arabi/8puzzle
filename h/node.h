#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <deque>
#include <vector>
#include <string>
#include "color.h"
#include <memory>

class Node
{
    public:
        int col{3};
        int size{col*col};
        std::vector<int> puzzle;
        std::vector<std::shared_ptr<Node>> children{};
        std::string action{};
        std::vector<std::shared_ptr<Node>> parent{};
        int ind0{};
        int heuristic{};

        Node(){}
        Node(std::vector<int> _puzzle,std::string _action="");
        void setValue(std::vector<int> _puzzle);
        Node(const Node& node);
        Node(const Node* node);
        ~Node(){}
        bool Test(std::vector<int> goalarray={1,2,3,4,5,6,7,8,0});
        void right(std::vector<int> _puzzle,int ind0);
        void left(std::vector<int> _puzzle,int ind0);
        void up(std::vector<int> _puzzle,int ind0);
        void down(std::vector<int> _puzzle,int ind0);
        void show();
        bool sameNode(std::vector<int> _puzzle);
        void generate();
        bool operator==(Node node);
        bool operator!=(Node node);
        int findHeu(std::vector<int> goalarray={1,2,3,4,5,6,7,8,0});
};

#endif
#ifndef A_H
#define A_H

#include "node.h"
#include <bits/stdc++.h>

class A
{
    private:
        Node root;
        std::vector<std::shared_ptr<Node>> path{};
        std::vector<std::shared_ptr<Node>> frontier{};
        std::vector<std::shared_ptr<Node>> explored{};
        std::vector<int> nfrontier{};
        std::vector<int> nexplored{};
        std::vector<std::shared_ptr<Node>> actions{};
        std::vector<int> goalpuzzle{};
        std::vector<int> goal{1,2,3,4,5,6,7,8,0};
        int depth{};

    public:
        A(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~A(){}
        std::vector<std::shared_ptr<Node>> Solve();

        bool contains(std::vector<int> l,int idp);
        void pathtrace(Node n);
        void showPathInfo();

};

#endif
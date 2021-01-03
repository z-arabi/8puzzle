#ifndef DFS_H
#define DFS_H

#include "node.h"
#include "color.h"

class DFS
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
        
        int limit{};
        int depth{};

    public:
        DFS(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~DFS(){};
        std::vector<std::shared_ptr<Node>> SolveDLS(int _limit);
        std::vector<std::shared_ptr<Node>> SolveIDS();
        bool recDLS(std::shared_ptr<Node> node,int l);

        bool contains(std::vector<int> l,int idp);
        void pathtrace(Node n);
        void showPathInfo();
};

#endif
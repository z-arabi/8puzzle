#ifndef BFS_H
#define BFS_H

#include "node.h"
#include <iostream>
#include <bits/stdc++.h>

class BFS
{
    public:
        BFS(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0});
        ~BFS(){};
        std::vector<std::shared_ptr<Node>> Solve();

        Node root;
        std::vector<std::shared_ptr<Node>> path{};
        std::vector<std::shared_ptr<Node>> frontier{};
        std::vector<int> nfrontier{};
        std::vector<int> nexplored{};
        std::vector<std::shared_ptr<Node>> actions{};
        std::vector<int> goalpuzzle{};

        bool contain(std::vector<int> l,int idp){
            auto it = std::find(l.begin(), l.end(), idp);
            if (it != l.end()) 
            {
                return true;
            }
            return false;
        }

        void pathtrace(Node n){
            path = {};
            actions = {};
            auto current = std::make_shared<Node>(n);
            path.push_back(current);
            Node comp{};
            while(current->parent.size()!=0)
            {
                current = current->parent[0];
                path.push_back(current);
            }
            std::reverse(path.begin(),path.end());
            std::cout << GREEN << "The Depth is..." << path.size() << RESET << "\n";
        }

        void showPathInfo(){
            for(size_t i{0};i<path.size();i++)
            {
                if(i==0)
                    std::cout << "+++++++++\n" << MAGENTA << "starting..." << RESET << "\n";
                else
                    std::cout << MAGENTA << path[i]->action << " =>" << RESET << "\n";
                path[i]->show();
            }
        }

        int getInvCount(std::vector<int> p){
            int inv_count = 0;
            for (int i = 0; i < 8; i++) 
                for (int j = i+1; j < 9; j++)
                    if (p[j] && p[i] &&  p[i] > p[j]) 
                        inv_count++;
            return inv_count;
        }    

        bool isSolvable(std::vector<int> _puzzle){
            int invCount = getInvCount(_puzzle);
            return (invCount%2 == 0); 
        }
};

#endif
#ifndef BFS_H
#define BFS_H

#include "tree.h"
#include "node.h"
#include <iostream>
#include <deque>
#include <list>

class BFS:Tree
{
    public:
        BFS(Node _root,std::vector<int> _goalpuzzle={1,2,3,4,5,6,7,8,0})
        {
            std::cout << "bfs constructor" << "\n";
            root=_root;
            goalpuzzle=_goalpuzzle;
        }
        ~BFS(){};
        std::deque<Node> Solve()
        {
            path={};
            actions={};
            frontier={};
            explored={};

            bool findGoal = false;
            if(root.Test(goalpuzzle))
            {
                std::cout << "Primary State is Final State. Primary state is:\n";
                root.show();
                return {root};
            }
            else
            {
                frontier.push_back(root);
                while(frontier.size() > 0 && !findGoal)
                {
                    std::cout << "in while ..." << "\n";
                    Node currentNode = frontier.front();
                    explored.push_back(currentNode);
                    frontier.pop_front();
                    currentNode.generate();
                    Node currentchild;
                    
                    for(int i{};i<currentNode.children.size();i++)
                    {
                        currentchild = currentNode.children[i];
                        if(currentchild.Test(goalpuzzle))
                        {
                            std::cout << "Goal found\n";
                            findGoal = true;
                            pathtrace(currentchild);
                            showPathInfo();
                            return path;
                        }
                        if(!contains(frontier,currentchild) || !contains(explored,currentchild))
                        {
                            frontier.push_back(currentchild);
                        }
                    }

                }         
            }
            std::cout << BOLD << RED << "it has no solution" << RESET << "\n";
        }

};

#endif
#include "bfs.h"

BFS::BFS(Node _root,std::vector<int> _goalpuzzle)
{
    std::cout << "bfs constructor" << "\n";
    root=_root;
    goalpuzzle=_goalpuzzle;
}

std::vector<std::shared_ptr<Node>> BFS::Solve()
{
    path={};
    actions={};
    frontier={};

    bool findGoal = false;
    std::vector<int> goal{1,2,3,4,5,6,7,8,0};

    if(root.Test(goalpuzzle))
    {
        std::cout << GREEN_B << "Primary State is Final State. Primary state is:" << RESET << "\n";
        root.show();
        return {};
    }
    else if(!isSolvable(root.puzzle) && goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
    }
    else
    {
        frontier.push_back(std::make_shared<Node>(root));
        nfrontier.push_back(root.id);
        while(frontier.size() > 0 && !findGoal)
        {
            std::shared_ptr<Node> currentNode = frontier.front();
            int out = nfrontier.front();
            nexplored.push_back(out);
            frontier.erase(frontier.begin());
            nfrontier.erase(nfrontier.begin());
            currentNode->generate();
            std::shared_ptr<Node> currentchild;
            
            for(size_t i{};i<currentNode->children.size();i++)
            {
                currentchild = currentNode->children[i];
                if(currentchild->Test(goalpuzzle))
                {
                    std::cout << "Goal found\n";
                    pathtrace(*currentchild);
                    showPathInfo();
                    return path;
                }
                if(!contain(nexplored,currentchild->id))
                {
                    if(!contain(nfrontier,currentchild->id))
                    {
                        std::cout << "contains\n";
                        frontier.push_back(currentchild);
                        nfrontier.push_back(currentchild->id);
                    }
                }
            }
        }         
    }
    return path;
}


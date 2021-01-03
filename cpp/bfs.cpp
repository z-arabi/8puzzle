#include "bfs.h"

BFS::BFS(Node _root,std::vector<int> _goalpuzzle)
{
    root=_root;
    goalpuzzle=_goalpuzzle;
}

std::vector<std::shared_ptr<Node>> BFS::Solve()
{
    path={};
    actions={};
    frontier={};
    nfrontier={};
    nexplored={};

    if(root.Test(goalpuzzle))
    {
        std::cout << GREEN_B << "Primary State is Final State. Primary state is:" << RESET << "\n";
        root.show();
        return {std::make_shared<Node>(root)};
    }
    else if(!root.isSolvable() && goalpuzzle==goal)
    {
        return {};
    }
    else
    {
        frontier.push_back(std::make_shared<Node>(root));
        nfrontier.push_back(root.id);
        std::shared_ptr<Node> currentNode;
        std::shared_ptr<Node> currentchild;
        while(frontier.size() > 0)
        {
            currentNode = frontier.front();
            nexplored.push_back(nfrontier.front());
            frontier.erase(frontier.begin());
            nfrontier.erase(nfrontier.begin());
            currentNode->generate();
                            
            for(size_t i{};i<currentNode->children.size();i++)
            {
                currentchild = currentNode->children[i];
                if(currentchild->Test(goalpuzzle))
                {
                    std::cout << BOLD << GREEN << "Goal found" << RESET << "\n";
                    pathtrace(*currentchild);
                    showPathInfo();
                    return path;
                }
                if(!contains(nexplored,currentchild->id))
                {
                    if(!contains(nfrontier,currentchild->id))
                    {
                        frontier.push_back(currentchild);
                        nfrontier.push_back(currentchild->id);
                    }
                }
            }
        }         
    }
    return {};
}

bool BFS::contains(std::vector<int> l,int idp)
{
    auto it = std::find(l.begin(), l.end(), idp);
    if (it != l.end()) 
    {
        return true;
    }
    return false;
}

void BFS::pathtrace(Node n)
{
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
}

void BFS::showPathInfo()
{
    for(size_t i{0};i<path.size();i++)
    {
        if(i==0)
            std::cout << "+++++++++\n" << MAGENTA << "starting..." << RESET << "\n";
        else
            std::cout << MAGENTA << path[i]->action << " =>" << RESET << "\n";
        path[i]->show();
    }
    std::cout << BOLD << GREEN << "The Depth is..." << path.size()-1 << RESET << "\n";
}
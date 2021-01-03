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
        while(frontier.size() > 0)
        {
            std::shared_ptr<Node> currentNode = frontier.front();
            nexplored.push_back(nfrontier.front());
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
    return path;
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
    std::cout << GREEN << "The Depth is..." << path.size() << RESET << "\n";
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
}

int BFS::getInvCount(std::vector<int> p)
{
    int inv_count = 0;
    for (int i = 0; i < 8; i++) 
        for (int j = i+1; j < 9; j++)
            if (p[j] && p[i] &&  p[i] > p[j]) 
                inv_count++;
    return inv_count;
}    

bool BFS::isSolvable(std::vector<int> _puzzle)
{
    int invCount = getInvCount(_puzzle);
    return (invCount%2 == 0); 
}
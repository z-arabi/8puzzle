#include "dfs.h"
#include <bits/stdc++.h>

DFS::DFS(Node _root,std::vector<int> _goalpuzzle)
{
    root = _root;
    goalpuzzle=_goalpuzzle;
}

std::vector<std::shared_ptr<Node>> DFS::SolveDLS(int _limit)
{
    path={};
    actions={};
    explored={};
    nexplored={};
    nfrontier={};
    frontier={};
    frontier.push_back(std::make_shared<Node>(root));
    nfrontier.push_back(root.id);

    bool result = recDLS(std::make_shared<Node>(root),_limit);
    if(result)
        return path;
    return{};
}
 
bool DFS::recDLS(std::shared_ptr<Node> node,int l)
{
    std::cout << l << " limit when entering-----------------\n";
    node->show();
    std::shared_ptr<Node> currentNode;
    if(node->Test(goalpuzzle))
    {
        std::cout << "Goal found\n";
        std::cout << node->depth << "depth of last node \n";
        pathtrace(*node);
        showPathInfo();
        
        return true;
    }
    else if(!isSolvable(node->puzzle) && goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
        return false;
    }
    else if(l<=0)
    {
        std::cout << RED << "cut-off occured" << RESET << "\n";
        if(frontier.size()>1)
        {
            explored.push_back(frontier.back());
            nexplored.push_back(frontier.back()->id);
            nfrontier.pop_back();
            frontier.pop_back();
        }
        return false;
    }
    else if(frontier.empty())
    {
        std::cout << "reach to the end\n";
        return false;
    }
    else
    {
        std::cout << frontier.size() << " " << explored.size() << " initial check\n";
        currentNode = frontier.back();
        explored.push_back(frontier.back());
        nexplored.push_back(frontier.back()->id);
        frontier.pop_back();
        nfrontier.pop_back();
        std::cout << frontier.size() << " " << explored.size() << " second check check\n";
        currentNode->generate();
        std::shared_ptr<Node> currentchild;
        std::cout << currentNode->children.size() << " number of children\n";
        int thislevel{0};

        for(size_t i{};i<currentNode->children.size();i++)
        {
            std::cout << currentNode->depth << " " << currentNode->children[i]->depth  << " in childerns\n";
            currentchild = currentNode->children[i];
            currentchild->show();
            if(currentchild->Test(goalpuzzle))
            {
                std::cout << "Goal found\n";
                pathtrace(*currentchild);
                showPathInfo();
                return true;
            }
            if(!contains(nexplored,currentchild->id))
            {
                std::cout << "not in explored\n";
                if(!contains(nfrontier,currentchild->id))
                {
                    std::cout << "not in frontier => added to frontier\n";
                    frontier.push_back(currentchild);
                    nfrontier.push_back(currentchild->id);

                }
                else
                {
                    std::cout << explored.size() << "in frontier\n";
                    std::vector<std::shared_ptr<Node>>::iterator it_fr = std::find(frontier.begin(),frontier.end(),currentchild);
                    std::cout << "in front\n";
                    (*it_fr)->show();
                    if((*it_fr)->id > currentchild->id)
                    {
                        std::cout << "replaced in front\n";
                        frontier.push_back(currentchild);
                        nfrontier.push_back(currentchild->id);
                    }
                }
            }
            else
            {
                std::cout << explored.size() << "in explored\n";
                std::vector<std::shared_ptr<Node>>::iterator it_ex = std::find(explored.begin(),explored.end(),currentchild);
                std::cout << "in back\n";
                (*it_ex)->show();
                if((*it_ex)->id > currentchild->id)
                {
                    std::vector<int>::iterator it_nex = std::find(nexplored.begin(),nexplored.end(),currentchild->id);
                    std::cout << "replaced in back\n";
                    frontier.push_back(currentchild);
                    nfrontier.push_back(currentchild->id);
                    explored.erase(it_ex);
                    nexplored.erase(it_nex);
                }
            }
        }
        std::cout << "check5\n";
        std::reverse(currentNode->children.begin(),currentNode->children.end());
        for(int i{};i<currentNode->children.size();i++)
        {
            // currentNode->children[i]->show();
            if(contains(nfrontier,currentNode->children[i]->id))
            {
                std::cout << "check8\n";
                bool outcome = recDLS(currentNode->children[i],l-1);
                if(outcome)
                    return true;
            }
        }
        return false;
    }
}

std::vector<std::shared_ptr<Node>> DFS::SolveIDS()
{
    for (int i{};i<100;i++)
    {
        std::vector<std::shared_ptr<Node>>  result = SolveDLS(i);
        if (!result.empty())
            {
                std::cout << limit << "\n";
                return path;
            }
    }
    return {};
}
     
bool DFS::contains(std::vector<int> l,int idp)
{
    auto it = std::find(l.begin(), l.end(), idp);
    if (it != l.end()) 
    {
        return true;
    }
    return false;
}

void DFS::pathtrace(Node n)
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

void DFS::showPathInfo()
{
    // for(size_t i{0};i<path.size();i++)
    // {
    //     if(i==0)
    //         std::cout << "+++++++++\n" << MAGENTA << "starting..." << RESET << "\n";
    //     else
    //         std::cout << MAGENTA << path[i]->action << " =>" << RESET << "\n";
    //     path[i]->show();
    // }
    
    std::cout << GREEN << "The Depth is..." << path.size() << RESET << "\n";
}

int DFS::getInvCount(std::vector<int> p)
{
    int inv_count = 0;
    for (int i = 0; i < 8; i++) 
        for (int j = i+1; j < 9; j++)
            if (p[j] && p[i] &&  p[i] > p[j]) 
                inv_count++;
    return inv_count;
}    

bool DFS::isSolvable(std::vector<int> _puzzle)
{
    int invCount = getInvCount(_puzzle);
    return (invCount%2 == 0); 
}

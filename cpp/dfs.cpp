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
    std::shared_ptr<Node> currentNode;
    if(node->Test(goalpuzzle))
    {
        std::cout << BOLD << GREEN << "Goal found" << RESET << "\n";
        pathtrace(*node);
        showPathInfo();
        return true;
    }
    else if(!node->isSolvable() && goalpuzzle==goal)
    {
        return false;
    }
    else if(l<=0)
    {
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
        return false;
    }
    else
    {
        currentNode = frontier.back();
        explored.push_back(frontier.back());
        nexplored.push_back(frontier.back()->id);
        frontier.pop_back();
        nfrontier.pop_back();
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
                return true;
            }
            if(!contains(nexplored,currentchild->id))
            {
                if(!contains(nfrontier,currentchild->id))
                {
                    frontier.push_back(currentchild);
                    nfrontier.push_back(currentchild->id);
                }
                else
                {
                    std::vector<std::shared_ptr<Node>>::iterator it_fr = std::find(frontier.begin(),frontier.end(),currentchild);
                    if((*it_fr)->depth < currentchild->depth)
                    {
                        frontier.push_back(currentchild);
                        nfrontier.push_back(currentchild->id);
                    }
                }
            }
            else
            {
                std::vector<std::shared_ptr<Node>>::iterator it_ex = std::find(explored.begin(),explored.end(),currentchild);
                if((*it_ex)->depth > currentchild->depth)
                {
                    std::vector<int>::iterator it_nex = std::find(nexplored.begin(),nexplored.end(),currentchild->id);
                    frontier.push_back(currentchild);
                    nfrontier.push_back(currentchild->id);
                    explored.erase(it_ex);
                    nexplored.erase(it_nex);
                }
            }
        }
        std::reverse(currentNode->children.begin(),currentNode->children.end());
        for(size_t i{};i<currentNode->children.size();i++)
        {
            if(contains(nfrontier,currentNode->children[i]->id))
            {
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
    for (int i{};i<5000;i++)
    {
        std::vector<std::shared_ptr<Node>>  result = SolveDLS(i);
        if (!result.empty())
            {
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
    for(size_t i{0};i<path.size();i++)
    {
        if(i==0)
            std::cout << "+++++++++\n" << MAGENTA << "starting..." << RESET << "\n";
        else
            std::cout << MAGENTA << path[i]->action << " =>" << RESET << "\n";
        path[i]->show();
    }
    std::cout << GREEN << "The Depth is..." << path.size()-1 << RESET << "\n";
}
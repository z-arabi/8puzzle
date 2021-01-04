#include "A.h"
#include <iterator>

A::A(Node _root,std::vector<int> _goalpuzzle)
{
    root=_root;
    goalpuzzle=_goalpuzzle;
}

std::vector<std::shared_ptr<Node>> A::Solve()
{
    path={};
    actions={};
    frontier={};
    nfrontier={};
    explored={};
    nexplored={};
    std::vector<int> goal{1,2,3,4,5,6,7,8,0};

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
        root.findHeu();
        root.depth=0;
        frontier.push_back(std::make_shared<Node>(root));
        nfrontier.push_back(root.id);
        nexplored.push_back(root.id);
        while(frontier.size() > 0 )
        {
            std::shared_ptr<Node> currentNode = frontier.front();
            int min{frontier[0]->heuristic};
            int idd{frontier[0]->id};
            std::vector<std::shared_ptr<Node>>::iterator i{frontier.begin()};
            std::vector<std::shared_ptr<Node>>::iterator ind = i;
            
            while (i != frontier.end()) 
            {
                if (min > (*i)->heuristic)
                {
                    min = (*i)->heuristic;
                    currentNode = *i;
                    ind = i;
                    idd = (*ind)->id;
                }   
                i++;         
            }
            std::vector<int>::iterator itr = std::find(nfrontier.begin(),nfrontier.end(),idd);
            explored.push_back(*ind);
            nexplored.push_back(idd);
            frontier.erase(ind);
            nfrontier.erase(itr);
            currentNode->generate();
            std::shared_ptr<Node> currentchild;

            for(size_t i{};i<currentNode->children.size();i++)
            {
                currentNode->children[i]->findHeu();
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
                     else
                    {
                        std::vector<std::shared_ptr<Node>>::iterator it_fr = std::find(frontier.begin(),frontier.end(),currentchild);
                        std::vector<int>::iterator it_nfr = std::find(nfrontier.begin(),nfrontier.end(),currentchild->id);
                        if((*it_fr)->heuristic > currentchild->heuristic)
                        {
                            frontier.erase(it_fr);
                            nfrontier.erase(it_nfr);
                            frontier.push_back(currentchild);
                            nfrontier.push_back(currentchild->id);
                        }
                    }
                }  
                else
                {
                    std::vector<std::shared_ptr<Node>>::iterator it_ex = std::find(explored.begin(),explored.end(),currentchild);
                    if((*it_ex)->heuristic > currentchild->heuristic)
                    {
                        std::vector<int>::iterator it_nex = std::find(nexplored.begin(),nexplored.end(),currentchild->id);
                        frontier.push_back(currentchild);
                        nfrontier.push_back(currentchild->id);
                        explored.erase(it_ex);
                        nexplored.erase(it_nex);
                    }
                }
            }
        }         
    }
    return path;
}


bool A::contains(std::vector<int> l,int idp)
{
    auto it = std::find(l.begin(), l.end(), idp);
    if (it != l.end()) 
    {
        return true;
    }
    return false;
}

void A::pathtrace(Node n)
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

void A::showPathInfo()
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
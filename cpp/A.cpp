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
    nexplored={};
    std::vector<int> goal{1,2,3,4,5,6,7,8,0};

    if(root.Test(goalpuzzle))
    {
        std::cout << GREEN_B << "Primary State is Final State. Primary state is:" << RESET << "\n";
        root.show();
        return {};
    }
    else if(!root.isSolvable() && goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
    }
    else
    {
        root.findHeu();
        root.depth=0;
        frontier.push_back(std::make_shared<Node>(root));
        nfrontier.push_back(root.id);
        nexplored.push_back(root.id);
        int c = 0;
        while(frontier.size() > 0 )
        {
            c++;
            std::cout << "inwhile\n";
            std::shared_ptr<Node> currentNode = frontier.front();
            int min{frontier[0]->heuristic};
            int idd{frontier[0]->id};
            std::vector<std::shared_ptr<Node>>::iterator i{frontier.begin()};
            std::vector<std::shared_ptr<Node>>::iterator ind = i;
            
            while (i != frontier.end()) 
            { 
                // std::cout << min << " " << (*i)->heuristic << " " << c <<"\n";
                if (min > (*i)->heuristic)
                {
                    min = (*i)->heuristic;
                    currentNode = *i;
                    ind = i;
                    idd = (*ind)->id;
                    std::cout << idd << " min changed\n";
                }   
                i++;         
            }
            std::vector<int>::iterator itr = std::find(nfrontier.begin(),nfrontier.end(),idd);
            // std::cout << *itr << " iterator number\n";
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
        // std::cout << *it << "contains\n";
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
    std::cout << GREEN << "The Depth is..." << path.size()-1 << RESET << "\n";
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
}
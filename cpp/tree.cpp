#include "tree.h"
#include "color.h"
#include<iterator> // for iterators 
#include<vector> // for vectors 

bool Tree::contains(std::vector<std::shared_ptr<Node>> l,Node c)
{
    std::vector<std::shared_ptr<Node>>::iterator ptr;
    // for(size_t i = 0;i<l.size();i++)
    // {
    //     if(l[i].puzzle==c.puzzle)
    //     {
    //         return true;
    //     }
    // }
    for (ptr = l.begin(); ptr < l.end(); ptr++) 
    {
        if((*ptr)->puzzle == c.puzzle)
            return true;
    }
    return false;
}

int Tree::getInvCount(std::vector<int> p,int _s) 
{ 
    int inv_count = 0; 
    int s = _s;
    for (int i = 0; i < s-1; i++) 
        for (int j = i+1; j < s; j++)
            if (p[j] && p[i] &&  p[i] > p[j]) 
                inv_count++; 
    // std::cout << inv_count << "\n";
    return inv_count; 
} 

bool Tree::isSolvable(std::vector<int> _puzzle,int _s) 
{
    int invCount = getInvCount(_puzzle,_s);
    // std::cout << invCount << "\n";
    return (invCount%2 == 0); 
}

void Tree::pathtrace(Node n)
{
    // std::cout << "tracing path...\n";
    path = {};
    actions = {};
    // std::shared_ptr<Node> current(new Node);
    auto current = std::make_shared<Node>(&n);
    path.push_front(current);
    Node comp{};
    while(current->parent.size()!=0)
    {
        current = current->parent[0];
        path.push_front(current);
    }
    std::cout << GREEN << "The Depth is..." << path.size() << RESET << "\n";
}

void Tree::showPathInfo()
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


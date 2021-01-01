#include "tree.h"

bool Tree::contains(std::deque<Node> l,Node c)
{
    // std::cout << "contains..." << l.size() << "\n";
    for(size_t i = 0;i<l.size();i++)
    {
        // l[i].show();
        if(l[i].puzzle==c.puzzle)
        {
            // std::cout << "equal\n";
            return true;
        }
    }
    // std::cout << "contains finished\n";
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
    std::cout << "tracing path...\n";
    path = {};
    actions = {};
    Node current = n;
    path.push_front(current);
    Node comp{};
    while(current.parent.size()!=0)
    {
        current = current.parent[0];
        path.push_front(current);
    }
    std::cout << path.size() << "\n";
}

void Tree::showPathInfo()
{
    for(size_t i{0};i<path.size();i++)
    {
        if(i==0)
            std::cout << "+++++++++\n" << MAGENTA << "starting..." << RESET << "\n";
        else
            std::cout << MAGENTA << path[i].action << " =>" << RESET << "\n";
        path[i].show();
    }
}


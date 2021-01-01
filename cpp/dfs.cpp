#include "dfs.h"

DFS::DFS(Node _root,int _limit,std::vector<int> _goalpuzzle):limit{_limit}
{
    Tree::root = _root;
    Tree::goalpuzzle=_goalpuzzle;
    test=limit;
}

std::deque<Node> DFS::Solve()
{
    std::vector<int> goal{1,2,3,4,5,6,7,8,0};
    if(!Tree::isSolvable(Tree::root.puzzle,Tree::root.size) && Tree::goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
    }
    else
    {
        std::cout << "!!!!!!!\n";
    }
    
}
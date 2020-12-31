#include "bfs.h"

BFS::BFS(Node _root,std::vector<int> _goalpuzzle)
{
    // std::cout << "bfs constructor" << "\n";
    Tree::root=_root;
    Tree::goalpuzzle=_goalpuzzle;
}

std::deque<Node> BFS::Solve()
{
    Tree::path={};
    Tree::actions={};
    Tree::frontier={};
    Tree::explored={};

    bool findGoal = false;
    std::vector<int> goal{1,2,3,4,5,6,7,8,0};

    if(root.Test(Tree::goalpuzzle))
    {
        std::cout << GREEN_B << "Primary State is Final State. Primary state is:" << RESET << "\n";
        root.show();
        return {Tree::root};
    }
    else if(!isSolvable(root.puzzle,root.size) && goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
    }
    else
    {
        frontier.push_back(root);
        while(frontier.size() > 0 && !findGoal)
        {
            std::cout << "in while ..." << "\n";
            Node currentNode = frontier.front();
            explored.push_back(currentNode);
            frontier.pop_front();
            currentNode.generate();
            Node currentchild;
            
            for(size_t i{};i<currentNode.children.size();i++)
            {
                currentchild = currentNode.children[i];
                if(currentchild.Test(goalpuzzle))
                {
                    std::cout << "Goal found\n";
                    Tree::pathtrace(currentchild);
                    Tree::showPathInfo();
                    return path;
                }
                if(!Tree::contains(frontier,currentchild) || !Tree::contains(explored,currentchild))
                {
                    frontier.push_back(currentchild);
                }
            }

        }         
    }
    return path;
}


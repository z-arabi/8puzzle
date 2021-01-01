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

    if(Tree::root.Test(Tree::goalpuzzle))
    {
        std::cout << GREEN_B << "Primary State is Final State. Primary state is:" << RESET << "\n";
        Tree::root.show();
        return {Tree::root};
    }
    else if(!Tree::isSolvable(Tree::root.puzzle,root.size) && Tree::goalpuzzle==goal)
    {
        std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
    }
    else
    {
        Tree::frontier.push_back(Tree::root);
        while(Tree::frontier.size() > 0 && !findGoal)
        {
            // std::cout << "in while ..." << "\n";
            Node currentNode = Tree::frontier.front();
            // currentNode.show();
            Tree::explored.push_back(currentNode);
            Tree::frontier.pop_front();
            currentNode.generate();
            Node currentchild;
            
            for(size_t i{};i<currentNode.children.size();i++)
            {
                currentchild = currentNode.children[i];
                if(currentchild.Test(Tree::goalpuzzle))
                {
                    std::cout << "Goal found\n";
                    Tree::pathtrace(currentchild);
                    Tree::showPathInfo();
                    return Tree::path;
                }
                if(!(Tree::contains(Tree::frontier,currentchild) || Tree::contains(Tree::explored,currentchild)))
                {
                    Tree::frontier.push_back(currentchild);
                }
            }
        }         
    }
    return Tree::path;
}


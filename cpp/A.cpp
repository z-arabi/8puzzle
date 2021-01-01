#include "A.h"
#include <iterator>

A::A(Node _root,std::vector<int> _goalpuzzle)
{
    Tree::root=_root;
    Tree::goalpuzzle=_goalpuzzle;
}

std::deque<Node> A::Solve()
{
    Tree::path={};
    Tree::actions={};
    Tree::frontier={};
    Tree::explored={};

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
        Tree::root.findHeu();
        Tree::frontier.push_back(Tree::root);
        // std::cout << root.heuristic << "\n";
        while(Tree::frontier.size() > 0)
        { 
            // std::cout << "in while ..." << "\n";
            Node currentNode = frontier[0];
            int min = frontier[0].heuristic;
            // int ind{0};
            std::deque<Node>::iterator i;
            std::deque<Node>::iterator ind; 
            i = frontier.begin();
            ind = i;
            while (i != frontier.end()) 
            { 
                if (min > i->heuristic)
                {
                    // std::cout << "changing...\n";
                    min = i->heuristic;
                    currentNode = *i;
                    ind = i;
                }   
                i++;         
            }
            Tree::frontier.erase(ind);
            // currentNode.show();
            Tree::explored.push_back(currentNode);
            // Tree::frontier.erase(ind);
            currentNode.generate();
            Node currentchild;
            for(size_t i{};i<currentNode.children.size();i++)
            {
                currentNode.children[i].findHeu();
                currentchild = currentNode.children[i];
                if(currentchild.Test(Tree::goalpuzzle))
                {
                    std::cout << "Goal found\n";
                    Tree::pathtrace(currentchild);
                    Tree::showPathInfo();
                    return Tree::path;
                }
                // bool f=0;
                // bool e = 0;
                // if(Tree::contains(Tree::frontier,currentchild))
                // {
                //     f = 1;
                // }
                // if(Tree::contains(Tree::explored,currentchild))
                // {
                //     /* check the heu of previous ones */
                //     Tree::frontier.push_back(currentchild);
                // }
                if(!(Tree::contains(Tree::frontier,currentchild) || Tree::contains(Tree::explored,currentchild)))
                {
                    Tree::frontier.push_back(currentchild);
                }
            }
        }         
    }
    return Tree::path;
}
    
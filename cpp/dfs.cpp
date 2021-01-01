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
    }else
    {
        Tree::path={};
        Tree::actions={};
        Tree::frontier={};
        Tree::explored={};
        depth={};
        if(Tree::root.Test(Tree::goalpuzzle))
        {
            std::cout << "Goal found\n";
            Tree::pathtrace(Tree::root);
            Tree::showPathInfo();
            return Tree::path;
        }else
        {
            // Tree::frontier.push_front(Tree::root);
            // Node currentNode = Tree::frontier.front();
            // currentNode.show();
            Tree::explored.push_back(Tree::root);
            // Tree::frontier.pop_front();
            bool result = DFS::recDLS(Tree::root,limit,depth);
            if(result)
                return Tree::path;
        }        
    }
    return {};
}

bool DFS::recDLS(Node node,int l,int d)
{
    if(limit<=0)
    {
        std::cout << BOLD << "cut-off occured" << RESET << "\n";    
        return false;
    }
    else if(!Tree::frontier.size())
    {
        std::cout << BOLD << "no solution" << RESET << "\n";
        return false;
    }
    else
    {
        // std::cout << "in recurssion\n";
        // Node currentNode = Tree::frontier.front();
        // currentNode.show();
        // Tree::explored.push_back(currentNode);
        // Tree::frontier.pop_front();
        node.generate();
        for(size_t i{};i<node.children.size();i++)
        {
            // currentNode.children[i].show();
            Node currentchild = node.children[i];
            if(currentchild.Test(Tree::goalpuzzle))
            {
                std::cout << "Goal found\n";
                Tree::pathtrace(Tree::root);
                Tree::showPathInfo();
                return true;
            }else
            {
                if(!Tree::contains(Tree::frontier,currentchild) && !Tree::contains(Tree::explored,currentchild))
                {
                    // std::cout << "frontier size " << Tree::frontier.size() << "\n";
                    // std::cout << "explored size " << Tree::explored.size() << "\n";
                    // node.children[i].show();
                    Tree::frontier.push_front(currentchild);
                }
            }
        }
        for(size_t i{};i<node.children.size();i++)
        {
            // Node currentchild = currentNode.children[currentNode.children.size()-i-1];
            Node currentNode = Tree::frontier.front();
            // currentNode.show();
            Tree::explored.push_back(currentNode);
            Tree::frontier.pop_front();
            bool outcome = DFS::recDLS(currentNode.children[i],limit--,depth++);
            if(outcome)
            {
                return true;
            }   
        }
        // std::cout << "print childrens ends " << frontier.size() << "\n";
        // for(size_t i{};i<currentNode.children.size();i++)
        // {
        //     Node currentchild = currentNode.children[i];
        //     // Node currentchild = frontier[i];
        //     // limit --;
        //     // depth ++;
           
        // }
    }
    return false;
}


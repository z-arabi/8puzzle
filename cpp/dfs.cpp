// #include "dfs.h"

// DFS::DFS(Node _root,int _limit,std::vector<int> _goalpuzzle):limit{_limit}
// {
//     Tree::root = _root;
//     Tree::goalpuzzle=_goalpuzzle;
//     test=limit;
// }

// std::deque<Node> DFS::Solve()
// {
//     std::vector<int> goal{1,2,3,4,5,6,7,8,0};
//     if(!Tree::isSolvable(Tree::root.puzzle,Tree::root.size) && Tree::goalpuzzle==goal)
//     {
//         std::cout << LIGHTCYAN_B << BOLD << RED << "it has no solution" << RESET << "\n";
//     }else
//     {
//         Tree::path={};
//         Tree::actions={};
//         Tree::frontier={};
//         Tree::explored={};
//         depth={};
//         Tree::frontier.push_front(Tree::root);
//         bool result = DFS::recDLS(Tree::root,limit,depth);
//         if(result)
//             return Tree::path;
//     }
//     return {};
// }

// bool DFS::recDLS(Node node,int l,int d)
// {
//     std::cout << "limit is " << limit << "\n";
//     if(node.Test(Tree::goalpuzzle))
//     {
//         std::cout << "Goal found\n";
//         Tree::pathtrace(node);
//         Tree::showPathInfo();
//         return true;
//     }
//     else if(limit<=0)
//     {
//         std::cout << BOLD << "cut-off occured" << RESET << "\n";    
//         return false;
//     }
//     else if(!Tree::frontier.size())
//     {
//         std::cout << BOLD << "no solution" << RESET << "\n";
//         return false;
//     }
//     else
//     {
//         Node currentNode = Tree::frontier.front();
//         Tree::explored.push_back(currentNode);
//         Tree::frontier.pop_front();
//         currentNode.generate();
//         for(size_t i{};i<currentNode.children.size();i++)
//         {
//             Node currentchild = currentNode.children[i];
//             if(!Tree::contains(Tree::frontier,currentchild) && !Tree::contains(Tree::explored,currentchild))
//             {
//                 Tree::frontier.push_front(currentchild);
//             }
//         }
//         for(size_t i{};i<currentNode.children.size();i++)
//         {
//             Node currentchild = currentNode.children[currentNode.children.size()-i-1];
//             bool outcome = DFS::recDLS(currentchild,limit--,depth++);
//             if(outcome)
//             {
//                 return true;
//             }   
//         }
//     }
//     return false;
// }

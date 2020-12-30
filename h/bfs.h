// #ifndef BFS_H
// #define BFS_H

// #include "tree.h"
// #include "node.h"
// #include <iostream>
// #include <deque>
// #include <list>

// class BFS
// {
//     public:
//         BFS(Node _root):root{_root}
//         {
//             std::cout << "bfs constructor" << "\n";
//             // for(int i=0;i<9;i++)
//             // {
//             //     std::cout << _root.puzzle[i] << "*";
//             // }
//             // std::cout << std::endl;
//             root.show();
//         }
//         ~BFS(){};
//         std::deque<Node> Solve()
//         {
//             path={};
//             frontier={};
//             explored={};
//             // bool findGoal=root.test();
//             // if(findGoal)
//             // std::cout << "entrance of Solve" << "\n";

//             bool findGoal = false;
//             if(root.Test())
//             {
//                 std::cout << "Primary State is Final State\n";
//             }
//             else
//             {
//                 frontier.push_back(root);
//                  while(frontier.size() > 0 && !findGoal)
//                 {
//                     std::cout << "in while ..." << "\n";
//                     Node currentNode = frontier.front();
//                     explored.push_back(currentNode);
//                     frontier.pop_front();

//                     currentNode.generate();
//                     // for (int i=0;i<currentNode.children.size();i++)
//                     // {
//                     //     currentNode.children[i].show();
//                     // } 

//                     for(int i{};i<currentNode.children.size();i++)
//                     {
//                         Node currentchild = currentNode.children[i];
//                         // currentNode.children[i].parent->show();
//                         // currentchild.parent->show();
//                         if(currentchild.Test())
//                         {
//                             std::cout << "Goal found\n";
//                             findGoal = true;
//                             currentNode.show();
//                             currentchild.show();
//                             // currentchild.parent->show();
//                             currentchild.parent[0].show();
//                             pathtrace(currentchild);
//                             break;
//                         }
//                         if(!contains(frontier,currentchild) && !contains(explored,currentchild))
//                         {
//                             frontier.push_back(currentchild);
//                         }
//                     }

//                 }         
//             }
//             // std::cout << path.size() << "\n";
//             return path;
//         }

//         bool contains(std::deque<Node> l,Node c)
//         {
//             bool contain = false;
//             std::cout << "contains..." << l.size() << "\n";
//             // if(l.size())
//             //     l[0].show();
//             for(int i = 0;i<l.size();i++)
//             {
//                 // if (l[i].sameNode(c.puzzle))
//                 // {
//                 //     contain = true;
//                 //     break;
//                 // }
//                 for(int j{};j<9;j++)
//                 {
//                     if(l[i].puzzle[j] == c.puzzle[j])
//                     {
//                         contain = false;
//                         break;
//                     }
//                 }
//             }
//             return contain;
//         }
    
//         void pathtrace(Node n)
//         {
//             std::cout << "tracing path...\n";
//             path = {};
//             Node n2{};
//             Node current = n;
//             Node c = n;
//             path.push_front(current);
//             current.show();
//             // current.parent->show();
//             current.parent[0].show();
//             while(current.parent.size())
//             {
//                 std::cout << "before\n";
//                 current.show();
//                 // current.parent->show();
//                 current.parent[0].show();
//                 std::cout << current.children.size() << "\n";
//                 current.children[0].show();
//                 // current = *(current.parent);
//                 current = current.parent[0];
//                 // c.puzzle = current.parent->puzzle;
//                 // c.children =  current.parent->children;
//                 // c.ind0 =  current.parent->ind0;
//                 // c.parent = current.parent->parent;
//                 // current = c;
//                 // current.puzzle = current.parent->puzzle;
//                 // current.children =  current.parent->children;
//                 // current.ind0 =  current.parent->ind0;
//                 // current.parent = current.parent->parent;
//             //     // current =  std::move(*(current.parent));
//                 // current = *(current.parent);
//             //     // current = c;
//             //     // current.parent = c.parent->parent;
//                 std::cout << "after\n";
//                 current.show();
//                 // current.parent->show();
//                 current.parent[0].show();
//                 std::cout << current.children.size() << "\n";
//                 current.children[0].show();

//                 // current.parent = nullptr;
//             //     // current.show();
//                 path.push_front(current);
//             //     std::cout << "in while\n";
                
//             }
//             std::cout << path.size() << "\n";
//         }

//     private:
//         Node root;
//         std::deque<Node> path{};
//         std::deque<Node> frontier{};
//         std::deque<Node> explored{};
//         std::deque<std::string> actions{};
//         int* goalarray{new int[root.size]};
        


// };

// #endif
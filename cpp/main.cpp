#include <iostream>
#include "tree.h"
#include "midterm.h"
#include "bfs.h"
#include "dfs.h"
#include "node.h"
#include <vector>
#include <string>

int main()
{
    std::cout << "hello world\n";

    /* Test 1 */
    std::vector<int> s0{1,2,3,4,0,6,7,5,8};
    std::vector<int> s1{1,2,3,4,6,0,7,5,8};
    std::vector<int> s13{1,2,0,4,6,3,7,5,8};
    Node root{s0};
    Node child1{s1};
    Node child13{s13};
    root.generate();
    for(auto i:root.children)
    {
        i.show();
    }
    root.children[0].parent->show();
    // child1.parent = &root;
    // Node child2 = child1;
    // std::cout << child1.parent->puzzle[5] << std::endl;
    // std::cout << child2.parent->puzzle[5] << std::endl;
    // Node grandchild{s2};
    // child1.children[0] = grandchild;
    // grandchild.parent = &child1;
    // std::cout << grandchild.parent->puzzle[3] << std::endl;
    // std::cout << grandchild.parent->parent->puzzle[3] << std::endl;
    

    // int* s0{new int[9]};
    // for(int i=0;i<9;i++)
    // {
    //     std::cout << "Enter the " << i+1 << "'s number: ";
    //     std::cin >> s0[i];,
    // }
    // std::deque<int> s0{1,2,3,4,0,6,7,5,8};
    // int s0[]{1,2,3,4,0,6,7,5,8};
    // std::cout << "\npuzzle size " << sizeof(s0) << "\n";
    // std::deque<int> s0{1,2,3,4,5,6,7,0,8};
    // Node root{s0};
    // root.show();
    // root.generate();
    // for(int i{};i<root.children.size();i++)
    // {
    //     root.children[i].show();
    //     std::cout << "\n";
    // }
    
    // root.children[0].parent->show();
    // BFS bfs{root};
    // std::deque<Node> solution = bfs.Solve();
    // if(solution.size() > 0)
    // {
    //     for (int i{};i<solution.size();i++)
    //     {
    //         solution[i].show();
    //         std::cout << "***\n";
    //     }
    // }
    // else
    // {
    //     std::cout << "no path to solution found\n";
    // } 
    // std::cout << s0 << "\n";
    // int goal[]{1,2,3,4,5,6,7,8,0}
    return 0;
}

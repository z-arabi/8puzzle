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
    std::vector<int> s0{1,2,3,4,0,6,5,7,8};
    std::vector<int> s1{1,2,3,4,6,0,5,7,8};
    std::vector<int> s13{1,2,0,4,6,3,5,7,8};
    Node root{s0};
    root.generate();
    for(auto i:root.children)
    {
        i.show();
    }
    root.children[0].parent->show();
    Node child1 = root.children[0];
    child1.parent->show();
    child1.generate();
    Node child13 = child1.children[0];
    child13.parent->show();
    child13.parent->parent->show();
    if( child13 != child1 )
        std::cout << "NOTequal" << "\n";    

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

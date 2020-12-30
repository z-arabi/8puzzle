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
    /* Test 1 */
    // std::vector<int> s0{1,2,3,4,0,6,5,7,8};
    // std::vector<int> s1{1,2,3,4,6,0,5,7,8};
    // std::vector<int> s13{1,2,0,4,6,3,5,7,8};
    // Node root{s0};
    // root.generate();
    // for(auto i:root.children)
    // {
    //     i.show();
    //     Node child = i;
    // }
    // root.children[0].parent->show();
    // Node child1 = root.children[0];
    // child1.parent->show();
    // child1.generate();
    // Node child13 = child1.children[0];
    // child13.parent->show();
    // child13.parent->parent->show();
    // if( child13 != child1 )
    //     std::cout << "NOTequal" << "\n";

    /* Test2 */
    // std::vector<int> s0{1,2,3,4,0,6,7,5,8};
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    Node root{s0};
    BFS bfs{root};
    std::deque<Node> solution = bfs.Solve();

    return 0;
}

#include <iostream>
#include "tree.h"
#include "midterm.h"
#include "bfs.h"
#include "dfs.h"
#include "node.h"
#include <vector>
#include <string>
#include "A.h"

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

    /* Test 2 - inversion10 - solvable - depth10 - seconds*/
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    // Node root{s0};
    // BFS bfs{root};
    // std::deque<std::shared_ptr<Node>> solution = bfs.Solve();

    /* inversion19 - notsolvable*/
    // std::vector<int> s0{8,5,6,4,2,1,0,3,7};
    // Node root{s0};
    // BFS bfs{root};
    // std::deque<Node> solution = bfs.Solve();

    /* inversion20 - solvable - bfs can't */
    std::vector<int> s0{8,5,6,4,2,1,0,7,3};
    Node root{s0};
    BFS bfs{root};
    std::deque<std::shared_ptr<Node>> solution = bfs.Solve();

    /* inversion2 - solvable - depth*/
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // Node root{s0};
    // BFS bfs{root};
    // std::deque<Node> solution = bfs.Solve();

    /* Test4 */
    // std::vector<int> s0{1,2,3,4,5,6,7,8,0};
    // Node root{s0};
    // BFS bfs{root};
    // std::deque<Node> solution = bfs.Solve();

    /* Test5 */
    // std::vector<int> s0{1,0,2,3,4,5,6,7,8};
    // std::vector<int> goal{0,1,2,3,4,5,6,7,8};
    // Node root{s0};
    // BFS bfs{root,goal};
    // std::deque<Node> solution = bfs.Solve();

    /* Test6 */
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // std::vector<int> goal{2,0,4,1,8,5,7,3,6};
    // Node root{s0};
    // BFS bfs{root,goal};
    // std::deque<Node> solution = bfs.Solve();

    /* Test7 */
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // std::vector<int> goal{0,1,2,3,4,5,6,7,8};
    // Node root{s0};
    // BFS bfs{root,goal};
    // std::deque<Node> solution = bfs.Solve();

    /* Test 2 - inversion10 - solvable - depth10 - seconds*/
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    // Node root{s0};
    // BFS bfs{root};
    // std::deque<Node> solution = bfs.Solve();

    // /* Test5 */
    // std::vector<int> s0{1,0,2,3,4,5,6,7,8};
    // std::vector<int> goal{0,1,2,3,4,5,6,7,8};
    // Node root{s0};
    // BFS bfs{root,goal};
    // std::deque<Node> solution = bfs.Solve();

    /* Test8 */
    // std::vector<int> s0{1,2,3,4,5,6,7,0,8};
    // Node root{s0};
    // DFS dfs{root,5};
    // std::deque<Node> solution = dfs.Solve();

    /* Test9 */
    // std::vector<int> s0{8,5,6,4,2,1,0,7,3};
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // Node root{s0};
    // A astar{root};
    // std::deque<Node> solution = astar.Solve();

    return 0;
}


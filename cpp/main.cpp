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
    //     i->show();
    //     std::shared_ptr<Node> child{i};
    // }
    // root.children[0]->parent[0]->show();
    // std::cout << root.depth << " " << root.children[0]->depth << "\n";
    // std::shared_ptr<Node> child1 = root.children[0];
    // std::cout << child1->depth << "\n";
    // child1.parent->show();
    // child1.generate();
    // Node child13 = child1.children[0];
    // child13.parent->show();
    // child13.parent->parent->show();
    // if( child13 != child1 )
    //     std::cout << "NOTequal" << "\n";

    /* bst fisrt is last */
    // std::vector<int> s0{1,2,3,4,5,6,7,8,0};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* Test 2 - inversion10 - solvable - depth10 */
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* inversion19 - notsolvable*/
    // std::vector<int> s0{8,5,6,4,2,1,0,3,7};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<Node> solution = bfs.Solve();

    /* inversion20 - solvable - bfs - depth27 */
    // std::vector<int> s0{8,5,6,4,2,1,0,7,3};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* inversion2 - solvable - bfs - depth23*/
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* solvable - bfs - depth24*/
    // std::vector<int> s0{8,7,4,6,5,1,3,0,2};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* solvable - bfs - depth29*/
    // std::vector<int> s0{0,8,7,6,5,4,3,2,1};
    // Node root{s0};
    // BFS bfs{root};
    // std::vector<std::shared_ptr<Node>> solution = bfs.Solve();

    /* solvable - a* - depth25 */
    // std::vector<int> s0{1,2,4,3,0,5,7,6,8};
    // Node root{s0};
    // A astar{root};
    // std::vector<std::shared_ptr<Node>> solution = astar.Solve();

    /* solvable - a* - depth10 */
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    // Node root{s0};
    // A astar{root};
    // std::vector<std::shared_ptr<Node>> solution = astar.Solve();

    /* solvable - a* - depth29 */
    // std::vector<int> s0{0,8,7,6,5,4,3,2,1};
    // Node root{s0};
    // A astar{root};
    // std::vector<std::shared_ptr<Node>> solution = astar.Solve();

    /* solvable - a* - fisrt is last*/
    // std::vector<int> s0{1,2,3,4,5,6,7,8,0};
    // Node root{s0};
    // A astar{root};
    // std::vector<std::shared_ptr<Node>> solution = astar.Solve();

    /* Test8 */
    // std::vector<int> s0{1,2,3,4,5,6,7,0,8};
    // Node root{s0};
    // DFS dfs{root};
    // std::vector<std::shared_ptr<Node>> solution = dfs.SolveDLS(10);

    /* dls */
    // std::vector<int> s0{1,2,3,4,5,6,7,8,0};
    // std::vector<int> s0{1,2,3,4,0,5,7,8,6};
    std::vector<int> s0{0,8,7,6,5,4,3,2,1};
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    Node root{s0};
    DFS dfs{root};
    // std::vector<std::shared_ptr<Node>> solution = dfs.SolveDLS(11);
    std::vector<std::shared_ptr<Node>> solution = dfs.SolveIDS();

    return 0;
}


#include <iostream>
#include "tree.h"
#include "midterm.h"
#include "bfs.h"
#include "dfs.h"
#include "node.h"
#include <vector>
#include <string>
#include "A.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
    // std::vector<int> s0{0,8,7,6,5,4,3,2,1};
    // std::vector<int> s0{1,8,2,0,4,3,7,6,5};
    // Node root{s0};
    // DFS dfs{root};
    // std::vector<std::shared_ptr<Node>> solution = dfs.SolveDLS(11);
    // std::vector<std::shared_ptr<Node>> solution = dfs.SolveIDS();
    // .............Welcome.............
    // Please choose one of the options: 
    // The key is incorrect try again   
    // Let's create a puzzle!           
    //     a. create random puzzle      
    //     b. enter a desired puzzle    

    
    std::system("clear");
    std::cout << LIGHTBLUE_B << BOLD << ".............Welcome.............\n" << "Let's create a puzzle!           \n"
            << "    a. create random puzzle      \n" << "    b. enter a desired puzzle    \n" << RESET << "\n" 
            << BOLD <<  "Please choose one of the options: \n" << RESET;
    char ch=getchar();
    while(!(ch=='a' || ch=='b'))
    {
        std::cout << BOLD << RED << "The key is incorrect try again   \n" << RESET ;
        ch=getchar();        
    }
    std::vector<int> puzzle0{1,2,3,4,5,6,7,8,0};
    Node root;
    if(ch=='a')
    {
        int number;
        std::cout << BOLD <<  "Nmber of random moves: \n" << RESET; 
        std::cin >> number;
        bool issolve{false};
        while(!issolve)
        {
            for(int i{};i<number;i++)
            {
                std::random_shuffle(puzzle0.begin(),puzzle0.end());
            }
            root.setValue(puzzle0);
            if(root.isSolvable())
                issolve=true;       
        }
        std::cout << "\n";
    }
    else if (ch=='b')
    {
        std::string s{};
        std::cout << BOLD <<  "Enter your puzzle: \n" << RESET; 
        std::getline(std::cin,s,'*');
        std::istringstream is{s};
        is >> puzzle0[0] >> puzzle0[1] >> puzzle0[2] >> puzzle0[3] >> puzzle0[4] >> puzzle0[5] >> puzzle0[6] >> puzzle0[7] >> puzzle0[8];
    }

    std::cout << LIGHTBLUE_B << BOLD << "Let's define a goal!             " << RESET << "\n";
    std::cout << LIGHTBLUE_B << BOLD << "    a. enter goal puzzle         " << RESET << "\n";
    std::cout << LIGHTBLUE_B << BOLD << "    b. use initial goal          " << RESET << "\n\n";
    std::cout << BOLD <<  "Please choose one of the options:  " << RESET ;
    while((ch=getchar())!= '\n') {}
    std::cout << "\n";
    ch=getchar();
    std::vector<int> goalpuzzle{1,2,3,4,5,6,7,8,0};
    while(!(ch=='a' || ch=='b'))
    {
        std::cout << BOLD << RED << "The key is incorrect try again   \n" << RESET ;
        ch=getchar();        
    }
    if(ch=='a')
    {
        std::string s{};
        std::cout << BOLD <<  "Enter your puzzle: \n" << RESET; 
        std::getline(std::cin,s,'*');
        std::istringstream is{s};
        is >> goalpuzzle[0] >> goalpuzzle[1] >> goalpuzzle[2] >> goalpuzzle[3] >> goalpuzzle[4] >> goalpuzzle[5] >> goalpuzzle[6] >> goalpuzzle[7] >> goalpuzzle[8];
    
    }

    std::system("clear");
    std::cout << YELLOW_B << BOLD << BLACK  << "Well done! your puzzle is created                           \n";
    std::cout << BOLD << "the initial state is:   ";
    for(auto i:puzzle0)
    {
        std::cout << i << "   ";
    }
    std::cout << "\n";
    std::cout << BOLD << "the final state is:     ";
    for(auto i:goalpuzzle)
    {
        std::cout << i  << "   ";
    }
    std::cout << RESET << "\n\n";

    std::cout << YELLOW_B << BOLD << BLACK <<  "It's time to choose your algorithm                          \n"
            << "    a. BFS                                                  \n" << "    b. DLS                                                  \n" 
            << "    c. IDS                                                  \n" << "    d. A*                                                   \n" 
            << RESET << "\n" << BOLD <<  "Please choose one of the options:  \n" << RESET;
    while((ch=getchar())!= '.') {}
    ch=getchar();
    while(!(ch=='a' || ch=='b'|| ch=='c' || ch=='d'))
    {
        std::cout << BOLD << RED << "The key is incorrect try again   \n" << RESET ;
        ch=getchar();        
    }
    std::vector<std::shared_ptr<Node>> solution;
    if(ch=='a')
    {
        BFS bfs{root,goalpuzzle};
        solution = bfs.Solve();
    }
    else if(ch=='b')
    {
        int lim;
        std::cout << BOLD <<  "The limit for DLs: \n" << RESET; 
        std::cin >> lim;
        DFS dfs{root,goalpuzzle};
        solution = dfs.SolveDLS(lim);
    }
    else if(ch=='c')
    {
        DFS dfs{root,goalpuzzle};
        solution = dfs.SolveIDS();
    }
    else if(ch=='d')
    {
        A astar{root,goalpuzzle};
        solution = astar.Solve();
    }
     
    return 0;
}


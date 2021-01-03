#include "midterm.h"

void makePuzzle(std::vector<int> &puzzle0,std::vector<int> &goalpuzzle,Node &root)
{
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
        root.setValue(puzzle0);
    }

    std::cout << LIGHTBLUE_B << BOLD << "Let's define a goal!             " << RESET << "\n";
    std::cout << LIGHTBLUE_B << BOLD << "    a. enter goal puzzle         " << RESET << "\n";
    std::cout << LIGHTBLUE_B << BOLD << "    b. use initial goal          " << RESET << "\n\n";
    std::cout << BOLD <<  "Please choose one of the options:  " << RESET ;
    
    while((ch=getchar())!= '\n') {}
    std::cout << "\n";
    ch=getchar();

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
}

void solvePuzzle(std::vector<int> puzzle0,std::vector<int> goalpuzzle,Node root)
{
    std::system("clear");
    std::cout << LIGHTRED << BOLD << "you can enter (q) to go to menu"  << RESET << "\n\n";
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
            << RESET << "\n" << BOLD <<  "Please choose one of the options:  " << RESET << "\n";
    
    char ch;
    while((ch=getchar())!= '\n') {}
    std::cout << "\n";
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
        std::cout << "It will be solved in a second...\n";
        solution = bfs.Solve();
        if(!solution.size())
            std::cout << BOLD << RED << "It has no solution" << RESET << "\n";
    }
    else if(ch=='b')
    {
        int lim;
        std::cout << BOLD <<  "The limit for DLs: \n" << RESET; 
        std::cin >> lim;
        DFS dfs{root,goalpuzzle};
        std::cout << "It will be solved in seconds...\n";
        solution = dfs.SolveDLS(lim);
        if(!solution.size())
            std::cout << BOLD << RED << "It has no solution" << RESET << "\n";
    }
    else if(ch=='c')
    {
        DFS dfs{root,goalpuzzle};
        std::cout << "It will be solved in seconds...\n";
        solution = dfs.SolveIDS();
        if(!solution.size())
            std::cout << BOLD << RED << "It has no solution" << RESET << "\n";
    }
    else if(ch=='d')
    {
        A astar{root,goalpuzzle};
        std::cout << "It will be solved in seconds...\n";
        solution = astar.Solve();
        if(!solution.size())
            std::cout << BOLD << RED << "It has no solution" << RESET << "\n";
    }
}
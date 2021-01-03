#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "midterm.h"

int main()
{
    while(1)
    {
        std::vector<int> puzzle0{1,2,3,4,5,6,7,8,0};
        std::vector<int> goalpuzzle{1,2,3,4,5,6,7,8,0};
        Node root;
        makePuzzle(puzzle0,goalpuzzle,root);
        solvePuzzle(puzzle0,goalpuzzle,root);
        char ch;
        while((ch=getchar())!= 'q') {}
    }
    
    return 0;
}


#include "node.h"
#include <bits/stdc++.h>
#include <cmath>

Node::Node(std::vector<int> _puzzle,std::string _action):action{_action}
{
    setValue(_puzzle);
}

void Node::setValue(std::vector<int> _puzzle)
{
    puzzle = {};
    for(int i{};i<9;i++)
    {
        this->puzzle.push_back(_puzzle[i]);
    }
    id = setid(puzzle);
}

Node::Node(const Node& node)
{
    parent = {};
    if(node.parent.size())
        parent.push_back(node.parent[0]);
    children=node.children;  
    puzzle=node.puzzle;          
    ind0 = node.ind0;
    action = node.action;
    heuristic = node.heuristic;
    id = node.id;
    depth=node.depth;
}

Node::Node(const Node* node)
{
    parent = {};
    if(node->parent.size())
        parent.push_back(node->parent[0]);
    children=node->children;  
    puzzle=node->puzzle;         
    ind0 = node->ind0;
    action = node->action;
    heuristic = node->heuristic;
    id = node->id;
    depth=node->depth;
}

bool Node::Test(std::vector<int> goalarray)
{
    int goalid = setid(goalarray);
    if(id==goalid)
        return true;
    return false;   
}

void Node::right(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "right move\n";
    if(ind0 % 3 < 2)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0+1],mid_values[ind0]);
        std::string s = "move right";
        Node childd(mid_values);
        childd.setid(mid_values);
        childd.depth = depth+1;
        auto child = std::make_shared<Node>(childd);
        if(!child->parent.size())
            child->parent.push_back(std::make_shared<Node>(this));
        else
            child->parent[0]=std::make_shared<Node>(this);    
        child->action = s;
        children.push_back(child);
    }
}

void Node::left(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "left move\n";
    if(ind0 % 3 > 0)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0-1],mid_values[ind0]);
        std::string s = "move left";
        Node childd(mid_values);
        childd.setid(mid_values);
        childd.depth = depth+1;
        auto child = std::make_shared<Node>(childd);
        if(!child->parent.size())
            child->parent.push_back(std::make_shared<Node>(this));
        else
            child->parent[0]=std::make_shared<Node>(this); 
        child->action = s;
        children.push_back(child);        
    }
}

void Node::up(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "up move\n";
    if(ind0 - 3 >= 0)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0-3],mid_values[ind0]);
        std::string s = "move up";
        Node childd(mid_values);
        childd.setid(mid_values);
        childd.depth = depth+1;
        auto child = std::make_shared<Node>(childd);
        if(!child->parent.size())
            child->parent.push_back(std::make_shared<Node>(*this));
        else
            child->parent[0]=std::make_shared<Node>(this); 
        child->action = s;
        children.push_back(child);   
    }
}

void Node::down(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "down move\n";
    if(ind0 + 3 < 9)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0+3],mid_values[ind0]);
        std::string s = "move down";
        Node childd(mid_values);
        childd.setid(mid_values);
        childd.depth = depth+1;
        auto child = std::make_shared<Node>(childd);
        if(!child->parent.size())
            child->parent.push_back(std::make_shared<Node>(this));
        else
            child->parent[0]=std::make_shared<Node>(this); 
        child->action = s;
        children.push_back(child);             
    }
}

void Node::show()
{
    int m = 0;
    std::cout << "+-------+\n";
    for(int i{};i<3;i++)
    {
        std::cout << "| ";
        std::cout << LIGHTGRAY_B ;
        for(int j{};j<3;j++)
        {
            if( j == 2)
                std::cout << BOLD << LIGHTMAGENTA << puzzle[m] << RESET;
            else
                std::cout << BOLD << LIGHTMAGENTA << puzzle[m] << " ";
            m+=1;
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "+-------+\n";
}

void Node::generate()
{
    auto it = std::find(puzzle.begin(), puzzle.end(), 0);
    if (it != puzzle.end()) 
    {
        ind0 = it - puzzle.begin();
    }
    else 
    {
        std::cout << "-1" << std::endl;
    }
    right(puzzle,ind0);
    left(puzzle,ind0);
    up(puzzle,ind0);
    down(puzzle,ind0);
}

bool Node::operator==(Node node)
{
    if(puzzle==node.puzzle)
    {
        return true;                
    }
    return false;
}

bool Node::operator==(std::shared_ptr<Node> node)
{
    std::cout << "calls this";
    if(puzzle==node->puzzle)
    {
        return true;                
    }
    return false;
}

bool Node::operator!=(Node node)
{
    if(*this==node)
    {
        return false;
    }
    return true;
}

int Node::findHeu(std::vector<int> goalarray)
{
    heuristic=0;
    for(int i{};i<9;i++)
    {
        if(puzzle[i] != goalarray[i])
        {
            heuristic ++;
        }
    }
    return heuristic;
}

int Node::setid(std::vector<int> p)
{
    int c = (p[0]*100000000)+(p[1]*10000000)+(p[2]*1000000)+(p[3]*100000)+(p[4]*10000)+(p[5]*1000)+(p[6]*100)+(p[7]*10)+p[8];
    return c;
}

int Node::getInvCount(std::vector<int> p)
{
    int inv_count = 0;
    for (int i = 0; i < 8; i++) 
        for (int j = i+1; j < 9; j++)
            if (p[j] && p[i] &&  p[i] > p[j]) 
                inv_count++;
    return inv_count;
}    

bool Node::isSolvable()
{
    int invCount = getInvCount(puzzle);
    return (invCount%2 == 0); 
}
#include "node.h"

Node::Node(std::vector<int> _puzzle,std::string _action):action{_action}
{
    // std::cout << "node constructor" << "\n";
    setValue(_puzzle);
}

void Node::setValue(std::vector<int> _puzzle)
{
    // std::cout << "set value..." << "\n";
    for(int i{};i<size;i++)
    {
        this->puzzle.push_back(_puzzle[i]);
    }
    // std::cout << "end set value\n";
}

Node::Node(const Node& node)
{
    // std::cout <<"node copy constructor\n";
    parent = {};
    if(node.parent.size())
        parent.push_back(node.parent[0]);
    children={};  
    puzzle={};          
    for(int i{};i<size;i++)
    {
        puzzle.push_back(node.puzzle[i]);
    }
    for(size_t i{};i<children.size();i++)
    {
        children.push_back(node.children[i]);
    }
    ind0 = node.ind0;
    col = node.col;
    size = node.size;
    action = node.action;
}

bool Node::Test(std::vector<int> goalarray)
{
    for(int i{};i<size;i++)
    {
        if(puzzle[i] != goalarray[i])
        {
            return false;
        }
    }
    return true;        
}

void Node::right(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "right move\n";
    if(ind0 % col < col-1)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0+1],mid_values[ind0]);
        std::string s = "move right";
        Node child(mid_values);
        if(!child.parent.size())
            child.parent.push_back(*this);
        else
            child.parent[0]=*this;    
        child.action = s;
        children.push_back(child);    
    }
}

void Node::left(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "left move\n";
    if(ind0 % col > 0)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0-1],mid_values[ind0]);
        std::string s = "move left";
        Node child(mid_values);
        if(!child.parent.size())
            child.parent.push_back(*this);
        else
            child.parent[0]=*this; 
        child.action = s;
        children.push_back(child);        
    }
}

void Node::up(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "up move\n";
    if(ind0 - col >= 0)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0-col],mid_values[ind0]);
        std::string s = "move up";
        Node child(mid_values);
        if(!child.parent.size())
            child.parent.push_back(*this);
        else
            child.parent[0]=*this;
        child.action = s;
        children.push_back(child);    
    }
}

void Node::down(std::vector<int> _puzzle,int ind0)
{
    // std::cout << "down move\n";
    if(ind0 + col < col*col)
    {
        std::vector<int> mid_values = _puzzle;
        std::swap(mid_values[ind0+col],mid_values[ind0]);
        std::string s = "move down";
        Node child(mid_values);
        if(!child.parent.size())
            child.parent.push_back(*this);
        else
            child.parent[0]=*this;
        child.action = s;
        children.push_back(child);             
    }
}

void Node::show()
{
    int m = 0;
    std::cout << "+-------+\n";
    for(int i{};i<col;i++)
    {
        std::cout << "| ";
        std::cout << LIGHTGRAY_B ;
        for(int j{};j<col;j++)
        {
            if( j == col-1)
                std::cout << BOLD << LIGHTMAGENTA << puzzle[m] << RESET;
            else
                std::cout << BOLD << LIGHTMAGENTA << puzzle[m] << " ";
            m+=1;
        }
        std::cout << " |" << std::endl;
    }
    std::cout << "+-------+\n";
}

bool Node::sameNode(std::vector<int> _puzzle)
{
    for(int i{};i<size;i++)
    {
        if(puzzle[i] != _puzzle[i])
        {
            return false;
        }
    }
    return true;
}

void Node::generate()
{
    // std::cout << "entrance of generator " << puzzle.size() << "\n";
    for(size_t i{};i<puzzle.size();i++)
    {
        if(puzzle[i]==0)
        {
            ind0 = i;
            break;
        }
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
        if(parent.size() && node.parent.size())
            if(parent[0].puzzle == node.parent[0].puzzle)
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
#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <deque> 
#include <iterator> 
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "color.h"

class Node
{
    public:

        int col{3};
        int size{col*col};
        std::vector<int> puzzle;
        std::deque<Node> children{};
        std::string action{};
        std::vector<Node> parent{};
        int ind0{};

        Node(){}
        Node(std::vector<int> _puzzle,std::string _action=""):action{_action}
        {
            std::cout << "node constructor" << "\n";
            setValue(_puzzle);
            // parent = new Node[1];
            // parent[0] = {};
        }
        void setValue(std::vector<int> _puzzle)
        {
            std::cout << "set value..." << "\n";
            for(int i{};i<size;i++)
            {
                this->puzzle.push_back(_puzzle[i]);
            }
            std::cout << "end set value\n";
        }
        Node(const Node& node)
        {
            // std::cout <<"node copy constructor\n";
            parent = {};
            // delete[] parent;
            // parent[0] = node.parent[0];
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
        ~Node(){}
        bool Test(std::vector<int> goalarray)
        {
            for(size_t i{};i<size;i++)
            {
                if(puzzle[i] != goalarray[i])
                {
                    return false;
                }
            }
            return true;        
        }
        void right(std::vector<int> _puzzle,int ind0)
        {
            std::cout << "right move\n";
            if(ind0 % col < col-1)
            {
                std::vector<int> mid_values = _puzzle;
                std::swap(mid_values[ind0+1],mid_values[ind0]);
                std::string s = "move right";
                Node child(mid_values);
                // child.parent = this; 
                if(!child.parent.size())
                    child.parent.push_back(*this);
                else
                    child.parent[0]=*this;    
                child.action = s;
                children.push_back(child);    
            }
        }
        void left(std::vector<int> _puzzle,int ind0)
        {
            std::cout << "left move\n";
            if(ind0 % col > 0)
            {
                std::vector<int> mid_values = _puzzle;
                std::swap(mid_values[ind0-1],mid_values[ind0]);
                std::string s = "move left";
                Node child(mid_values);
                // child.parent = this;
                if(!child.parent.size())
                    child.parent.push_back(*this);
                else
                    child.parent[0]=*this; 
                child.action = s;
                children.push_back(child);        
            }
        }
        void up(std::vector<int> _puzzle,int ind0)
        {
            std::cout << "up move\n";
            if(ind0 - col >= 0)
            {
                std::vector<int> mid_values = _puzzle;
                std::swap(mid_values[ind0-col],mid_values[ind0]);
                std::string s = "move up";
                Node child(mid_values);
                // child.parent = this;
                if(!child.parent.size())
                    child.parent.push_back(*this);
                else
                    child.parent[0]=*this;
                child.action = s;
                children.push_back(child);    
            }
        }
        void down(std::vector<int> _puzzle,int ind0)
        {
            std::cout << "down move\n";
            if(ind0 + col < col*col)
            {
                std::vector<int> mid_values = _puzzle;
                std::swap(mid_values[ind0+col],mid_values[ind0]);
                std::string s = "move down";
                Node child(mid_values);
                // child.parent = this; 
                if(!child.parent.size())
                    child.parent.push_back(*this);
                else
                    child.parent[0]=*this;
                child.action = s;
                children.push_back(child);             
            }
        }
        void show()
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
        bool sameNode(std::vector<int> _puzzle)
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
        void generate()
        {
            std::cout << "entrance of generator " << puzzle.size() << "\n";
            for(int i{};i<puzzle.size();i++)
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
        bool operator==(Node node)
        {
            if(children==node.children && puzzle==node.puzzle)
            {
                return true;
            }
            return false;
        }
        bool operator!=(Node node)
        {
            if(*this==node)
            {
                return false;
            }
            return true;
        }
};

#endif
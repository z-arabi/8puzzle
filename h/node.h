#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include <deque> 
#include <iterator> 
#include <deque>
#include <vector>
#include <algorithm>
#include <string>


class Node
{
    public:

        int col{3};
        int size{col*col};
        std::vector<int> puzzle;
        std::deque<Node> children{};
        std::string action{};
        Node* parent{};
        int ind0{};

        Node()
        {

        }
        Node(std::vector<int> _puzzle,std::string _action=""):action{_action}
        {
            std::cout << "node constructor" << "\n";
            setValue(_puzzle);
        }
        void setValue(std::vector<int> _puzzle)
        {
            std::cout << "set value..." << "\n";
            for(int i{};i<size;i++)
            {
                this->puzzle.push_back(_puzzle[i]);
                // std::cout << puzzle[i] << " ";
            }
            std::cout << puzzle.size() << "\n";
        }
        Node(const Node& node)
        {
            std::cout <<"node copy constructor\n";
            parent = node.parent;
            children={};            
            for(int i{};i<size;i++)
            {
                puzzle.push_back(node.puzzle[i]);
                // std::cout << puzzle[i] << " pp ";
            }
            // std::cout << std::endl;
            for(size_t i{};i<children.size();i++)
            {
                children.push_back(node.children[i]);
            }
            // parent = new Node[1];
            // parent[0] = *(node.parent);
            ind0 = node.ind0;
            col = node.col;
            size = node.size;
            std::cout << parent << " p " << node.parent << std::endl;
        }
        ~Node()
        {
            // delete[] parent;
        }
        
        bool Test(int* goalarray)
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
                child.parent = this; 
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
                child.parent = this; 
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
                child.parent = this; 
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
                child.parent = this; 
                child.action = s;
                children.push_back(child);             
            }
        }
        void show()
        {
            std::cout << "\n";
            int m = 0;
            for(int i{};i<col;i++)
            {
                for(int j{};j<col;j++)
                {
                    std::cout << puzzle[m] << " ";
                    m+=1;
                }
                std::cout << std::endl;
            }
            std::cout << "\n";
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
                    // std::cout << "index of zero " << ind0 << "\n";
                    break;
                }
            }
            right(puzzle,ind0);
            left(puzzle,ind0);
            up(puzzle,ind0);
            down(puzzle,ind0);
        }
        // // bool operator==(Node node)
        // // {
        // //     if(children==node.children && parent==node.parent && puzzle==node.puzzle)
        // //     {
        // //         return true;
        // //     }
        // //     return false;
        // // }
        // // bool operator!=(Node node)
        // // {
        // //     if(children==node.children && parent==node.parent && puzzle==node.puzzle)
        // //     {
        // //         return false;
        // //     }
        // //     return true;
        // // }

};

#endif
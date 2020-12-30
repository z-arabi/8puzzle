// #ifndef TREE_H
// #define TREE_H

// #include <iostream>
// #include <vector>
// #include <string>

// class Tree
// {
//     private:
//         class Node
//         {
//             public:
//                 Node* parent{};
//                 std::vector<Node*> children{};
//                 std::vector<int> values{};
//                 Node(std::vector<int> values)
//                 {
//                     setValue(values);
//                 }
//                 Node()=default;
//                 ~Node(){}
//                 void setValue(std::vector<int> values)
//                 {
//                     for(int i{};i<9;i++)
//                     {
//                         values[i]=values[i];
//                         // std::cout << values[i] << "\n";
//                     }
//                 }
//         };
//     public:
//         Tree(std::vector<int> initialarray,std::vector<int> goalarray={1,2,3,4,5,6,7,8,0})
//         {
//             std::cout << "tree constructor\n";
//             initialstate.setValue(initialarray);
//             goalstate.setValue(goalarray);
//         }
//         Tree(const Tree& tree)
//         {
//             initialstate=tree.initialstate;
//             goalstate=tree.goalstate; 
//         }
//         ~Tree(){};
//         bool Test(Node node)
//         {
//             bool test=true;
//             for(size_t i{};i<9;i++)
//             {
//                 if(node.values[i] != goalstate.values[i])
//                 {
//                     test = false;
//                 }
//             }
//             return test;        
//         }
//         void right(Node node,int ind0)
//         {
//             if(ind0 % 3 < 2)
//             {
//                 std::vector<int> mid_values = node.values;
//                 std::swap(mid_values[ind0+1],mid_values[ind0]);
//                 Node child(mid_values);
//                 node.children.push_back(&child);
//                 child.parent = &node;             
//             }
//         }
//         void left(std::vector<int> values,int i)
//         {
//             if(ind0 % 3 > 0)
//             {
//                 std::vector<int> mid_values = node.values;
//                 std::swap(mid_values[ind0+1],mid_values[ind0]);
//                 Node child(mid_values);
//                 node.children.push_back(&child);
//                 child.parent = &node;             
//             }
            
//         }
//         void up(std::vector<int> values,int i)
//         {
//             if(ind0 - 3 >= 0)
//             {
//                 std::vector<int> mid_values = node.values;
//                 std::swap(mid_values[ind0+1],mid_values[ind0]);
//                 Node child(mid_values);
//                 node.children.push_back(&child);
//                 child.parent = &node;             
//             }
            
//         }
//         void down(std::vector<int> values,int i)
//         {
//             if(ind0 + 3 < 9)
//             {
//                 std::vector<int> mid_values = node.values;
//                 std::swap(mid_values[ind0+1],mid_values[ind0]);
//                 Node child(mid_values);
//                 node.children.push_back(&child);
//                 child.parent = &node;             
//             }
            
//         }
//         void show(Node node)
//         {
//             int m = 0
//             for(int i{};i<3;i++)
//             {
//                 for(int j{};j<3;j++)
//                 {
//                     std::cout << node.values[m] << " ";
//                 }
//                 std::cout << std::endl;
//             }
//         }
//         bool sameNode(Node node)
//         {
//             // bool same=true;
//             // for(int i{};i<9;i++)
//             // {
//             //     if(node.values[i] != )
//             // }
//         }
//         void generate(Node node)
//         {
//             for(int i{};i<9;i++)
//             {
//                 if(node.values[i]==0)
//                 {
//                     ind0 = i;
//                 }
//             }
//             right(node,ind0);
//             left(node,ind0);
//             up(node,ind0);
//             down(node,ind0);
//         }
//     private:
//         int ind{0};
//         int depth{};
//         Node initialstate;
//         Node goalstate;
        

// };

// #endif
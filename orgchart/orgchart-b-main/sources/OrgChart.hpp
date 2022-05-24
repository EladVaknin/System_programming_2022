/**
 *
 * @author Elad Vaknin
 * @since 2022-05
 * 
 * https://www.geeksforgeeks.org/templates-cpp/
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
// #pragma once
using namespace std;

namespace ariel 
{
    template<typename T=string>
    class OrgChart{
        struct Node{
        T name;
        vector <Node *> childrens;
        Node *parent;
        Node (T &data) : name(data) ,parent(nullptr){}
        };

        // Node root;
        Node *root;
        int counter_level;
        int counter_children;

        public:
        OrgChart(){
            root = nullptr;
        }
        ~OrgChart(){};
        OrgChart &add_root (T x);
        OrgChart &add_sub (T x, T y);

        // implements iterator in sub class for the tree-functions https://programmer.group/principle-and-simple-implementation-of-c-stl-iterator-just-read-this-one.html
        enum Order_of_iterator {
            level_order ,preorder ,reverse_orders
        };

        class iterator{
            private :
            Node *current;
            vector <Node *> list_of_nodes;
            int i;
            queue <Node *> queue_of_nodes; 
            queue <Node *> queue_to_reverse;     
            stack <Node *> stack_of_nodes;
            stack <Node *> stack_to_reverse;      

            Order_of_iterator direction;

            public :

            // iterator (Node *p ,Order_of_iterator o):current(p),Order_of_iterator(o){
            //     if ((p =! nullptr) && (o =! level_order) && (!p->childrens.emty())){  // level order
            //         for (auto &childrens :current->childrens){
            //             queue_of_nodes.push(childrens);
            //         }
            //     }
            //     if ((p =! nullptr) && (o =! reverse_orders) && (!p->childrens.emty())){  // revers order
                  
            //     }
            // }

            iterator (Node *p ,Order_of_iterator o):current(p),Order_of_iterator(o){
                check_input(p);
                if(o==reverse_orders){
                    reverse_bfs(p);
                }
            }


            void next_level_order(){
                bfs();
            }

            void next_reverse_order(){

            }

            void next_preorder(){

            }

            iterator bfs () {      // to next level order
                if (queue_of_nodes.empty()){
                    current=nullptr;
                }else{
                    current =queue_of_nodes.front();
                    queue_of_nodes.pop();
                    for (Node* tmp :current->childrens){
                        queue_of_nodes.push(tmp);
                    }
                }
                return *this;
            }

            void reverse_bfs (Node* root){        //to revrse order
                queue_to_reverse.push(root);
                while (!queue_to_reverse.empty()){
                    Node* tmp = queue_to_reverse.front();
                    queue_to_reverse.pop();
                    stack_to_reverse.push(tmp);
                    for (int i=0 ;i<tmp->childrens.size();i++){
                        int index = tmp->childrens.size() -1 -i;
                        queue_to_reverse.push(tmp->childrens[index]);
                    }
                }
            }

            void check_input (Node *tmp){
                if(tmp == nullptr){
                    throw invalid_argument ("the tree is empty - cant run on the tree");
                }
            }

            // ++ , =! , == ,*
            iterator &operator++(){
                          //  level_order ,preorder ,reverse_orders

                switch (direction)
                {
                    case reverse_orders:
                    next_reverse_order();
                    break;

                    case preorder:
                    next_preorder();    
                    break;

                    case level_order:
                    next_level_order();
                    break;
                    
                    // default:
                    //     break;
                    }
            }

            
            iterator &operator*(){}
            bool operator ==(const iterator &i)const{}
            bool operator!=(const iterator &i)const{}





        };

        iterator *begin_level_order ();            //bfs
        iterator *begin_reverse_order();            //reverse bfs
        iterator *begin_preorder();
        iterator *end_level_order ();
        iterator *reverse_order();
        iterator *end_preorder();
        iterator *begin();
        iterator *end();
        friend ostream &operator << (ostream &out ,OrgChart &r);


    };
}








            // iterator &operator*(){}

            // iterator (){
            //     current = NULL;
            //     i =0;
            // }
            //cons

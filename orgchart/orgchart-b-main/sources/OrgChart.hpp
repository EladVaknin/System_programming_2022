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
///////////////////////////////////////Node/////////////////////////////
        struct Node{
        T name;
        vector <Node *> childrens;
        Node *parent;
        Node (T &data) : name(data) ,parent(nullptr){}
        };
/////////////////////////////////OrgChart///////////////////////////
        Node *root;
        int counter_level;
        int counter_children;

        public:
        OrgChart(){
            root = nullptr;
        }
        ~OrgChart(){};

        OrgChart &add_root (T x) {
            if (root == nullptr){
                this->root=new Node (x);
            }else{    //replace
               this->root->name=x;
            }
            return *this;
        }
        OrgChart &add_sub (T x, T y){
            check_node(x);   //if x is nullptr.
            if (this->root->name == x ){   //this root is the father
                this->root->childrens.push_back(new Node (y));
            }
            for (Node* tmp :this->root->childrens){
                if(tmp->name==x){
                    this->root->childrens.push_back(new Node (y)); 
                }
                
            }
            return *this;

        }

//////////////////////////////////iterator////////////////////////////////////////////

        // implements iterator in sub class for the tree-functions https://programmer.group/principle-and-simple-implementation-of-c-stl-iterator-just-read-this-one.html
        enum Order_of_iterator {
            level_order ,preorder ,reverse_orders
        };

        class iterator{
            private :
            Node *current;
            vector <Node *> list_of_nodes;
            int i;
            //queues
            queue <Node *> queue_to_level; 
            queue <Node *> queue_to_reverse;   
            //stacks
            stack <Node *> stack_of_nodes;
            stack <Node *> stack_to_reverse;
            stack <Node *> stack_for_preorder; 
            //enum object
            Order_of_iterator direction;

            public :
            iterator (Node *p ,Order_of_iterator o):current(p),Order_of_iterator(o){
                check_input(p);
                // initzale to be non empty.
                queue_to_level.push(nullptr);
                queue_to_reverse.push(nullptr); 
                stack_of_nodes.push(nullptr);
                stack_to_reverse.push(nullptr);
                stack_for_preorder.push(nullptr);

                if(o==reverse_orders){     
                    reverse_bfs(p);        //to end level order
                }

            }

            iterator bfs () {      // to next level order - becuse its tree we dont check if we visited becuse in thos tree cant be circuls
                if (queue_to_level.empty()){
                    current=nullptr;
                }else{
                    current =queue_to_level.front();
                    queue_to_level.pop();
                    for (Node* tmp :current->childrens){
                        queue_to_level.push(tmp);
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
                // current = stack_to_reverse.top();
                // stack_to_reverse.pop();
            }
            void preorder (Node *tmp){      
                stack_for_preorder.push(tmp);
                for(Node* tmp2 : tmp->childrens){
                    preorder(tmp2);        // recurseve becuse its goes left automatically
                }
            }

            void check_input (Node *tmp){
                if(tmp == nullptr){
                    throw invalid_argument ("the tree is empty - cant run on the tree");
                }
            }




            void plus_plus_level_order(){
                bfs();
            }

            void plus_plus_reverse_order(){
                 if(stack_to_reverse.empty()){
                    current= nullptr;
                }
                else{
                    current=stack_to_reverse.top();
                    stack_to_reverse.pop();
                }
            }

            void plus_plus_preorder(){
                  if(stack_for_preorder.empty()){
                    current= nullptr;
                }else{
                    current=stack_for_preorder.top();
                    stack_for_preorder.pop();
                }

            }

            // ++ , =! , == ,*
            iterator &operator++(){
                switch (direction)
                {
                    case reverse_orders:
                    plus_plus_reverse_order();
                    break;

                    case preorder:
                    plus_plus_preorder();    
                    break;

                    case level_order:
                    plus_plus_level_order();
                    break;
                    }
                    return *this;
            }


            iterator &operator*(){
                return this->current->name;
            }
            bool operator ==(const iterator &i)const{
                return this->current ==i.current;
            }
            bool operator!=(const iterator &i)const{
                return this->current != i.current;
            }
        };
///////////////////////////////////////////////////////////////////////////////////////////////////////


        iterator *begin_level_order (){
            return iterator(root,level_order);
        }            
        iterator *begin_reverse_order(){
            return iterator(root,reverse_orders);
        }           
        iterator *begin_preorder(){
            return iterator(root,preorder);
        }
        iterator *end_level_order (){ 
            check_node(root);
            return iterator();  
        }
        iterator *reverse_order(){
            check_node(root);
            return iterator();  
        }
        iterator *end_preorder(){
            check_node(root);
            return iterator();  
        }
        iterator *begin(){
            return begin_level_order();
        }
        iterator *end(){
          return end_level_order();
        }
        friend ostream &operator << (ostream &out ,OrgChart &r);
        // void print_tree (ostream &out,Node *tmp){
        // }
        void check_node(Node *tmp){
            if(tmp == nullptr){
                throw invalid_argument ("the tree is empty - cant run on the tree");
            }
        }


    };
}


            // iterator (Node *p ,Order_of_iterator o):current(p),Order_of_iterator(o){
            //     if ((p =! nullptr) && (o =! level_order) && (!p->childrens.emty())){  // level order
            //         for (auto &childrens :current->childrens){
            //             queue_of_nodes.push(childrens);
            //         }
            //     }
            //     if ((p =! nullptr) && (o =! reverse_orders) && (!p->childrens.emty())){  // revers order
                  
            //     }
            // }





            // iterator &operator*(){}

            // iterator (){
            //     current = NULL;
            //     i =0;
            // }
            //cons

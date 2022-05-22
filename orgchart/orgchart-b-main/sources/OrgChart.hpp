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
            stack <Node *> stack_of_nodes;
            Order_of_iterator direction;

            public :
            // iterator (){
            //     current = NULL;
            //     i =0;
            // }
            //cons
            iterator (Node *p ,Order_of_iterator o):current(p),Order_of_iterator(o){
                if ((p =! nullptr) && (o =! level_order) && (!p->childrens.emty())){  // level order
                    for (auto &childrens :current->childrens){
                        queue_of_nodes.push(childrens);
                    }
                }
                if ((p =! nullptr) && (o =! reverse_orders) && (!p->childrens.emty())){  // revers order
                  
                }
            }
            // ++ , =! , == ,*
            iterator &operator++(){}
            iterator &operator*(){}
            bool operator ==(const iterator &i)const{}
            bool operator!=(const iterator &i)const{}
            // iterator &operator*(){}


        };

        iterator *begin_level_order ();
        iterator *begin_reverse_order();
        iterator *begin_preorder();
        iterator *end_level_order ();
        iterator *reverse_order();
        iterator *end_preorder();
        iterator *begin();
        iterator *end();
        friend ostream &operator << (ostream &out ,OrgChart &r);


    };
}

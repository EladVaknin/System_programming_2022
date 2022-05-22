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
using namespace std;

namespace ariel 
{
    template<typename T=string>
    class OrgChart{
        struct Node{
        T name;
        vector <Node *> childrens;
        Node *parent;
        node (T &data) : name(data) ,parent(nullptr);
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
        string *begin_level_order ();
        string *begin_reverse_order();
        string *begin_preorder();
        string *end_level_order ();
        void *reverse_order();
        void *end_preorder();
        string *begin();
        string *end();
        friend ostream &operator << (ostream &out ,OrgChart &r);


    };
    // enum Order_of_iterator {
//     level_order ,preorder ,reversed_order

// };

// class iterator{
//     private :
//     node *current;
//     vector <node *> list_of_nodes;
//     int i;

//     public :
    
//     iterator (){
//         current = NULL;
//         i =0;
//     }
//     // ++ , =! , == ,*


// };
}

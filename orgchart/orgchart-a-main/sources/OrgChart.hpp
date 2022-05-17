/**
 *
 * @author Elad Vaknin
 * @since 2022-05
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
    struct Node{

    string name;
    vector <Node> childrens;
    };

    class OrgChart{
        
        private:
        Node root;
        int counter;

        public:
        OrgChart();
        ~OrgChart();
        OrgChart &add_root (string x);
        OrgChart &add_sub (string x, string y);
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
}

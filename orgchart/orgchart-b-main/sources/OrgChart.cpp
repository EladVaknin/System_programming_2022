/**
 *
 * @author Elad Vaknin
 * @since 2022-05

 https://www.geeksforgeeks.org/templates-cpp/
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"

namespace ariel
{
        //     OrgChart(){};     V
        // ~OrgChart(){};   V
        // OrgChart &add_root (string x); V
        // OrgChart &add_sub (string x, string y); V
        // string *begin_level_order ();   V
        // string *begin_reverse_order();   V
        // string *begin_preorder(); V
        // string *end_level_order (); V
        // void *reverse_order();  V
        // void *end_preorder();    V
        // string *begin();       V
        // string *end();     V
        // friend ostream &operator << (ostream &out ,OrgChart &r); V


        OrgChart &OrgChart::add_root (T x){
            this->root.name =x;
            return *this;
        }
        OrgChart &OrgChart::add_sub (T x, T y){
            // if(begin_level_order() )
            return *this;
        }
        string *OrgChart::begin_level_order (){
            string x = "";
            return NULL;
        }
        string *OrgChart::begin_reverse_order(){
            string x = "";
            return NULL;
        }
        string *OrgChart::begin_preorder(){
            string x = "";
            return NULL;
        }
        string *OrgChart::end_level_order (){
            string x = "";
            return NULL;
        }
        void *OrgChart::reverse_order(){
            return NULL;
        }
        void *OrgChart::end_preorder(){
            return NULL;
        }
        string *OrgChart::begin(){
            return begin_level_order();
        }
        string *OrgChart::end(){
            // return end_level_order();
            return NULL;
        }
        ostream &operator << (ostream &out ,OrgChart &r) {
           return out;
       }

}
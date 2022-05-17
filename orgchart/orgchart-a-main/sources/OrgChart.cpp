/**
 *
 * @author Elad Vaknin
 * @since 2022-05
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"

namespace ariel
{
        OrgChart &OrgChart::add_root (string x){
            this->root.name =x;
            return *this;
        }
        OrgChart &OrgChart::add_sub (string x, string y){
            if(begin_level_order() )
            return *this;
        }
        string *begin_level_order (){
            string x = "";
            return NULL;
        }
        string *begin_reverse_order(){
            string x = "";
            return NULL;
        }
        string *begin_preorder(){
            string x = "";
            return NULL;
        }
        string *end_level_order (){
            string x = "";
            return NULL;
        }
        void *reverse_order(){

        }
        void *end_preorder(){

        }
        string *begin(){
            return begin_level_order();
        }
        string *end(){
            // return end_level_order();
            return NULL;
        }
}
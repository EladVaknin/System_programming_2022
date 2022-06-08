/**
 *
 * @author Elad Vaknin
 * @since 2022-05
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("good input"){
    OrgChart<string> organization;
    /// create a tree : 
    /*
              1
            /   \
           3     2 
          / \   / \
         7   6  5  4 

    */
    organization.add_root("1");
    organization.add_sub("1", "2");
    organization.add_sub("1", "3");
    organization.add_sub("2", "4");
    organization.add_sub("2", "5");
    organization.add_sub("3", "6");
    organization.add_sub("3", "7");

    string tmp = "";
   /// check level order
     for (auto iterator = organization.begin_level_order(); iterator != organization.end_level_order(); ++iterator) {
        tmp += *iterator;
    }
     CHECK(tmp=="1 2 3 4 5 6 7 ");

    /// check reverse level order
     for (auto iterator = organization.begin_reverse_order(); iterator != organization.reverse_order(); ++iterator) {
        tmp += *iterator;
    }
     CHECK(tmp=="4 5 6 7  2 3 1");

    /// check pre order
     for (auto iterator = organization.begin_preorder(); iterator != organization.end_preorder(); ++iterator) {
        tmp += *iterator;
    }
    CHECK(tmp=="1 2 3 4 5 6 7 ");  
}



TEST_CASE("bad input")
{
    OrgChart<string> organization;
    organization.add_root("elad");
    organization.add_sub("david","vaknin");  /// cant add vaknin to david becuse david doesent excist
    string tmp = "";
    /// check level order
     for (auto iterator = organization.begin_level_order(); iterator != organization.end_level_order(); ++iterator) {
        tmp += *iterator;
    }
    CHECK(tmp=="elad david vaknin");    // not correct
    CHECK_NOTHROW (organization.add_sub("" ,"nizan"));    //empty father
    CHECK_NOTHROW (organization.add_sub("" ,""));    //empty sub
    CHECK_NOTHROW (organization.add_sub("elad" ,""));      // empty son
    CHECK_NOTHROW (organization.add_root(""));     //  change to empty root
    OrgChart<string> organization2;
    CHECK_NOTHROW (for (auto iterator = organization2.begin_level_order(); iterator != organization2.end_level_order(); ++iterator));     //   empty iterate - level order
    CHECK_NOTHROW (for (auto iterator = organization2.begin_reverse_order(); iterator != organization2.reverse_order(); ++iterator));     //   empty iterate - reverse order
    CHECK_NOTHROW (for (auto iterator = organization.begin_preorder(); iterator != organization.end_preorder(); ++iterator));     //   empty iterate - pre order

}


TEST_CASE("some tests")
{
    OrgChart<string> organization;
    /// create a tree : 
        /*
              1
            /   \
           3     2 
          / \   / \
         7   6  5  4 

    */
    organization.add_root("1");
    organization.add_sub("1", "2");
    organization.add_sub("1", "3");
    organization.add_sub("2", "4");
    organization.add_sub("2", "5");
    organization.add_sub("3", "6");
    organization.add_sub("3", "7");

/// we change the root and add childrens for nood num 4
    organization.add_root("99");
    string tmp ="";
    for (auto iterator = organization.begin_level_order(); iterator != organization.end_level_order(); ++iterator) {
        tmp += *iterator;
    }
    CHECK(tmp=="99 2 3 4 5 6 7 ");               //check the update in level order
    CHECK_NOTHROW (organization.add_sub("4" ,"77"));    
    organization.add_sub("4", "77");
    organization.add_sub("4", "88"); 
    /*
              99
            /   \
           3     2 
          / \   / \
         7   6  5  4 
                  /  \
                 88  77
    */
   string tmp2 ="";
    for (auto iterator = organization.begin_level_order(); iterator != organization.end_level_order(); ++iterator) {
        tmp2 += *iterator;
    }
    CHECK(tmp2 == "99 2 3 4 5 6 7 88 77 ");               //check the update in level order
    //add on exist noodes
    CHECK_NOTHROW (organization.add_sub("4" ,"77"));  
    CHECK_NOTHROW (organization.add_sub("4" ,"88")); 
    // add the same value of the root
    CHECK_NOTHROW (organization.add_root("99")); 
    
    CHECK_NOTHROW (organization.add_sub("2", "9"));  //change the childrens    
    CHECK_NOTHROW (organization.add_sub("3", "10"));  //change the childrens
    CHECK_NOTHROW (organization.add_sub("3", "14"));  //change the childrens   
        /*
              99
            /   \
           3      2 
          / \    / \
        14   10  9  4 
                  /  \
                 88  77
    */
    string tmp3 ="";
    for (auto iterator = organization.begin_level_order(); iterator != organization.end_level_order(); ++iterator) {
        tmp3 += *iterator;
    }
    CHECK(tmp3 =="99 2 3 4 9 10 14 77 88");               //check the update in level order    

}
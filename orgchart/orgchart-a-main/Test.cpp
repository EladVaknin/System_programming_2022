/**
 *
 * @author Elad Vaknin
 * @since 2022-05
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;
using namespace std;


TEST_CASE("From demo"){
    OrgChart organization;
    // CHECK (organization.add_root("elad"));
    CHECK_THROWS (organization.add_root("elad"));
    CHECK_THROWS (organization.add_root(""));
    // CHECK (organization.add_root("Amit"));
    // CHECK (organization.add_root("Nizan"));
    // CHECK (organization.add_root("Adva"));
    CHECK_THROWS (organization.add_root("Amit"));
    CHECK_THROWS (organization.add_root("Nizan"));
    CHECK_THROWS (organization.add_root("Adva"));
    CHECK_NOTHROW (organization.add_sub("elad" ,"nizan"));
    CHECK_NOTHROW (organization.add_sub("nizan" ,"david"));
    CHECK_NOTHROW (organization.add_sub("david" ,"shlomo"));
    CHECK_NOTHROW (organization.add_sub("shlomo" ,"haim"));
    CHECK_NOTHROW (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));
    // CHECK (organization.add_root("daniela"));
    CHECK_THROWS (organization.add_root("daniela"));
    CHECK_THROWS (organization.add_sub("shlomo" ,"haim"));

    ///////////////////////////////////////////////////////////////// try to do like the demo    
    unsigned int i = 5;   //size of the names;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){ // prints: CEO CTO CFO COO VP_SW VP_BI
        //  CHECK (organization)
    } 
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){ // prints: VP_SW VP_BI CTO CFO COO CEO
         cout << (*it) << " " ;
    } 
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {   // prints: CEO CTO VP_SW CFO COO VP_BI
         cout << (*it) << " " ;
    }  


    
}

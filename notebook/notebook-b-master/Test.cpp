/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */


#include "Notebook.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace ariel;
using ariel::Direction;


TEST_CASE("Notebook working") {
   Notebook notebook;
   // wirte to the notebook (page,col.row,direc,string)
   CHECK_NOTHROW (notebook.write(1,4,5,Direction::Horizontal,"Elad"));
   CHECK_NOTHROW (notebook.write(1,4,5,Direction::Vertical,"Vaknin"));
   CHECK_NOTHROW (notebook.write(2,4,5,Direction::Horizontal,"Amit"));
   CHECK_NOTHROW (notebook.write(2,4,5,Direction::Vertical,"Vaknin"));
   // Check read function
   CHECK (notebook.read(1,4,5,Direction::Horizontal,4)=="Elad");
   CHECK (notebook.read(1,4,5,Direction::Vertical,6)=="Vaknin");
   CHECK (notebook.read(2,4,5,Direction::Horizontal,4)=="Amit");
   CHECK (notebook.read(2,4,5,Direction::Vertical,6)=="Vaknin");
   // Check erase function - ~   
   CHECK_NOTHROW (notebook.erase(1,4,5,Direction::Horizontal,4));
   CHECK (notebook.read(1,4,5,Direction::Horizontal,4)=="~~~~");
   CHECK_NOTHROW (notebook.erase(1,4,5,Direction::Vertical,6));
   CHECK (notebook.read(1,4,5,Direction::Vertical,6)=="~~~~~~");
   CHECK_NOTHROW (notebook.erase(2,4,5,Direction::Horizontal,4));
   CHECK (notebook.read(2,4,5,Direction::Horizontal,4)=="~~~~");
   CHECK_NOTHROW (notebook.erase(2,4,5,Direction::Horizontal,6));
   CHECK (notebook.read(2,4,5,Direction::Vertical,6)=="~~~~~~");
}

TEST_CASE("Random tests ") {
    Notebook notebook3;
    //randoms numbers 0- 100
    unsigned int random1 ,random2,random3,random4,len5;
    srand(0);
	len5 = rand() % 100;
    for (int i =0 ;i<len5;i++){
        random1 = rand() % 100; // page
	    random2 = rand() % 100; //row
        random3 = rand() % 100; //col
	    random4 = rand() % 100;
        // wirte
        CHECK_NOTHROW (notebook3.write(random1,random2,random3,Direction::Horizontal,"Elad"));
        CHECK_NOTHROW (notebook3.write(random1,random2,random3,Direction::Vertical,"Vaknin"));
        //read
        CHECK (notebook3.read(random1,random2,random3,Direction::Horizontal,4)=="Elad");
        CHECK (notebook3.read(random1,random2,random3,Direction::Vertical,6)=="Vaknin");
        //erase
        CHECK_NOTHROW (notebook3.erase(random1,random2,random3,Direction::Horizontal,4));
        CHECK (notebook3.read(random1,random2,random3,Direction::Horizontal,4)=="~~~~");
    }

}




TEST_CASE("Invaild input") {
    Notebook notebook2;
    CHECK_NOTHROW(notebook2.write(0,0,0,Direction::Horizontal,"Elad"));
    CHECK_NOTHROW(notebook2.write(0,0,0,Direction::Vertical,"Vaknin"));
    CHECK_THROWS(notebook2.read(0,0,0,Direction::Horizontal,7));
    CHECK_THROWS(notebook2.read(0,0,0,Direction::Vertical,8));
    CHECK_NOTHROW(notebook2.write(550,550,550,Direction::Horizontal,"Elad"));
    CHECK_NOTHROW(notebook2.write(550,550,550,Direction::Vertical,"Vaknin"));
    CHECK_THROWS(notebook2.read(550,550,550,Direction::Horizontal,7));
    CHECK_THROWS(notebook2.read(550,550,550,Direction::Vertical,8));






//the rules :  page >= 0 && col >= 0 && row >= 0 
//    //001 - check row
//    CHECK_NOTHROW (notebook2.write(0,0,-1,Direction::Horizontal,"Amit"));
//    CHECK_THROWS(notebook2.read(0,0,-1,Direction::Horizontal,4));
//    CHECK_NOTHROW (notebook2.write(0,0,-1,Direction::Horizontal,"Vaknin"));
//    CHECK_THROWS(notebook2.read(0,0,-1,Direction::Horizontal,6));
//    //010 -check col
//    CHECK_NOTHROW (notebook2.write(0,-1,0,Direction::Horizontal,"Nizan"));
//    CHECK_THROWS(notebook2.read(0,-1,0,Direction::Horizontal,5));
//    CHECK_NOTHROW (notebook2.write(0,-1,0,Direction::Horizontal,"Vaknin"));
//    CHECK_THROWS(notebook2.read(0,-1,0,Direction::Horizontal,6));
//    //100 - check page
//    CHECK_NOTHROW (notebook2.write(-1,0,0,Direction::Horizontal,"Avi"));
//    CHECK_THROWS(notebook2.read(-1,0,0,Direction::Horizontal,3));
//    CHECK_NOTHROW (notebook2.write(-1,0,0,Direction::Horizontal,"Vaknin"));
//    CHECK_THROWS(notebook2.read(-1,0,0,Direction::Horizontal,6));



}

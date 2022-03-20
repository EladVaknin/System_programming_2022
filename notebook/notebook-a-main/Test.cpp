/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */


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
TEST_CASE("Invaild input") {
    Notebook notebook2;
   //the rules :  page >= 0 && col >= 0 && row >= 0 

   //001 - check row
   CHECK_NOTHROW (notebook2.write(0,0,-1,Direction::Horizontal,"Amit"));
   CHECK_THROWS(notebook2.read(0,0,-1,Direction::Horizontal,4));
   CHECK_NOTHROW (notebook2.write(0,0,-1,Direction::Horizontal,"Vaknin"));
   CHECK_THROWS(notebook2.read(0,0,-1,Direction::Horizontal,6));
   //010 -check col
   CHECK_NOTHROW (notebook2.write(0,-1,0,Direction::Horizontal,"Nizan"));
   CHECK_THROWS(notebook2.read(0,-1,0,Direction::Horizontal,5));
   CHECK_NOTHROW (notebook2.write(0,-1,0,Direction::Horizontal,"Vaknin"));
   CHECK_THROWS(notebook2.read(0,-1,0,Direction::Horizontal,6));
   //100 - check page
   CHECK_NOTHROW (notebook2.write(-1,0,0,Direction::Horizontal,"Avi"));
   CHECK_THROWS(notebook2.read(-1,0,0,Direction::Horizontal,3));
   CHECK_NOTHROW (notebook2.write(-1,0,0,Direction::Horizontal,"Vaknin"));
   CHECK_THROWS(notebook2.read(-1,0,0,Direction::Horizontal,6));



}

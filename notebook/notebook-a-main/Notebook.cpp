/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */

#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using ariel::Direction;
using namespace std;

namespace ariel {
    Notebook::Notebook(){} //cons
    void Notebook::write (unsigned int page,unsigned int row,unsigned int colum,Direction direction,string st){}
    string Notebook::read (unsigned int page,unsigned int row,unsigned int colum,Direction direction,unsigned int len) {
        string result = "h";
        return result;
    }
    void Notebook::erase (unsigned int page,unsigned int row,unsigned int colum,Direction direction,int len) {}
    void Notebook::show (unsigned int page){}


};
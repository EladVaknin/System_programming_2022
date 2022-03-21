/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */

#include "Direction.hpp"
#include <map>
#include <iostream>
#include <stdexcept>
using ariel::Direction;
using namespace std;
namespace ariel {
     class Notebook{
     private:
        typedef pair <unsigned int,unsigned int> palce_notebook;
        map < palce_notebook, char> notebbok; 
    public: 
        Notebook ();  // constructor
        // functions
        void write(unsigned int page,unsigned int row,unsigned int colum,Direction direction,string st);
        string read(unsigned int page,unsigned int row,unsigned int colum,Direction direction,unsigned int len);
        void erase(unsigned int page,unsigned int row,unsigned int colum,Direction direction,int len);
        void show (unsigned int page);
    };
}
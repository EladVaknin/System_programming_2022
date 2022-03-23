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
        typedef tuple < int,int, int> place_notebook;
        map < place_notebook, char> map_notebbok; 
    public: 
        Notebook ();  // constructor
        // functions
        void write( int page, int row, int colum,Direction direction,string st);
        string read( int page, int row, int colum,Direction direction, int len);
        void erase( int page, int row, int colum,Direction direction,int len);
        void show ( int page);
    };

   void check_inputs(int page, int row, int colum);
}
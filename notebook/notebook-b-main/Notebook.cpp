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

   void check_inputs(int page, int row, int colum){
     if (row < 0 || colum < 0 || page < 0){
         throw invalid_argument( "The input should be minimum zero");
     }
   }

    void Notebook::write (int page, int row, int colum,Direction direction,string st){
        check_inputs (int page, int row, int colum);

    }


    string Notebook::read (int page, int row, int colum,Direction direction, int len) {
        check_inputs(int page, int row, int colum);
        if (len >= 100 ){
            throw invalid_argument("The length should be smaller from 100");
        }
        string result ;
        char line ='_';
        for (int i =0;i<len; i++){
            if (map_notebook[make_tuple(page,row,colum)] > 0 ){
                line = map_notebook[make_tuple(page,row,colum)];
            }else{
                line = '_';
            }
            result += line;
            if (Direction::Vertical == direction){
                row ++;
            }else{
                colum++;
            }
        }

        return result;
    }



    void Notebook::erase ( int page, int row, int colum,Direction direction,int len) {}
    void Notebook::show ( int page){

    }


};
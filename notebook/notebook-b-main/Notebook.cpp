/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */

#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>

using ariel::Direction;
using namespace std;

namespace ariel {
    Notebook::Notebook(){} //cons


// check input functions
   void check_inputs(int page, int row, int colum){
     if (page < 0 || row < 0 || colum < 0){
         throw invalid_argument( "The input should be minimum zero");
     }
   }

   void check_inputs2(int page, int row, int colum,int len){
    check_inputs (page,row,colum);
    if (len >= 100 ){
    throw invalid_argument("The length should be smaller from 100");
    }
   }


// notebook functions
    void Notebook::write (int page, int row, int colum,Direction direction,string input){
        check_inputs  (page,row, colum);
        // check if the page is empty
        if(map_notebbok[make_tuple(page,row,colum)] == NULL ){
        for (int i=0;i<input.length();i++){
            map_notebbok[make_tuple(page,row,colum)]=input.at(i);
            //check if the exact location not erased
            }if(map_notebbok[make_tuple(page,row,colum)]== '~'){
                throw invalid_argument("The page is busy");
            }
          }else{
                throw invalid_argument("The page is busy");
        }

    }


    string Notebook::read (int page, int row, int colum,Direction direction, int length) {
        check_inputs2 (page,row,colum,length);
        string result ;
        char line ='_';
        for (int i =0;i<length; i++){
            if (map_notebbok[make_tuple(page,row,colum)] > 0 ){
                line = map_notebbok[make_tuple(page,row,colum)];
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



    void Notebook::erase ( int page, int row, int colum,Direction direction,int length) {
        check_inputs2 (page,row,colum,length);

    }



    void Notebook::show ( int page){
        if (page < 0 ) {
            throw invalid_argument("The input page should be 0 or bigger");
        }

    }


};
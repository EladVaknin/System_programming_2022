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
    //cons
    Notebook::Notebook(){} 


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

   int the_next_data(int row,int colum ,Direction direction){
        if (Direction::Vertical == direction){
                row ++;
                return row;
        }else{
                colum++;
                return colum;
            }
   }


// notebook functions
    void Notebook::write (int page, int row, int colum,Direction direction,string input){
        check_inputs  (page,row, colum);
        // check if the page is empty
        if(map_notebbok[make_tuple(page,row,colum)] == NULL ){
        for (int i=0;i<input.length();i++){
            map_notebbok[make_tuple(page,row,colum)]=input.at(i);
            the_next_data (row,colum,direction);
            //check if the exact location not erased or wirted
            }if(map_notebbok[make_tuple(page,row,colum)]== '~'){
                throw invalid_argument("The place in the notebook has been deleted");
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
            the_next_data (row,colum,direction);
        }
        return result;
    }



    void Notebook::erase ( int page, int row, int colum,Direction direction,int length_char) {
        check_inputs2 (page,row,colum,length_char);
         if(map_notebbok[make_tuple(page,row,colum)] == '~' ){
             throw invalid_argument("The place in the notebook has been deleted");
         }else{
             for (int i =0 ;i <length_char;i++){
                 map_notebbok[make_tuple(page,row,colum)] = '~';
                 the_next_data (row,colum,direction);
           }
        }
    }



    void Notebook::show ( int page){
        if (page < 0 ) {
            throw invalid_argument("The input page should be 0 or bigger");
        }

    }


};
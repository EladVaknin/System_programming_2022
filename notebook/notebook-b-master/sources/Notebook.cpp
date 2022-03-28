/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */

/* Because this is the second time I'm doing the course, I relied on my exercise last year -
https://github.com/EladVaknin/CPP-*/


#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>

using ariel::Direction;
using namespace std;

namespace ariel {
//cons
   Notebook::Notebook(){} 

// inizalize the notebook
    Notebook::Notebook(int page,int row,int colum){
        page = page;
        row = row;
        colum = colum;
        char line = '_';
        for (int i =0 ;i<page;i++){
            for (int j=0;j<row;j++){
                for (int k=0;k<colum;k++){
                    map_notebbok[make_tuple(page,row,colum)] = line;
                }
            }
        }
        cout<<"The notebook inizalized"<<endl;
    }


// check input functions - The functions are similar but the arguments are different.
   void check_inputs(int page, int row, int colum,string input){  // to write func
       int max = 100;
       unsigned long max_row = row+input.length();
     if (page < 0 || row < 0 || colum < 0){
         throw invalid_argument( "The input should be minimum zero");
     }if((max_row)>max){
        throw invalid_argument("The length of the row + data should be smaller from 100");
     }if(input.length()>max){
        throw invalid_argument("The length should be smaller from 100");
    }if (input == "~"){
        throw invalid_argument("Invaild input");
    }
   }

   void check_inputs2(int page, int row, int colum,int len){  // to the other functions
     int max = 100;
     if (page < 0 || row < 0 || colum < 0){
         throw invalid_argument( "The input should be minimum zero");
    }if (len >= max ){
        throw invalid_argument("The length should be smaller from 100");
    }if((row+len)>max){
        throw invalid_argument("The length of the row + data should be smaller from 100");
    }
   }

   // maybe its  not usable - need tests
//    int the_next_data(int row,int colum ,Direction direction){
//         if (Direction::Vertical == direction){
//                 row ++;
//                 return row;
//         }else{
//                 colum++;
//                 return colum;
//             }
//    }


// notebook functions
    void Notebook::write (int page, int row, int colum,Direction direction,string input){
        check_inputs  (page,row, colum,input);
        char line = '_';
        if(map_notebbok[make_tuple(page,row,colum)] == line ){         // check if the page is empty
        for (int i=0;i<input.length();i++){
            map_notebbok[make_tuple(page,row,colum)]=input.at(i);
            // the_next_data (row,colum,direction);
            if (Direction::Vertical == direction){
                row ++;
            }else{
                colum++;
            }
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
        char line = '_';
        for (int i =0;i<length; i++){
            if (map_notebbok[make_tuple(page,row,colum)] > 0 ){
                line = map_notebbok[make_tuple(page,row,colum)];
            }else{
                line = '_';
            }
            result += line;
            // the_next_data (row,colum,direction);
             if (Direction::Vertical == direction){
                row ++;
            }else{
                colum++;
            }
        }
        return result;
    }



    void Notebook::erase ( int page, int row, int colum,Direction direction,int length_char) {
        check_inputs2 (page,row,colum,length_char);
         if(map_notebbok[make_tuple(page,row,colum)] == '~' ){
             throw invalid_argument("The place in the notebook has already been deleted");
         }
             for (int i =0 ;i <length_char;i++){
                 map_notebbok[make_tuple(page,row,colum)] = '~';
                //  the_next_data (row,colum,direction);
             if (Direction::Vertical == direction){
                row ++;
            }else{
                colum++;
            }
           }
        }
    



    void Notebook::show ( int page){
        if (page < 0 ) {
            throw invalid_argument("The input page should be 0 or bigger - page not found");
        }
        string from_read;
        for (int i = 0;i<row;i++){
            for (int j =0 ;j<colum;j++){
                from_read += read(page,row,colum,Direction::Horizontal,row);
                cout<<from_read<<endl;
            }
            from_read += '\n';
        }
    }

};
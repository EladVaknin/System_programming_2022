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
// #define MAXIMUM = 100;
constexpr int MAX_LEN = 100;

namespace ariel {
    
    // constructoe  to the main
    // Notebook::Notebook(int page,int row,int colum){
    //    this -> page = page;
    //    this -> row = row;
    //    this -> colum = colum;
    //     char line = '_';
    //     for (size_t i =0 ;i<page;i++){
    //         for (size_t j=0;j<row;j++){
    //             for (size_t k=0;k<colum;k++){
    //                 map_notebbok[make_tuple(i,j,k)] = line;
    //             }
    //         }
    //     }
    //     cout<<"The notebook inizalized"<<endl;
    // }


//cons
   Notebook::Notebook(){
       this -> p = MAX_LEN;
       this -> r = MAX_LEN;
       this -> c = MAX_LEN; 
       this ->map_notebbok = map <place_notebook,char>(); 
       char line = '_';
        for (size_t i =0 ;i<p;i++){
            for (size_t j=0;j<r;j++){
                for (size_t k=0;k<c;k++){
                    map_notebbok[make_tuple(i,j,k)] = line;
                }
            }
        }
    } 



// check input functions - The functions are similar but the arguments are different.
   void check_inputs(int page, int row, int colum,string const & input){  // to write func
     unsigned long max_row = size_t(row)+input.length();
     unsigned long max_colum = size_t(colum)+input.length();
     if (page < 0 || row < 0 || colum < 0){
         throw invalid_argument( "The input should be minimum zero");
     }if((max_row) >= MAX_LEN || (max_colum) >= MAX_LEN){ // need to be 99
        throw invalid_argument("The length of the row/colum + data should be smaller from 100");
     }if(input.length()>= MAX_LEN  || colum >= MAX_LEN){
        throw invalid_argument("The length/colum should be smaller from 100");
    }if (input == "~"){
        throw invalid_argument("Invaild input");
    }
   }

   void check_inputs2(int page, int row, int colum,int len){  // to the other functions
    //  int max = 100;
     int max_len = row +len;
     int max_cul = colum+len;
     if (page < 0 || row < 0 || colum < 0){
         throw invalid_argument( "The input should be minimum zero");
    }if (len >= MAX_LEN || max_len >= MAX_LEN ){
        throw invalid_argument("The length should be smaller from 100");
    }if(colum >=MAX_LEN){
        throw invalid_argument("The colum should be smaller from 100");
    }if((max_cul)>= MAX_LEN){
        throw invalid_argument("The length of the colum + data should be smaller from 100");
    }
   }


// notebook functions
    void Notebook::write (int page, int row, int colum,Direction direction,string input){
        check_inputs  (page,row, colum,input);
        char line = '_';
         if(map_notebbok[make_tuple(page,row,colum)] != line){          //check if the exact location not erased or wirted
                throw invalid_argument("The place in the notebook has been deleted or used");
            }
        for (size_t i=0;i<input.length();i++){
            map_notebbok[make_tuple(page,row,colum)]=input.at(i); 
            if (Direction::Horizontal == direction){
                colum ++;
            }else{
                row ++;
            }if ( map_notebbok[make_tuple(page,row,colum)]=='~'){     //check the next palce
                throw invalid_argument("The palce are deleted");
            }
        }
    }


    string Notebook::read (int page, int row, int colum,Direction direction, int length) {
        check_inputs2 (page,row,colum,length);
        string result ;
        int min = 0;
        char line = '_';
        for (size_t i =0;i<length; i++){
            if (map_notebbok[make_tuple(page,row,colum)] > min ){
                result += map_notebbok[make_tuple(page,row,colum)];
            }
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
             for (size_t i =0 ;i <length_char;i++){
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
        for(size_t k =0 ;k<=page;k++){   
            for (size_t i = 0;i<=r;i++){  
              for (size_t j =0 ;j<=c;j++){ 
                    cout<<map_notebbok[make_tuple(k,i,j)]; 
                
                }
            }
        }
    }










};


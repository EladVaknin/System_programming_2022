#include<stdexcept>
#include<string>
#include<iostream>
#include<vector>
#include <exception>
#include "mat.hpp"

/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */

using namespace std ;

namespace ariel{

        string mat (int c ,int r ,char n1,char m2){
           string result;
           const int min = 33;
           const int max = 127;
           const int num =9;
           int col = c ;
           int row = r;
            //check invaild input
            if (r%2==0||c%2==0){
                throw std::invalid_argument("invaild input - the input should be odd number or bigger from zero");
            }
            if (r == 0 || c ==0 ){
                throw std::invalid_argument("invaild input - the input should be bigger from zero ");
            }
            // The two input tests can be merged, but I did not merge because of Dvir's test file.
            if (r < 0 || c < 0 ){
                throw std::invalid_argument("invaild input - the input should be positive ");
            }
            // if for invaild char from ascii table 
            if ((n1 < min || n1> max)||(m2 < min || m2 > max)){
                throw std::invalid_argument("invaild input - the symbols should in the range");
            }
            // in case r=c=1
            if (r == 1 && c ==1){
                result = n1;
                return result;
            }


            // regular cases
            vector<vector<char>> tmpMatrix(r, vector<char>(c));
            // char tmpMatrix [r][c];
            // initalize all the matrix in the second char
            for (int i= 0;i<r;i++){
                for (int j=0 ;j<c;j++){
                    tmpMatrix[i][j] = m2;
                }
            }            
            int x = 0;
            int y = 0;
            int z =0;
            //working on the first char
             while (col>=(c/2)+1 || row >=(r/2)+1 ){
               // fill the frame in the first char.
               for (int i = x; i < col ;++i){
                   for (int j = z; j<row; ++j){
                       tmpMatrix[j][y] =n1;      // first col
                       tmpMatrix[y][i]=n1;       // first row
                       tmpMatrix[j][col-1] =n1;  // last col
                       tmpMatrix[row-1][i]=n1;   // last row
                  } 
               }
                y += 2;
                z +=2;
                x +=2;
                row -= 2;
                col -= 2;
           }

            // print the matrix
            for (int i =0 ; i<r; i++){
                for (int j=0 ;j <c ;j++){
                    // cout<< result <<tmpMatrix[i][j];
                    result += tmpMatrix [i][j];
                }
                result += '\n';
            }
          
        

            return result;
   
    }

}


 


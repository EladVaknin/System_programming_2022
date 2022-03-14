#include<stdexcept>
#include<string>
#include<iostream>
#include<vector>
// #include <exception>
#include "mat.hpp"

using namespace std ;

namespace ariel{

        string mat (int c ,int r ,char n1,char m2){
           string result = "";
           const int min = 33;
           const int max = 127;
            //check invaild input
            if (r%2==0||c%2==0){
                throw "invaild input - the input should be odd number";
            }
            if (r == 0 || c ==0 ){
                throw "invaild input - the input should be bigger from zero ";
            }
            // The two input tests can be merged, but I did not merge because of Dvir's test file.
            if (r < 0 || c < 0 ){
                throw "invaild input - the input should be positive ";
            }
            // if for invaild char from ascii table 
            if ((n1 < min || n1> max)||(m2 < min || m2 > max)){
                throw "invaild input - the symbols should in the range";
            }
            // in case r=c=1
            if (r == 1){
                result = n1;
                return result;
            }
            // regular cases
            vector <string> v1 ;
            char tmpMatrix [r][c];
            // initalize all the matrix in the second char
            for (int i= 0;i<r;i++){
                for (int j=0 ;j<c;j++){
                    tmpMatrix[i][j] =m2;
                }
            }            
            int x = 0;
            int y = 0;
            int col =c ;
            int row =r;
            //workin on the first char
            // while (x < r && y < c ){
           while (x < c ){
               for (int i = x; i < c; ++i){
               // fill the first frame in the first char.
               tmpMatrix[y][i] = n1;
               tmpMatrix[i][y] = n1;
               tmpMatrix[row-1][i] =n1;
               tmpMatrix[i][col-1] =n1;
               }
        
                y += 2;
                x +=2  ;
                row -= 2;
                col -= 2;
           }

            //    for (int j = y; j < c; j++){
            //    // fill the first and last colum in  the first char.
            //    tmpMatrix[0][j] = n1;
            //    tmpMatrix[c-1][j] = n1;
            //     }  
           // }

          // r= 7 ,c = 9
            // "@@@@@@@@@
		    // "@-------@
			// "@-@@@@@-@
			// "@-@---@-@
			// "@-@@@@@-@
			// "@-------@
			// "@@@@@@@@@
          
            

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
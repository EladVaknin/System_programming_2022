#include<stdexcept>
#include<string>
#include<iostream>
#include<vector>
// #include <exception>
#include "mat.hpp"

using namespace std ;

namespace ariel{

        string mat (int r ,int c,char n1,char m2){
           string result = " ";
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
            int x = 0;
            int y = 0;
            while (x < r && y < c ){
            for (int i = 0; i < r; i++){
               // fill the first and last line in the first char.
               tmpMatrix[i][0] = n1;
               tmpMatrix[i][c-1] = n1;
                  }
               for (int j = 0; j < c; j++){
               // fill the first and last colum in  the first char.
               tmpMatrix[0][j] = n1;
               tmpMatrix[c-1][j] = n1;
               // ...

                }  
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
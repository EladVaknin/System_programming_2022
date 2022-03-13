#include<stdexcept>
#include<string>
#include<iostream>
#include<vector>
#include "mat.hpp"

using namespace std ;

namespace ariel{

        string mat (int r ,int c,char n,char m){
            string result = " ";
            int min;
            int max;

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
            if ((n < min || n> max)||(m < min || m > max)){
                throw "invaild input - the symbols should in the range";
            }
            // in case r=c=1
            if (r==1){
                result = n;
                return result;
            }
            // regular cases
            vector <string> v1 ;
            char tmpMatrix [r][c];
            int x = 0;
            int y = 0;
            while (x < r && y <c ){
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
               // fill the first and last line in the first char.
               tmpMatrix[i][0] = n;
               tmpMatrix[i][c-1]=n;
               // fill the first and last colum in  the first char.
               tmpMatrix[0][j] = n;
               tmpMatrix[c-1][j] = n;
               // ...

                }  
                }
            }

            // print the matrix
            for (int i =0 ; i<r; i++){
                for (int j=0 ;j <c ;j++){
                    cout<< result <<tmpMatrix[i][j];
                }
            }
          
        

            return result;
   
    }
}
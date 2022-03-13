#include<stdexcept>
#include<string>
#include<iostream>
#include<vector>
#include "mat.hpp"

using namespace std ;

namespace ariel{
        string mat (int r ,int c,char n,char m){
            string result = "";

            //check invaild input
            if (r%2==0||c%2==0){
                throw "invaild input - the input should be odd number";
            }
            // in case r=c=1
            if (r==1){
                result = n;
                return result;
            }
            // regular cases
            vector <string> v1 ;
            string tmpMatrix [r][c];
            int x = 0;
            int y = 0;
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
               // fill the first and last line in the first char.
               tmpMatrix[i][0] = n;
               tmpMatrix[i][c-1]=n;
               // fill the first and last colum in  the first char.
               tmpMatrix[0][j] = n;
               tmpMatrix[c-1][j] = n;






                }  
            }
          
        

            return result;
   
    }
}
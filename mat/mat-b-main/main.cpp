/**
 * Author: Elad Vaknin
 */

#include "mat.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>
#include "mat.cpp"

using namespace std;
// symbols between the range 33 -127 by ascii table
char const PosSymbols [100] = {'!', '"', '#', '$', '%', '&', '(', ')', '*', '+',',', '-', '.', '/', 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', 
'@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' , 'O', 
'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[' , ']', '^' , '_' , 
'`' , 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' ,'{', '|', '}', '~' ,'1' ,'2' ,'3' ,'4','5','6'};




    int main() {

    //randoms numbers 0- 100
	int random1 ,random2;
	random1 = rand() % 100;
	random2 = rand() % 100;
	int random3 = rand () % 100;
	int random4 = rand () % 100;

     if (random1 %2 == 0 || random2 % 2 == 0 ){ 
     while (random1%2 != 0 && random2%2 != 0){
         	random1 = rand() % 100;
	        random2 = rand() % 100;
     }
    }

    cout<<ariel::mat (9 ,7 ,'@','-')<<endl;

    // ariel::mat(random1 ,random2 ,PosSymbols[random3],PosSymbols[random4]);
    // cout<<ariel::mat (random1 ,random2 ,PosSymbols[random3],PosSymbols[random4])<<endl;
    }
/**
 * Author: Elad Vaknin
 */

#include "mat.hpp"
#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include "mat.cpp"

using namespace std;

    int main() {
   // basic checks
    cout<<ariel::mat (1 ,1 ,'@','-')<<endl;
    //should print : 
    //@

    cout<<""<<endl;

    cout<<ariel::mat (9 ,7 ,'@','-')<<endl;
    //should print : 
    // @@@@@@@@@
    // @-------@
    // @-@@@@@-@
    // @-@---@-@
    // @-@@@@@-@
    // @-------@
    // @@@@@@@@@


    cout<<""<<endl;

    cout<<ariel::mat (9 ,9 ,'@','-')<<endl;
    // should print :
    // @@@@@@@@@
    // @-------@
    // @-@@@@@-@
    // @-@---@-@
    // @-@-@-@-@
    // @-@---@-@
    // @-@@@@@-@
    // @-------@
    // @@@@@@@@@

    cout<<ariel::mat (9 ,9 ,'G','L')<<endl;
    // should print :
    // GGGGGGGGG
    // GLLLLLLLG
    // GLGGGGGLG
    // GLGLLLGLG
    // GLGLGLGLG
    // GLGLLLGLG
    // GLGGGGGLG
    // GLLLLLLLG
    // GGGGGGGGG

    cout<<""<<endl;

    cout<<ariel::mat (13 ,5 ,'G','L')<<endl;
    //should print :
    // GGGGGGGGGGGGG
    // GLLLLLLLLLLLG
    // GLGGGGGGGGGLG
    // GLLLLLLLLLLLG
    // GGGGGGGGGGGGG


    cout<<""<<endl;

    cout<<ariel::mat (3 ,11 ,'@','-')<<endl;
    // should print :
    // @@@
    // @-@
    // @-@
    // @-@
    // @-@
    // @-@
    // @-@
    // @-@
    // @-@
    // @-@
    // @@@

    cout<<""<<endl;


// invaild inputs
    try{   
        cout<<ariel::mat(-1,7,'$','*')<<endl;   //negetive inputnumber
    }catch (exception& e){
        cout<<"The exception is : "<<e.what()<<endl;
    }
    try{
        cout<<ariel::mat(6,2,'$','*')<<endl;   // even inputs
    }catch (exception& e2){
        cout<<"The exception is : "<<e2.what()<<endl;
    }
    try{
        cout<<ariel::mat(5,0,'$','*')<<endl;    // input zero
    }catch (exception& e3){
        cout<<"The exception is : "<<e3.what()<<endl;
    }
    try{
        cout<<ariel::mat(5,9,'  ',' ')<<endl;    // the chars not in the ascii range
    }catch (exception& e3){
        cout<<"The exception is : "<<e3.what()<<endl;
    }
     


    cout<<""<<endl;

    // try yourself : 
    int col,row;
    char  s1,s2;
    cout<<"Please enter odd number for the col:"<<endl;
    cin>>col;
    cout<<"Please enter odd number for the row:"<<endl;
    cin>>row;
    cout<<"Please choose symbol1:"<<endl;
    cin>>s1;
    cout<<"Please choose  symbol2:"<<endl;
    cin>>s2;
    cout<<"The result:"<<endl;
    cout<<ariel::mat(col,row,s1,s2)<<endl;


// random checks
   // symbols between the range 33 -127 by ascii table
    char const PosSymbols [100] = {'!', '"', '#', '$', '%', '&', '(', ')', '*', '+',',', '-', '.', '/', 
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', 
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' , 'O', 
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[' , ']', '^' , '_' , 
    '`' , 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' ,'{', '|', '}', '~' ,'1' ,'2' ,'3' ,'4','5','6'};

    //randoms numbers 0- 100
    srand(time(0));
	int random1 ,random2 ,random3,random4;
	random1 = rand() % 100;
	random2 = rand() % 100;
    // random3 = rand () % 100;
	// random4 = rand () % 100;

     if (random1 %2 == 0 || random2 % 2 == 0 || random1 == 0 || random2  == 0){ 
     while (random1%2 != 0 && random2%2 != 0 && random1 != 0 && random2  != 0){
            srand(time(0));
         	random1 = rand() % 100;
	        random2 = rand() % 100;
     }
     }
     cout<<"the random numbers: "<<endl;
     cout<<random1<<endl;
     cout<<random2<<endl;
    //  cout<<random3<<endl;
    //  cout<<random4<<endl;
     cout<<"the result is:"<<endl;
     cout<<ariel::mat(random1,random2,'*','$')<<endl; 
    //  cout<<ariel::mat(random1,random2,PosSymbols[random3],PosSymbols[random4])<<endl; 
    }
    
    
    
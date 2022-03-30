
#include "Notebook.hpp"
#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include "Notebook.cpp"
// #include "doctest.h"

// #include "sources/Notebook.hpp"
// #include "sources/Direction.hpp"





using namespace std;
using namespace ariel;

    int main() {

        // Notebook notebook;

        int page,row,colum;
    //     cout<<"To create a notebook please choose the num of page :"<<endl;
    //     cin>>page;
    //     cout<<"Please choose the num of rows :"<<endl;
    //     cin>>row;
    //     cout<<"Please choose the num of colums :"<<endl;
    //     cin>>colum;
    //    // create my nootbook
        // Notebook notebook (page,row,colum);
        Notebook notebook;
        int x = 1;
        int y = 3;
        int z = 4;
        string input = "elad";

      //  notebook.write (x,y,z,Direction::Horizontal,input);   // work
        // notebook.write(1,0,0,Direction::Vertical,"eladgamal");
        // cout<<"finis write"<<endl;
        // cout<<  notebook.read(1,0,0,Direction::Vertical,9)<<endl; //work
        // cout<<"start show"<<endl;
        // notebook.show(1);    // work

       for ( int i=100; i<200;i++){
        Notebook note;
            note.write(1,i-100,0,Direction::Vertical,"Look at me");
            note.write(1,i-100,2,Direction::Horizontal,"I'm Mr. meeseeks");
            cout<<i<<endl;
    }
        
        // cout<<"agik "<<endl;
        // cout<<  notebook.read(x,y,z,Direction::Horizontal,input.length())<<endl; //work
   



    }
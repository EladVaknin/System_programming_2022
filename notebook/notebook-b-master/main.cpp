
#include "Notebook.hpp"
#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include "Notebook.cpp"




using namespace std;
using namespace ariel;

    int main() {

        // Notebook notebook;

        int page,row,colum;
        cout<<"To create a notebook please choose the num of page :"<<endl;
        cin>>page;
        cout<<"Please choose the num of rows :"<<endl;
        cin>>row;
        cout<<"Please choose the num of colums :"<<endl;
        cin>>colum;
       // create my nootbook
        Notebook notebook (page,row,colum);
        int x = 1;
        int y = 3;
        int z = 4;
        string input = "elad";
        notebook.write (x,y,z,Direction::Horizontal,input);
        notebook.read(x,y,z,Direction::Horizontal,input.length());
   



    }
#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include<vector>
#include "Matrix.hpp"
#include "Matrix.cpp"
// #pragma once




using namespace std;
using namespace zich;

    int main() {


    


    // vectors
    vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};    //3x3
    vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
    vector<double> vec1 = {1,1,1,1,1,1,1,1,1};  //3x3
    vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
    vector<double> vec3 = {1,1,1,1,1,1,1,1,1,1,1,1};//4x3
    //matrixs
    Matrix mat_identity_3(identity_3,3,3);
    Matrix mat_identity_4(identity_4,4,4);
    Matrix mat1(vec1, 3,3);
    Matrix mat2(vec2,3,4);
    Matrix mat3(vec3, 4, 3);


    // *
    cout<<"mat 1 is:"<< mat1 << "mat idententity is : "<< mat_identity_3<<endl;
    cout<<"mat1 * mat idententity :"<< mat1 * mat_identity_3<<endl;
    cout<<"<"<<endl;
    cout<<"mat 2 is:"<< mat2 << "mat idententity is : "<< mat_identity_4<<endl;
    cout<<"mat2 * mat idententity :"<< mat2 * mat_identity_4<<endl;
    cout<<"<"<<endl;
    cout<<"mat 2 is:"<< mat2 << "mat 3 : "<< mat3<<endl;
    // cout<<"mat2 * mat3:"<< mat2 * mat3<<endl;    // not true
    cout<<"<"<<endl;




   /////////////++++++////////////////////
    vector<double> up = {1,2,3,4,5,6,7,8,9};    //3x3
    vector<double> dwon = {9,8,7,6,5,4,3,2,1};;    //3x3
    Matrix plus(up, 3,3);
    Matrix plus2(dwon, 3,3);
    cout<<"mat plus:"<< plus << "mat plus2 : "<< plus2<<endl;
    cout<<"after + need to be eq"<<endl;
    Matrix tmp5 = plus +plus2;
    cout<<tmp5<<endl;

   /////////////--------////////////////////
    cout<<"Minus:"<<endl;
    Matrix tmp6= plus -plus2;
    cout<<tmp6<<endl;











    // // try it yourself
    // int col,row;
    // double vectorNum;
    // cout<<"Please enter number for the col:"<<endl;
    // cin>>col;
    // cout<<"Please enter number for the row:"<<endl;
    // cin>>row;
    // cout<<"Please enter any number for the vector:"<<endl;
    // cin>>vectorNum;
    // vector<double> tmp ;
    // for (double i = 0 ;i<col;i++){
    //     tmp[i].push_back(vectorNum);
    // }
    // Matrix matrix1 (tmp,row,col);
    // cout<<"Thats your matrix:"<<endl;
    // cout<<matrix1<<endl;

    

}


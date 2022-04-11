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
        // int row =2 ;
        // int col =2;
        // string result;
        // vector <double> tmpMatrix = {2,2,2,2};
        // // Matrix::Matrix mat (tmpMatrix,row,col);
        // for (int i =0 ; i<row; i++){
        //         for (int j=0 ;j <col ;j++){
        //             // cout<< result <<tmpMatrix[i][j];
        //             // result += mat [i][j];
        //             cout<<result<<endl;
        //         }
        //         result += '\n';
        //         cout<<result<<endl;
        //     }
    // vector<double> identity = {1, 1, 1, 1, 1, 1, 1 ,1 ,1};
    // vector<double> arr_c = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    // // vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
    // // vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
    // // vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};

    // // Matrix mat5{arr_e,4,3};
    // Matrix mat1{identity,3,3};
    // Matrix mat3{arr_c,3,3};
    // // Matrix mat4{arr_d,3,3};
    // // Matrix mat6{arr_f,4,3};
    // // Matrix mat7{arr_h,4,3};
    
    // // cout << (mat1)  << endl;
    // // cout << (mat3)  << endl;
    // cout << (mat1*mat3 == mat1)  << endl;



    /////// student 1 :
    cout<<"st 1 run"<<endl;
    vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
    Matrix mat_identity_3(identity_3,3,3);
    cout<<"start to build"<<endl;
    vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
    vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
    vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
    vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
    vector<double> _vec_ = {1,1,1,1,1,1,1,1,1,1,1,1};//4x3
    Matrix _mat_(_vec_, 4, 3);
    Matrix mat1(vec1, 3,3);
    Matrix mat_arr(arr,3,3);
    Matrix mat2(vec2,3,4);
    Matrix mat_identity_4(identity_4,4,4);
    cout<<mat1<<endl;
    cout<<mat_identity_3<<endl;

    cout<<mat1*mat_identity_3<<endl;



    }

#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include<vector>
#include "Matrix.hpp"


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
    vector<double> identity = {1, 1, 1, 1, 1, 1, 1 ,1 ,1};
    vector<double> arr_c = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    // vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
    // vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
    // vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};

    // Matrix mat5{arr_e,4,3};
    Matrix mat1{identity,3,3};
    Matrix mat3{arr_c,3,3};
    // Matrix mat4{arr_d,3,3};
    // Matrix mat6{arr_f,4,3};
    // Matrix mat7{arr_h,4,3};
    
    // cout << (mat1)  << endl;
    // cout << (mat3)  << endl;
    cout << (mat1*mat3 == mat1)  << endl;


    }

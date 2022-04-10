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




    // vector<vector<int>> matrix1;
    // vector<vector<int>> matrix2;
    // vector<vector<int>> matrix3;
    // vector<double> arr;
    // arr = {1,1,1,1,1,1,1,1,1};
    // Matrix(arr, 3, 3);
    // matrix1 = {{1,1,1},{1,1,1},{1,1,1}};
    // matrix2 = {{2,2,2},{2,2,2},{2,2,2}};
    // matrix3 = {{1,1},{1,1},{1,1}};
    cout << "****operator '++'" << endl;
    vector<double> arra;
    vector<double> arrb;
    vector<double> arrc;
    int a = 5;
    arra = {1,1,1,1,1,1,1,1,1};
    arrb = {1,1,1,1,1,1,1,1,2};
    arrc = {1,1,1,1,1,1,1,1,1};
    zich::Matrix a_{arra,3,3};
    zich::Matrix b_{arrb,3,3};
    zich::Matrix c_{arrc,3,3};
    cout << (a_ * b_)  << endl;
    cout << (a_ * a)  << endl;
    cout << (a * a_)  << endl;
    cout << (a_ = b_)  << endl;
    cout << (a_ + b_) << endl;
    cout << (a_ - b_) << endl;
    cout << (b_ - a_) << endl;
    cout << a_ << endl;
    cout << (a_ > b_)  << endl;
    cout << (a_ < b_)  << endl;
    cout << (a_ >= b_)  << endl;
    //cout

    }

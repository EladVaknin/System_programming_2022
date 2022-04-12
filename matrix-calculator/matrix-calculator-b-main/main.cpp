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



    /////// student 1  - passed !! :

    // vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
    // Matrix mat_identity_3(identity_3,3,3);
    // vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
    // vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
    // vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
    // vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
    // vector<double> _vec_ = {1,1,1,1,1,1,1,1,1,1,1,1};//4x3
    // Matrix _mat_(_vec_, 4, 3);
    // Matrix mat1(vec1, 3,3);
    // Matrix mat_arr(arr,3,3);
    // Matrix mat2(vec2,3,4);
    // Matrix mat_identity_4(identity_4,4,4);
    // cout<<mat1<<endl;
    // cout<<mat_identity_3<<endl;

    // cout<<mat1*mat_identity_3<<endl;

    // cout<<mat2<<endl;
    // cout<<"<"<<endl;
    // cout<<mat_identity_4<<endl;
    // cout<<"<"<<endl;
    // cout<<mat2*mat_identity_4<<endl;

    // mat2*_mat_ == mat1;
    // cout<<mat2<<endl;
    // cout<<" "<<endl;
    // cout<<_mat_<<endl;
    // cout<<" "<<endl;
    // cout<<mat1<<endl;
    // cout<<" "<<endl;
    // cout<<mat2*_mat_<<endl;



    /////// student 2 :
// std::vector<double> arr1 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
// std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
// std::vector<double> arr_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};
// std::vector<double> arr_c = {2, 0, 0, 0, 2, 0, 0, 0, 2};
// std::vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
// std::vector<double> arr_e= {4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};
// std::vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
// std::vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};

// std::vector<double> arr1_1 = {0, 1, 1, 1, 0, 1, 1, 1,0};
// std::vector<double> unit_matrix_1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
// std::vector<double> arr_b_1 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
// std::vector<double> arr_c_1 = {3, 1, 1, 1, 3, 1, 1, 1, 3};
// std::vector<double> arr_d_1= {5, 1, 1, 1, 5, 1, 1, 1, 5};
// std::vector<double> arr_e_1= {5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1};
// std::vector<double> arr_f_1= {6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1};
// std::vector<double> arr_h_1= {10, 1, 1,1, 10, 1, 1, 1, 10, 1, 1, 1};

// Matrix mat_un{arr1,3,3};
// Matrix mat1{unit_matrix,3,3};
// Matrix mat2{arr_b,3,3};
// Matrix mat3{arr_c,3,3};
// Matrix mat4{arr_d,3,3};
// Matrix mat5{arr_e,4,3};
// Matrix mat6{arr_f,4,3};
// Matrix mat7{arr_h,4,3};

// Matrix mat_un_1{arr1_1,3,3};
// Matrix mat1_1{unit_matrix_1,3,3};
// Matrix mat2_2{arr_b_1,3,3};
// Matrix mat3_3{arr_c_1,3,3};
// Matrix mat4_4{arr_d_1,3,3};
// Matrix mat5_5{arr_e_1,4,3};
// Matrix mat6_6{arr_f_1,4,3};
// Matrix mat7_7{arr_h_1,4,3};

//   CHECK_THROWS(mat3-=mat7);       // -= 

// cout<<mat3<<endl;
// cout<<"^3^"<<endl;
// cout<<mat7<<endl;
// cout<<"^7^"<<endl;
// cout<<mat3 -= mat7<<endl;
// cout<<"^3-7^"<<endl;

// ==      !=     == student 2 problem
// cout<<mat5==mat7<<endl;
// cout<<mat5<<endl;
// cout<<"^5^"<<endl;
// cout<<mat7<<endl;
// cout<<"^7^"<<endl;
// bool ans = mat5 == mat7;
// cout<<ans<<endl;
// bool ans2 = mat5 != mat7;
// cout<<ans2<<endl;






//*= 
// mat1 *= mat1 ;
// cout<<mat1<<endl;
// cout<<"^1^"<<endl;
// // CHECK(mat1 == mat2);
// bool ans = mat1 == mat2;
// cout<<ans<<endl;
// mat1-=mat3;
// mat1*=4;
// CHECK(mat4 == mat1);
// mat1-=mat2;
// mat1*=2;
// CHECK(mat3 == mat1);
// mat5*= 9;
// mat7*=4;







// std::vector<double> arr_cin = {1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1};
// Matrix mat_cin{arr_cin,3,4};

// bool equalto = false;

// // (mat5-mat6,mat7-mat6)
// cout<<mat5<<endl;
// cout<<"^5^"<<endl;
// cout<<mat6<<endl;
// cout<<"^6^"<<endl;
// cout<<mat5-mat6<<endl;
// cout<<"^5-6^"<<endl;
// cout<<mat7<<endl;
// cout<<"^7^"<<endl;
// cout<<mat6<<endl;
// cout<<"^6^"<<endl;
// cout<<mat7-mat6<<endl;
// cout<<"^7-6^"<<endl;









/// stream in ------------ only this
// std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
// istringstream is1{"[1 1 1 ],[1 1 1], [1 1 1]\n"};
// Matrix mat1{unit_matrix,3,3};
// is1 >> mat1;
// cout<<mat1<<endl;
    
// istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};
//  cout<<mat1<<endl;
//  cout<<"befor"<<endl;
//  is7 >> mat1;
//  cout<<mat1<<endl;








//student 3    -- paasseee


// CHECK_NOTHROW(C * D);
// CHECK_NOTHROW(C *= D);

//  vector<double> vector;
//  for (double i = 0; i < 30; ++i) {
//         vector.push_back(i);
//     }
//     Matrix C{vector, 5, 6};
//     vector.clear();
//     for (double i = 0; i < 60; ++i) {
//         vector.push_back(i);
//     }
//     Matrix D{vector, 6, 10};

//     cout<<C<<endl;
//     cout<<"^c^"<<endl;
//     cout<<D<<endl;
//     cout<<"^D^"<<endl;
    
//     cout<<C*=D<<endl;
//     cout<<"^C*D"<<endl;
////// +=
//     vector<double> arr={1,2,3,4,5,6,7,8,9,10,11,12};
//     Matrix A(arr,4,3);
//     Matrix B(arr,2,6);
//         Matrix C(arr,3,4);

// //  CHECK_THROWS(C+=A);     
//     cout<<C<<endl;
//     cout<<"^c^"<<endl;
//     cout<<A<<endl;
//     cout<<"^a^"<<endl;
    
//     C+=A;
//     cout<<C<<endl;
//     cout<<"^c+=a"<<endl;


    }

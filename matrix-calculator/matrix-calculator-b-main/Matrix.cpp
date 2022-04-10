/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 
and becuse its my second time that i made the course i base on my last year implem 
https://github.com/EladVaknin/CPP-/tree/master/number%20with%20units */


#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <fstream>
using namespace std;

namespace zich{

    //cos 
    Matrix::Matrix(vector<double> mat,int rows,int cols){
        check_inputs (mat,rows,cols);
        vector<double> ans;
        for (int i = 0; i < rows; ++i) {
             tmpMatrix.push_back(ans);
          for (int j = 0; j < colum; ++j) {
            int tmp = (i*colum) + j;
            tmpMatrix.at(i).push_back(mat.at(tmp));
            }
        }
    }

    Matrix::Matrix (int rows,int cols){
        vector< vector<double>> tmp; // inizalize the matrix to 0
        this ->  tmpMatrix = tmp;
        this -> row=rows;
        this ->colum = cols;
    }

    Matrix::Matrix(const Matrix& other_mat){
        vector<vector<double>> mat;
        for (int i = 0; i < other_mat.tmpMatrix.size(); i++){
            vector<double> row_iterator;
            for (int j = 0; j < other_mat.tmpMatrix[0].size(); j++){
                row_iterator.push_back(other_mat.tmpMatrix.at(i).at(j));
            }
            mat.push_back(row_iterator);
        }
        this->tmpMatrix = mat;
    }


    void check_inputs(vector<double> mat, int row,int col){
        if (mat.size() != (row*col)){
            throw invalid_argument ("invaild input - the size should be match");
        }if(row <=0 || col <=0){
            throw invalid_argument ("invaild input - row or col should be bigger from zero");
        }
    }
  

    // operators:
    //+
    Matrix& Matrix::operator++ (){
    }
    Matrix Matrix::operator ++ (int skalar){
        Matrix ans = *this;
        ++(*this);
        return ans;
    }
    Matrix Matrix::operator+ (const Matrix &other_mat)const {

    } 
    Matrix Matrix::operator+ (){

    }
    Matrix& Matrix::operator+= (const Matrix &other_mat){

    }


    // -
    Matrix& Matrix::operator -- (){

    }
    Matrix Matrix::operator -- (int skalar){
        Matrix ans = *this;
        --(*this);
        return ans;
    }
    Matrix Matrix::operator- () const {

    }
    Matrix Matrix::operator- (const Matrix &other_mat) {

    }
    Matrix& Matrix::operator-= (const Matrix &mat){

    }


    //+=   /-=

    // *
    Matrix Matrix::operator* (const Matrix &other_mat)const{

    }
    Matrix Matrix::operator* (double skalar, const Matrix &mat){

    }
    Matrix Matrix::operator* (double skalar)const{

    }
    Matrix Matrix::operator *= (double skalar){

    }


    // < > = 
    bool Matrix::operator> (const Matrix &other_mat) const{
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        double sum1 = 0;
        double sum2 = 0 ;
        for (int i =0 ;i<this->tmpMatrix.size();i++){
            for(int j =0;this->tmpMatrix[0].size();j++){
                sum1 += this ->tmpMatrix.at(i).at(j);
                sum2 += other_mat.tmpMatrix.at(i).at(j);
            }
        }
        if (sum1 > sum2){
            return true;
        }else{
            return false;
        }

    }

    bool Matrix::operator< (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        double sum1 = 0;
        double sum2 = 0 ;
        for (int i =0 ;i<this->tmpMatrix.size();i++){
            for(int j =0;this->tmpMatrix[0].size();j++){
                sum1 += this ->tmpMatrix.at(i).at(j);
                sum2 += other_mat.tmpMatrix.at(i).at(j);
            }
        }
        if (sum1 < sum2){
            return true;
        }else{
            return false;
        }

    }
    bool Matrix::operator == (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        for (int i =0 ;i<this->tmpMatrix.size();i++){
            for(int j =0;this->tmpMatrix[0].size();j++){
                if (this->tmpMatrix.at(i).at(j) != other_mat.tmpMatrix.at(i).at(j)){
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator<= (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        return !(*this>other_mat);

    }
    bool Matrix::operator>= (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        return !(*this<other_mat);

    }
    bool Matrix::operator!= (const  Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        // for (int i =0 ;i<this->tmpMatrix.size();i++){
        //     for(int j =0;this->tmpMatrix[0].size();j++){
        //         if (this->tmpMatrix.at(i).at(j) == other_mat.tmpMatrix.at(i).at(j)){
        //             return false;
        //         }
        //     }
        // }
        return !(*this == other_mat);
    }



   


    // << >> 
        ostream& operator<< (ostream& out, const Matrix& mat){
            for (int i =0 ; i< mat.row;i++){
                for (int j=0;j<mat.colum;j++){
                    out<<mat.tmpMatrix.at(i).at(j);
                }
                out<<endl;
            }
        return out;

    }
        istream& operator>> (istream& in, const Matrix& mat){
            for (int i =0 ; i< mat.row;i++){
                for (int j=0;j<mat.colum;j++){
                in>>mat.tmpMatrix.at(i).at(j);
            }
            // in >>endl;
        }
        return in;


    }



}


  // void check_size (const Matrix &mat,const Matrix &other_mat){
    //     if (mat.size()!= other_mat.tmpMatrix.size()){
    //         throw invalid_argument ("invaild input - the size should be match");
    //     }
    // }

//  // operators:
//     //+
//     void operator++ (const Matrix &mat){
        
//     }
//     Matrix operator+ (const Matrix &mat ) {
//         Matrix ans (mat);
//         for (int i = 0;i<mat.row;i++){
//             for (int j =0 ;mat.colum;j++){
//                 ans.tmpMatrix.at(i).at(j) +=  tmpMatrix.at(i).at(j) ;   // not full;
//             }
//         }
//         return ans;
//     }
//     Matrix operator+ (const Matrix &mat ,const Matrix &other_mat){
//         return mat;
//     }
//     Matrix operator+ (const Matrix &mat ,double num){
//         return mat;
//     }
//     Matrix operator+ (double num,Matrix &mat){
//         return mat;
//     }  

//     // -
//     void operator -- (const Matrix &mat){
   
//     }
//     // Matrix operator-- (int);
//     Matrix operator- (const Matrix &mat ,const Matrix &other_mat){
//         return mat;
//     }
//     Matrix operator- (const Matrix &mat) {
//         return mat;
//     }
//     Matrix operator- (const Matrix &mat ,double num){
//         return mat;

//     }
//     Matrix operator- (double num,const Matrix &mat){
//         return mat;
//     }

//     //+=-
//     // Matrix& operator+= (const Matrix &mat,const Matrix &other_mat){
//     //     return mat;
//     // }
//     void operator+= (const Matrix &mat,double num){

//     }
//     void operator-= (const Matrix &mat,double num){

//     }
//     // Matrix& operator-= (const Matrix &mat,const Matrix &other_mat){
//     //     return mat;
//     // }
//     void operator-= (double num ,const Matrix &mat){

//     }


//     // *
//     Matrix operator* (const Matrix &mat,double skalar){
//         return mat;
//     }
//     Matrix operator* (double skalar, const Matrix &mat){
//         return mat;
//     }
//     void operator *= (const Matrix &mat,const Matrix &other_mat){

//     }
//     void operator *= (const Matrix &mat,double skalar){

//     }
//     void operator *= (double skalar,const Matrix &mat){

//     }
//     void operator *= (const double &mat,const Matrix &other_mat){

//     }


//     // < > = 
//     bool operator> (const Matrix &mat,const Matrix &other_mat) {
//         if (mat.tmpMatrix.size() != other_mat.tmpMatrix.size()){
//             throw invalid_argument ("invaild input - the size should be match");
//         }
//         double sum1 = 0;
//         double sum2 =0;
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 sum1 += mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         for (int i =0 ; i< other_mat.row;i++){
//             for (int j=0;j<other_mat.colum;j++){
//                 sum2 += other_mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         if (sum1 > sum2){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     bool operator< (const Matrix &mat,const Matrix &other_mat) {
//         if (mat.tmpMatrix.size() != other_mat.tmpMatrix.size()){
//             throw invalid_argument ("invaild input - the size should be match");
//         }
//         double sum1 = 0;
//         double sum2 =0;
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 sum1 += mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         for (int i =0 ;i< other_mat.row;i++){
//             for (int j=0;j<other_mat.colum;j++){
//                 sum2 += other_mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         if (sum1 < sum2){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     bool operator == (const Matrix &mat,const Matrix &other_mat){
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 if (mat.tmpMatrix.at(i).at(j) != other_mat.tmpMatrix.at(i).at(j)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     bool operator<= (const Matrix &mat,const Matrix &other_mat) {
//         if (mat.tmpMatrix.size() != other_mat.tmpMatrix.size()){
//           throw invalid_argument ("invaild input - the size should be match");
//         }
//         double sum1 = 0;
//         double sum2 =0;
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 sum1 += mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         for (int i =0 ;i< other_mat.row;i++){
//             for (int j=0;j<other_mat.colum;j++){
//                 sum2 += other_mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         if (sum1 <= sum2){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     bool operator>= (const Matrix &mat,const Matrix &other_mat) {
//         if (mat.tmpMatrix.size() != other_mat.tmpMatrix.size()){
//             throw invalid_argument ("invaild input - the size should be match");
//         }
//         double sum1 = 0;
//         double sum2 =0;
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 sum1 += mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         for (int i =0 ;i< other_mat.tmpMatrix.size();i++){
//             for (int j=0;j<other_mat.tmpMatrix[0].size();j++){
//                 sum2 += other_mat.tmpMatrix.at(i).at(j);
//             }
//         }
//         if (sum1 >= sum2){
//             return true;
//         }else{
//             return false;
//         }
//     }

//     bool operator!= (const Matrix &mat,const  Matrix &other_mat) {
//         for (int i =0 ; i< mat.row;i++){
//             for (int j=0;j<mat.colum;j++){
//                 if (mat.tmpMatrix.at(i).at(j) == other_mat.tmpMatrix.at(i).at(j)){
//                     return false;
//                 }
//             }
//         }
//         return true; 
//     }

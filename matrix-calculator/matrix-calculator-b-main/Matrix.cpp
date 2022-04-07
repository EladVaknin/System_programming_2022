/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */

#include <iostream>
#include "Matrix.hpp"
#include <vector>
#include <fstream>
using namespace std;

namespace zich{

    //cos 
    Matrix::Matrix(vector<double>,int rows,int cols){
        vector<double> tmp (row*colum,0); // inizalize the matrix to 0
        this ->  tmpMatrix = tmp;
        this -> row=rows;
        this ->colum = cols;
    }

    Matrix::Matrix (int rows,int cols){
        vector<double> tmp (row*colum,0); // inizalize the matrix to 0
        this ->  tmpMatrix = tmp;
        this -> row=rows;
        this ->colum = cols;
    }



    void chek_inputs(vector<double> mat, int row,int col){
        if (mat.size() != (row*col)){
            throw invalid_argument ("invaild input - the size should be match");
        }if(row <=0 || col <=0){
            throw invalid_argument ("invaild input - row or col should be bigger from zero");
        }
    }
    


    // operators:
    //+
    void operator++ (const Matrix &mat){
    }
    //Matrix operator++ (int);
    Matrix operator+ (const Matrix &mat ) {
        return mat;
    }
    Matrix operator+ (const Matrix &mat ,const Matrix &other_mat){
        return mat;
    }
    Matrix operator+ (const Matrix &mat ,double num){
        return mat;
    }
    Matrix operator+ (double num,Matrix &mat){
        return mat;
    }  

    // -
    void operator -- (const Matrix &mat){
   
    }
    // Matrix operator-- (int);
    Matrix operator- (const Matrix &mat ,const Matrix &other_mat){
        return mat;
    }
    Matrix operator- (const Matrix &mat) {
        return mat;
    }
    Matrix operator- (const Matrix &mat ,double num){
        return mat;

    }
    Matrix operator- (double num,const Matrix &mat){
        return mat;
    }

    //+=-
    // Matrix& operator+= (const Matrix &mat,const Matrix &other_mat){
    //     return mat;
    // }
    void operator+= (const Matrix &mat,double num){

    }
    void operator-= (const Matrix &mat,double num){

    }
    // Matrix& operator-= (const Matrix &mat,const Matrix &other_mat){
    //     return mat;
    // }
    void operator-= (double num ,const Matrix &mat){

    }


    // *
    Matrix operator* (const Matrix &mat,double skalar){
        return mat;
    }
    Matrix operator* (double skalar, const Matrix &mat){
        return mat;
    }
    void operator *= (const Matrix &mat,const Matrix &other_mat){

    }
    void operator *= (const Matrix &mat,double skalar){

    }
    void operator *= (double skalar,const Matrix &mat){

    }
    void operator *= (const double &mat,const Matrix &other_mat){

    }


    // < > = 
    bool operator> (const Matrix &mat,const Matrix &other_mat) {
        // need to add the checks size
        double sum1 = 0;
        double sum2 =0;
        for (int i =0 ; i< mat.row;i++){
            for (int j=0;j<mat.colum;j++){
                sum1 += mat.pointer[i][j];
            }
        }
        for (int i =0 ; i< other_mat.row;i++){
            for (int j=0;j<other_mat.colum;j++){
                sum2 += other_mat.pointer[i][j];
            }
        }
        if (sum1 > sum2){
            return true;
        }else{
            return false;
        }
    }
    bool operator< (const Matrix &mat,const Matrix &other_mat) {
        // need to add the checks size
        double sum1 = 0;
        double sum2 =0;
        for (int i =0 ; i< mat.row;i++){
            for (int j=0;j<mat.colum;j++){
                sum1 += mat.pointer[i][j];
            }
        }
        for (int i =0 ;i< other_mat.row;i++){
            for (int j=0;j<other_mat.colum;j++){
                sum2 += other_mat.pointer[i][j];
            }
        }
        if (sum1 < sum2){
            return true;
        }else{
            return false;
        }
    }
    bool operator == (const Matrix &mat,const Matrix &other_mat){
        for (int i =0 ; i< mat.row;i++){
            for (int j=0;j<mat.colum;j++){
                if (mat.pointer[i][j] != other_mat.pointer[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool operator<= (const Matrix &mat,const Matrix &other_mat) {
        return true;
    }
    bool operator>= (const Matrix &mat,const Matrix &other_mat) {
        return true;
    }
    bool operator!= (const Matrix &mat,const  Matrix &other_mat) {
        return true;
    }



    // << >> 
        ostream& operator<< (ostream& out, const Matrix& mat){
            for (int i =0 ; i< mat.row;i++){
                for (int j=0;j<mat.colum;j++){
                    out<<mat.pointer[i][j];
                }
                out<<endl;
            }
        return out;

    }
        istream& operator>> (istream& in, const Matrix& mat){
            for (int i =0 ; i< mat.row;i++){
                for (int j=0;j<mat.colum;j++){
                in>>mat.pointer[i][j];
            }
            // in >>endl;
        }
        return in;


    }



}
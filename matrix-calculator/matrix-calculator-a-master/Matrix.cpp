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
    Matrix::Matrix(vector<double>,int row,int col){
        this -> row;
        this ->colum;
        vector<double> tmp (row*colum,0); // inizalize the matrix to 0
        this ->  tmpMatrix = tmp;
    }

    void chek_inputs(vector<double>,int row,int col){
        return;
    }
    
    // operators:
    //+
    Matrix & operator++ (Matrix &mat){
        return mat;
    }
    //Matrix operator++ (int);
    Matrix operator+ (Matrix &mat ) {
        return mat;
    }
    Matrix operator+ (Matrix &mat ,const Matrix &other_mat){
        return mat;
    }
    Matrix operator+ (Matrix &mat ,double num){
        return mat;
    }
    Matrix operator+ (double num,Matrix &mat){
        return mat;
    }  

    // -
    Matrix & operator -- (Matrix &mat){
        return mat;
    }
    //Matrix operator-- (int);
    Matrix operator- (Matrix &mat ,const Matrix &other_mat){
        return mat;
    }
    Matrix operator- (Matrix &mat){
        return mat;
    }  
    Matrix operator- (Matrix &mat ,double num){
        return mat;
    }
    Matrix operator- (double num,Matrix &mat){
        return mat;
    }  

    //+=-
    Matrix& operator+= (const Matrix &mat,const Matrix &other_mat){
        return;
    }
    Matrix& operator-= (const Matrix &mat,const Matrix &other_mat){
        return;
    }
    Matrix& operator-= (double num ,const Matrix &mat){
        return;
    }


    // *
    Matrix operator* (const Matrix &mat,double skalar){
        return mat;
    }
    Matrix operator* (double skalar, const Matrix &mat){
        return mat;
    }
    Matrix& operator *= (const Matrix &mat,const Matrix &other_mat){
        return ;
    }
    Matrix& operator *= (const double &mat,const Matrix &other_mat){
        return ;
    }

    // < > = 
    bool operator> (const Matrix &mat,const Matrix &other_mat) {
        return true;
    }
    bool operator< (const Matrix &mat,const Matrix &other_mat) {
        return true;
    }
    bool operator == (const Matrix &mat,const Matrix &other_mat){
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
        ostream& operator<< (ostream& stream, const Matrix& mat){
        return stream;

    }
        istream& operator>> (istream& stream, const Matrix& mat){
                    return stream;


    }



}
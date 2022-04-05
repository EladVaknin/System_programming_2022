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
        // this -> row;
        // this ->colum;
        // vector<double> tmp (row*colum,0); // inizalize the matrix to 0
        // this ->  tmpMatrix = tmp;
    }

    void chek_inputs(vector<double>,int row,int col){
        return;
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
/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <map>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
using namespace std;
#pragma once

namespace zich {
     class Matrix{

     private:
     
     vector <double> tmpMatrix;
     int row;
     int colum;

    public: 

        Matrix (vector<double>,int r,int c);  // constructor

        // operators:
        //+
        friend Matrix & operator++ (Matrix &mat);
        // Matrix operator++ (int);
        friend Matrix operator+ (Matrix &mat) ; 
        friend Matrix operator+ (Matrix &mat ,const Matrix &other_mat);
        friend Matrix operator+ (Matrix &mat ,double num);
        friend Matrix operator+ (double num,Matrix &mat);  

        // -
        friend Matrix & operator -- (Matrix &mat);
        // Matrix operator-- (int);
        friend Matrix operator- (Matrix &mat ,const Matrix &other_mat);
        friend Matrix operator- (Matrix &mat) ; 
        friend Matrix operator- (const Matrix &mat ,double num);
        friend Matrix operator- (double num,const Matrix &mat);  
  
        //+=
        friend Matrix& operator+= (const Matrix &mat,const Matrix &other_mat);
        friend Matrix& operator-= (const Matrix &mat,const Matrix &other_mat);
        friend Matrix& operator-= (double num ,const Matrix &mat);


        // *
        friend Matrix operator* (const Matrix &mat,double skalar);
        friend Matrix operator* (double skalar, const Matrix &mat);
        friend Matrix& operator *= (const Matrix &mat,const Matrix &other_mat);
        friend Matrix& operator *= (const Matrix &mat,double skalar);
        friend Matrix& operator *= (double skalar,const Matrix &mat);
        friend Matrix& operator *= (const double &mat,const Matrix &other_mat);

        // < > = 
        friend bool operator> (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator< (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator == (const Matrix &mat,const Matrix &other_mat);
        friend bool operator<= (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator>= (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator!= (const Matrix &mat,const  Matrix &other_mat) ;

        // << >> 
        friend ostream& operator<< (ostream& stream, const Matrix& mat);
        friend istream& operator>> (istream& stream, const Matrix& mat);
        };
}
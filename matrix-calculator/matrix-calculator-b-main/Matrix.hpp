/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
using namespace std;
#pragma once

namespace zich {
     class Matrix{

     private:
     
     vector <vector <double>> tmpMatrix; // [][]
     int row;
     int colum;

    public: 

        Matrix(vector<vector<double>> mat,int rows,int cols);  // constructor
        Matrix (int row , int colum);
        Matrix(const Matrix& other_mat);
        ~Matrix();   // distructors 

        // operators:
        //+
        friend void operator++ (const Matrix &mat);
        // Matrix operator++ (int);
        friend Matrix operator+ (const Matrix &mat) ; 
        friend Matrix operator+ (const Matrix &mat ,const Matrix &other_mat);
        friend Matrix operator+ (const Matrix &mat ,double num);
        friend Matrix operator+ (double num,Matrix &mat);  

        // -
        friend void operator -- (const Matrix &mat);
        // Matrix operator-- (int);
        friend Matrix operator- (const Matrix &mat ,const Matrix &other_mat);
        friend Matrix operator- (const Matrix &mat) ; 
        friend Matrix operator- (const Matrix &mat ,double num);
        friend Matrix operator- (double num,const Matrix &mat);  
  
        //+=/-=
        // friend Matrix& operator+= (const Matrix &mat,const Matrix &other_mat);
        friend void operator+= (const Matrix &mat,double num);
        friend void operator-= (const Matrix &mat,double num);
        // friend Matrix& operator-= (const Matrix &mat,const Matrix &other_mat);
        friend void operator-= (double num ,const Matrix &mat);


        // *
        friend Matrix operator* (const Matrix &mat,double skalar);
        friend Matrix operator* (double skalar, const Matrix &mat);
        friend void operator *= (const Matrix &mat,const Matrix &other_mat);
        friend void operator *= (const Matrix &mat,double skalar);
        friend void operator *= (double skalar,const Matrix &mat); // 
        friend void operator *= (const double &mat,const Matrix &other_mat);

        // < > = 
        friend bool operator> (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator< (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator == (const Matrix &mat,const Matrix &other_mat);
        friend bool operator<= (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator>= (const Matrix &mat,const Matrix &other_mat) ;
        friend bool operator!= (const Matrix &mat,const  Matrix &other_mat) ;

        // << >> 
        friend ostream& operator<< (ostream& out, const Matrix& mat);
        friend istream& operator>> (istream& in, const Matrix& mat);
        };
        
        // Matrix operator*(const double value, Matrix& other);

}
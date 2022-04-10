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

        Matrix(vector<double> mat,int rows,int cols);  // constructor
        Matrix (int row , int colum);
        Matrix(const Matrix& other_mat);   // copy constructor
        ~Matrix();   // distructors 

        // operators:
        //+
        Matrix& operator++ ();  // pre
        Matrix operator ++ (int skalar); // post
        Matrix operator+ (const Matrix &other_mat) const ; 
        Matrix operator+ ();
        Matrix& operator+= (const Matrix &other_mat);
  

        // -
        Matrix& operator -- ();
        Matrix operator -- (int skalar);
        Matrix operator- () const ;
        Matrix operator- (const Matrix &other_mat) ;
        Matrix& operator-= (const Matrix &mat);
 
  
        //+=   /-=

        // *
        Matrix operator* (const Matrix &other_mat)const;
        friend Matrix operator* (double skalar, const Matrix &other_mat);
        Matrix operator* (double skalar)const;
        Matrix operator *= (double skalar);


        // < > = 
        bool operator> (const Matrix &other_mat) const ;
        bool operator< (const Matrix &other_mat) const;
        bool operator == (const Matrix &other_mat) const;
        bool operator<= (const Matrix &other_mat) const;
        bool operator>= (const Matrix &other_mat) const;
        bool operator!= (const  Matrix &other_mat) const;

        // << >> 
        friend ostream& operator<< (ostream& out, const Matrix& mat);
        friend istream& operator>> (istream& in, const Matrix& mat);
        };
        
}
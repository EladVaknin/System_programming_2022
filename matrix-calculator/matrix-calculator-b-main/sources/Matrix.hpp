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
     
     int row;
     int colum;

    public: 
        vector <vector <double>> tmpMatrix; // [][]
        Matrix(const vector<double> &mat,const int rows,const int cols);  // constructor
        Matrix (int row , int cols);
        // Matrix(const Matrix& other_mat);   // copy constructor
        // Matrix();
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
        Matrix operator* (const double skalar)const;
        Matrix operator *= (const double skalar);
        Matrix operator *= (const Matrix &other_mat);
        friend Matrix operator* (const double skalar, const Matrix &other_mat);



        // < > = 
        bool operator> (const Matrix &other_mat) const ;
        bool operator< (const Matrix &other_mat) const;
        bool operator == (const Matrix &other_mat) const;
        friend bool operator==( Matrix &mat,  Matrix &other_mat);    // just for stupid student 2  
        bool operator<= (const Matrix &other_mat) const;
        bool operator>= (const Matrix &other_mat) const;
        bool operator!= (const  Matrix &other_mat) const;

        // << >> 
        friend ostream& operator<< (ostream& out, const Matrix& mat);
        friend istream& operator>> (istream& in, Matrix& mat);
        void check_input_size (Matrix &mat,int in_row,int in_col);
        };
        void check_inputs(vector<double> const&mat, int row,int col);

        
}
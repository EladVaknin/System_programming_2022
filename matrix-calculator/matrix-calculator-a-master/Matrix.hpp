/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-03
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
        Matrix operator+ () const; 
        Matrix & operator++ ();
        Matrix operator++ (int);
        Matrix operator+ (Matrix &other_num);
        Matrix operator- (Matrix &other_num);
        Matrix & operator-- ();
        Matrix operator-- (int);
        Matrix operator- () const;
        Matrix& operator+= (const Matrix &num);
        Matrix& operator-= (const Matrix &num);
        // *
        Matrix operator* (double factor);
        friend Matrix operator* (double factor, const Matrix);
        Matrix& operator *= (const Matrix &num);
        Matrix& operator *= (const double &num);
        // < > = 
        bool operator> (const Matrix &other_num) const;
        bool operator< (const Matrix &other_num) const;
        bool operator== (const Matrix &other_num) const;
        bool operator<= (const Matrix &other_num) const;
        bool operator>= (const Matrix &other_num) const;
        bool operator!= (const  Matrix &other_num) const;
        // << >> 
        friend ostream& operator<< (ostream& stream, const Matrix& num);
        friend istream& operator>> (istream& stream, const Matrix& num);
        };
}
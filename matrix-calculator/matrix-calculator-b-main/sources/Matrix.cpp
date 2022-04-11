/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 
and becuse its my second time that i made the course i base on my last year implem 
https://github.com/EladVaknin/CPP-/tree/master/number%20with%20units 
https://en.wikipedia.org/wiki/Matrix_(mathematics) */


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
        this->row = rows;
        this->colum=cols;
        for (size_t i = 0; i < rows; ++i) {
             tmpMatrix.push_back(ans);
          for (size_t j = 0; j < cols; ++j) {
            unsigned long tmp = ((unsigned long)i*cols) + j;
            tmpMatrix.at(i).push_back(mat.at((unsigned long)tmp));
            }
        }
    }

    Matrix::~Matrix(){

    }

    



    // Matrix::Matrix (int rows,int cols){
    //     vector< vector<double>> tmp; // inizalize the matrix to 0
    //     this ->  tmpMatrix = tmp;
    //     this -> row=rows;
    //     this ->colum = cols;
    // }

    // Matrix::Matrix(const Matrix& other_mat){
    //     vector<vector<double>> mat;
    //     for (int i = 0; i < other_mat.tmpMatrix.size(); i++){
    //         vector<double> row_iterator;
    //         for (int j = 0; j < other_mat.tmpMatrix[0].size(); j++){
    //             row_iterator.push_back(other_mat.tmpMatrix.at(i).at(j));
    //         }
    //         mat.push_back(row_iterator);
    //     }
    //     this->tmpMatrix = mat;
    // }


    void check_inputs(vector<double> const&mat, int row,int col){
        if (mat.size() != (row*col)){
            throw invalid_argument ("invaild input - the size should be match");
        }if(row <=0 || col <=0){
            throw invalid_argument ("invaild input - row or col should be bigger from zero");
        }
    }
  

    // operators:
    //+
    Matrix& Matrix::operator++ (){
        for (size_t i =0 ;i<this->tmpMatrix.size();i++){
            for(size_t j =0;j<this->tmpMatrix[0].size();j++){
                this ->tmpMatrix.at((unsigned long)i).at((unsigned long)j)++;
            }
        }
        return *this;
    }
    Matrix Matrix::operator ++ (int skalar){
        Matrix ans = *this;
        ++(*this);
        return ans;
    }
    Matrix Matrix::operator+ (const Matrix &other_mat)const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                tmp.push_back(this->tmpMatrix.at((unsigned long)i).at((unsigned long)j)+other_mat.tmpMatrix.at((unsigned long)i).at((unsigned long)j));
            }
        }
        Matrix ans (tmp,row,col);
        return ans;
    } 
    Matrix Matrix::operator+ (){
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                tmp.push_back(this->tmpMatrix.at((unsigned long)i).at((unsigned long)j));
            }
        }
        Matrix ans (tmp,row,col);
        return ans;
    }
    //+=
    Matrix& Matrix::operator+= (const Matrix &other_mat){
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
             this->tmpMatrix.at((unsigned long)i).at((unsigned long)j)+= other_mat.tmpMatrix.at((unsigned long)i).at((unsigned long)j);
            }
        }
        // Matrix ans (tmp,row,col);
        return *this;
    }



    // -
    Matrix& Matrix::operator -- (){
        for (size_t i =0 ;i<this->tmpMatrix.size();i++){
            for(size_t j =0;j<this->tmpMatrix[0].size();j++){
                this ->tmpMatrix.at((unsigned long)i).at((unsigned long)j)--;
            }
        }
        return *this;
    }
    Matrix Matrix::operator -- (int skalar){
        Matrix ans = *this;
        --(*this);
        return ans;
    }
    Matrix Matrix::operator- () const {
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                tmp.push_back((-1)*this->tmpMatrix.at((unsigned long)i).at((unsigned long)j));
            }
        }
        Matrix ans (tmp,row,col);
        return ans;


    }
    Matrix Matrix::operator- (const Matrix &other_mat) {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                tmp.push_back(this->tmpMatrix.at((unsigned long)i).at((unsigned long)j)-other_mat.tmpMatrix.at((unsigned long)i).at((unsigned long)j));
            }
        }
        Matrix ans (tmp,row,col);
        return ans;
    }

    //-=
    Matrix& Matrix::operator-= (const Matrix &mat){
        // Matrix ans;
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
             this->tmpMatrix.at((unsigned long)i).at((unsigned long)j)-= mat.tmpMatrix.at((unsigned long)i).at((unsigned long)j);
            }
        }
        // Matrix ans (tmp,row,col);
        return *this;
    }


    // *     conditions - col of matrix a should be eq to row of matrix b 
    Matrix Matrix::operator* (const Matrix &other_mat)const{
        if (this->tmpMatrix[0].size() != other_mat.tmpMatrix.size()){
            throw invalid_argument ("Num of cols in matrix A should be equal to rows of Matrix B");
        }
        // size of Matrix A = n*m , size of Matrix B = m*p , size of Matrix c = n*p.
        int n = this->tmpMatrix[0].size();   
        int p = other_mat.tmpMatrix.size();
        int k = other_mat.tmpMatrix.size();  //represent the num of row in Matrix b.
        vector <double> tmp;
        Matrix ans (tmp,n,p);
        // formula of Matrix multiplication - sigma# Aik*Bkj
        for (size_t i =0 ;i<n;i++){
            for(size_t j =0;j<p;j++){
                for(size_t x =0 ;x<k;k++){
                  ans.tmpMatrix.at(i).at(j) += this->tmpMatrix.at(i).at((unsigned long)k)*other_mat.tmpMatrix.at((unsigned long)k).at((unsigned long)j);
                }
            }
        }       
        return ans;
    }
    Matrix operator* (double skalar, const Matrix &other_mat){
        // Matrix ans;
        vector <double> tmp;
        int row = other_mat.tmpMatrix.size();
        int col = other_mat.tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                if (other_mat.tmpMatrix.at(i).at(j)!=0){
                    tmp.push_back(skalar*other_mat.tmpMatrix.at(i).at(j));
                }else{
                    tmp.push_back(other_mat.tmpMatrix.at(i).at(j));
                }
                
            }
        }
        Matrix ans (tmp,row,col);
        return ans;
          
    }
    Matrix Matrix::operator* (double skalar)const{
        return skalar*(*this);
    }

    Matrix Matrix::operator *= (double skalar){
        vector <double> tmp;
        int row = tmpMatrix.size();
        int col = tmpMatrix[0].size();
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                if(this->tmpMatrix.at(i).at(j) != 0){  // Basic conditions for multiplication
                    this->tmpMatrix.at(i).at(j)*= skalar;
                }
            }
        }
        Matrix ans (tmp,row,col);
        return ans;
    }
    Matrix& Matrix::operator *= (const Matrix &other_mat){
        *this = *this*other_mat;
        return *this;
    }



    // < > = 
    bool Matrix::operator> (const Matrix &other_mat) const{
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        double sum1 = 0;
        double sum2 = 0 ;
        for (size_t i =0 ;i<this->tmpMatrix.size();i++){
            for(size_t j =0;j<this->tmpMatrix[0].size();j++){
                sum1 += this ->tmpMatrix.at(i).at(j);
                sum2 += other_mat.tmpMatrix.at(i).at(j);
            }
        }
        // if (sum1 > sum2){
        //     return true;
        // }else{
        //     return false;
        // }
        return sum1>sum2;

    }

    bool Matrix::operator< (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        double sum1 = 0;
        double sum2 = 0 ;
        for (size_t i =0 ;i<this->tmpMatrix.size();i++){
            for(size_t j =0;j<this->tmpMatrix[0].size();j++){
                sum1 += this ->tmpMatrix.at(i).at(j);
                sum2 += other_mat.tmpMatrix.at(i).at(j);
            }
        }
        // if (sum1 < sum2){
        //     return true;
        // }else{
        //     return false;
        // }
        return sum1<sum2;
    }
    bool Matrix::operator == (const Matrix &other_mat) const {
        if (this->tmpMatrix.size()!=other_mat.tmpMatrix.size()){
            throw invalid_argument ("invaild input - the size should be match");
        }
        for (size_t i =0 ;i<this->tmpMatrix.size();i++){
            for(size_t j =0;j<this->tmpMatrix[0].size();j++){
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
        for (size_t i =0 ; i< mat.tmpMatrix.size();i++){
            for (size_t j=0;j<mat.tmpMatrix[0].size();j++){
                out<<mat.tmpMatrix.at(i).at(j);
            }
            out<<endl;
        }
    return out;

    }
    istream& operator>> (istream& in,Matrix& mat){
        for (size_t i =0 ; i< mat.tmpMatrix.size();i++){
            for (size_t j=0;j<mat.tmpMatrix[0].size();j++){
            in >> mat.tmpMatrix.at(i).at(j);
              }
            }
          return in;
    }

// istream& operator>>(istream & in, Matrix &a){
//         cout<<"Input data"<<endl;
//         for(int i = 0; i<a.row; i++){
//             for (int j = 0; j<a.column; j++){
//                 in >> a.matrix[i][j];
//             }
//         }
//         return in;
//     }


}
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
    Matrix::Matrix(const vector<double> &mat,const int rows,const int cols){
        check_inputs (mat,rows,cols);
        this->row = rows;
        this->colum=cols;
        this->tmpMatrix.resize((unsigned int)rows);
        for ( unsigned int i = 0; i < rows; i++) {
          for (unsigned int j = 0; j < cols; j++) {
            // long tmp = i*cols + j;
            this-> tmpMatrix.at((i)).push_back(mat.at((i*(unsigned int)cols) + j));
            }
        }
    }

    Matrix::~Matrix(){

    }

    Matrix::Matrix (int rows,int cols){
        this -> row=rows;
        this ->colum = cols;
        this->tmpMatrix.resize((unsigned int)rows,vector<double>((unsigned int)cols));
    }

    // Matrix::Matrix(const Matrix& other_mat){
    //     this->row=other_mat.row;
    //     this->colum=other_mat.colum;
    //     this->tmpMatrix.resize((unsigned int)other_mat.row);
    //     for (size_t i = 0; i < other_mat.row; i++){
    //         for (size_t j = 0; j < other_mat.colum; j++){
    //             this->tmpMatrix.at(i).push_back(other_mat.tmpMatrix.at(i).at(j));
    //         }
    //     }
    // }
    // Matrix::Matrix(){
    //     this->row=0;
    //     this->colum=0;
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
        // cout<<"1111111"<<endl;
         for (size_t i =0 ;i<row;i++){
            for(size_t j =0;j<col;j++){
                // cout<<"222222"<<endl;
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
        if (this->tmpMatrix[0].size()!= other_mat.tmpMatrix.size() ){
            throw invalid_argument ("Num of cols in matrix A should be equal to rows of Matrix B");
        }
        // cout<<"11111"<<endl;
        // size of Matrix A = n*m , size of Matrix B = m*p , size of Matrix c = n*p.
        int n = this->tmpMatrix.size();      // row of matrix A
        int p = other_mat.tmpMatrix[0].size();  // col of Matrix B
        int k = other_mat.tmpMatrix[0].size(); 
        // vector <double> tmp;
        double tmpSum=0;
        Matrix ans (n,p);
        // cout<<"222222"<<endl;
        // formula of Matrix multiplication - sigma# Aik*Bkj
        for (size_t i =0 ;i<n;i++){
            for(size_t j =0;j<p;j++){
                // cout<<"333333"<<endl;
                tmpSum =0;
                for(size_t x =0 ;x<k;x++){
                //   cout<<"444444"<<endl;
                  tmpSum += this->tmpMatrix.at(i).at(x)*other_mat.tmpMatrix.at(x).at(j);
                }
                ans.tmpMatrix.at((unsigned long)i).at((unsigned long)j) = tmpSum;
                        // cout<<"5555555"<<endl;

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
        if (this->tmpMatrix.size() != other_mat.tmpMatrix.size() || this->tmpMatrix[0].size() != other_mat.tmpMatrix[0].size() ){
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
        if (this->tmpMatrix.size() != other_mat.tmpMatrix.size() || this->tmpMatrix[0].size() != other_mat.tmpMatrix[0].size() ){
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
        int row = mat.tmpMatrix.size();
        int col = mat.tmpMatrix[0].size();
        for (size_t i =0 ; i< row;i++){
            out<<"[";
            for (size_t j=0;j<col;j++){
                if (j == col-1 ){
                out<<mat.tmpMatrix.at(i).at(j);
                }else{
                out<<mat.tmpMatrix.at(i).at(j)<<" ";
                }
            }
            if(i==row-1){
                out<<"]";
            }else{
                out<<"]\n"; 
            }
        }
        return out;
    }

    
    void check_input_size (Matrix &mat,unsigned long in_row,unsigned long in_col){
        int row = mat.tmpMatrix.size();
        int col = mat.tmpMatrix[0].size();
        if (row <= in_row){
            throw invalid_argument("not good size");
        }
        if (col <= in_col){
            throw invalid_argument("not good size");
        }
         
    }
    istream& operator>> (istream& in,Matrix& mat){
        unsigned long in_row = 0;
        unsigned long in_col=0;
        string tmp;
        double holder=0;
        in.fill(' ');
        in.get();
        for (char i =0 ; in.get(i);){
            if (i=='\n'){
                break;
            }
            if(i=='['){   // start of row
               in_col =0;
               in_row++;
               check_input_size(mat,in_row,in_col);
            }
            if(i == ' '||i ==']'){   // start of colum
               check_input_size(mat,in_row,in_col);
               holder = stod(tmp);  // convert string to double;
               mat.tmpMatrix.at(in_row).at(in_col)= holder;
               cout<<in_row<<","<<in_col<<","<<holder <<endl;
               in_col++;
               tmp="";
            }
            if (isdigit(i)!=0){   // check if the first character in str is a digit
                tmp +=i;
            }
        }
        return in;
    }

    

}
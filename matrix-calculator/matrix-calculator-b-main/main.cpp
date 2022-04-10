#include <iostream>
#include <math.h>
#include <exception>
#include <algorithm>
#include<vector>
#include "Matrix.hpp"


using namespace std;
using namespace zich;

    int main() {
        int row =2 ;
        int col =2;
        string result;
        vector <double> tmpMatrix = {2,2,2,2};
        // Matrix::Matrix mat (tmpMatrix,row,col);
        for (int i =0 ; i<row; i++){
                for (int j=0 ;j <col ;j++){
                    // cout<< result <<tmpMatrix[i][j];
                    // result += mat [i][j];
                    cout<<result<<endl;
                }
                result += '\n';
                cout<<result<<endl;
            }
    }

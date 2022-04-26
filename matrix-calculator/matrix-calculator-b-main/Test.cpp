/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
/* To see the whole process and the committees -
https://github.com/EladVaknin/System_programming_2022 */

#include "sources/Matrix.hpp"
#include "doctest.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>


using namespace zich;
using namespace std;

TEST_CASE("bool"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
     
    CHECK_THROWS(bool ans = tmp == tmp2);
    CHECK_THROWS(bool ans =tmp == tmp3);
    CHECK_THROWS(bool ans = tmp2 == tmp3);
    CHECK_THROWS(bool ans = tmp == tmp4);
    CHECK_THROWS(bool ans = tmp == tmp);
    CHECK_THROWS(bool ans = tmp <= tmp2);
    CHECK_THROWS(bool ans = tmp <= tmp3);
    CHECK_THROWS(bool ans = tmp2 <= tmp2);
    CHECK_THROWS(bool ans = tmp >= tmp2);
    CHECK_THROWS(bool ans = tmp >= tmp3);
    CHECK_THROWS(bool ans = tmp2 >= tmp2);
    CHECK_THROWS(bool ans = tmp < tmp2);
    CHECK_THROWS(bool ans = tmp < tmp3);
    CHECK_THROWS(bool ans = tmp2 < tmp2);
    CHECK_THROWS(bool ans = tmp > tmp2);
    CHECK_THROWS(bool ans = tmp > tmp3);
    CHECK_THROWS(bool ans = tmp2 > tmp2);
    CHECK_THROWS(bool ans = tmp != tmp2);
    CHECK_THROWS(bool ans = tmp != tmp3);
    CHECK_THROWS(bool ans = tmp2 != tmp2);
    CHECK_THROWS(bool ans = tmp != tmp4);
}

TEST_CASE("Plus and Minus"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
    double skalar = 8;
    CHECK_THROWS(tmp + tmp2);
    CHECK_THROWS(tmp + tmp3);
    CHECK_THROWS(tmp2 + tmp3);
    CHECK_THROWS(tmp + tmp4);
    CHECK_THROWS(tmp - tmp2);
    CHECK_THROWS(tmp  -tmp3);
    CHECK_THROWS(tmp2 - tmp3);
    CHECK_THROWS(tmp - tmp4);
    CHECK(tmp += skalar);
    CHECK(tmp2 += skalar);
    CHECK(tmp3 += skalar);
    CHECK(tmp -= skalar);
    CHECK(tmp2 -= skalar);
    CHECK(tmp3 -= skalar);

}

TEST_CASE("Multiplication"){
    Matrix tmp ({0,0,0,0},2,2);
    Matrix tmp2 ({1,1,1,1},2,2);
    Matrix tmp3 ({2,2,2,2},2,2);
    Matrix tmp4 ({0,0,0,0},2,2);
    double skalar = 4;
    CHECK_THROWS(tmp * skalar);
    CHECK_THROWS(tmp2 * skalar);
    CHECK_THROWS(tmp3 * skalar);
    CHECK_THROWS(skalar * tmp);
    CHECK_THROWS(skalar * tmp2);
    CHECK_THROWS(skalar * tmp3);
    CHECK_THROWS(tmp *= skalar);
    CHECK_THROWS(tmp2 *= skalar);
    CHECK_THROWS(tmp3 *= skalar);
    CHECK_THROWS(tmp2 * tmp);
    CHECK_THROWS(tmp3 * tmp2);
    CHECK_THROWS(tmp * tmp3);
    
}



TEST_CASE("Random checks"){
 for (double i = 1; i < 20; i++)
    {
        srand(time(0));
        int random = rand() % 100;    // 0-99
        int skalar = rand() % 100;
        vector<double> vec1 = {i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random,i*random};
        vector<double> arr1 = {i,i,i,i,i,i,i,i,i};//3x3
        vector<double> arr = {pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2)};//3x3
        Matrix tmp(arr1, 3, 3);
        Matrix tmp2(arr, 3, 3);
        Matrix tmp3(vec1, 3, 3);
        // all the checks
        CHECK(((tmp*tmp) != tmp2));
        CHECK (tmp + tmp2);
        CHECK (tmp - tmp2);
        CHECK (tmp + tmp3);
        CHECK (tmp - tmp3);
        CHECK (tmp3 + tmp2);
        CHECK (tmp3 - tmp2);
        CHECK (tmp += skalar);
        CHECK (tmp2 += skalar);
        CHECK (tmp3 += skalar);
        CHECK (tmp -= skalar);
        CHECK (tmp2 -= skalar);
        CHECK (tmp3 -= skalar);
        CHECK (tmp *= skalar);
        CHECK (tmp2 *= skalar);
        CHECK (tmp3 *= skalar);
        CHECK (tmp2 * tmp3);
        CHECK (tmp2 * tmp);
        CHECK (tmp3 * tmp);
        CHECK_THROWS(bool ans = tmp == tmp2);
        CHECK_THROWS(bool ans = tmp == tmp3);
        CHECK_THROWS(bool ans = tmp2 == tmp3);
        CHECK_THROWS(bool ans = tmp == tmp);
        CHECK_THROWS(bool ans = tmp <= tmp2);
        CHECK_THROWS(bool ans = tmp <= tmp3);
        CHECK_THROWS(bool ans = tmp3 <= tmp2);
        CHECK_THROWS(bool ans = tmp >= tmp2);
        CHECK_THROWS(bool ans = tmp >= tmp3);
        CHECK_THROWS(bool ans = tmp3 >= tmp2);
        CHECK_THROWS(bool ans = tmp != tmp2);
        CHECK_THROWS(bool ans = tmp != tmp3);
        CHECK_THROWS(bool ans = tmp3 != tmp2);
    }
    

}
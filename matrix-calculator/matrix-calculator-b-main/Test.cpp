// /**
//  * AUTHORS: <Elad Vaknin>
//  * 
//  * Date: 2022-04
//  */
// /* To see the whole process and the committees -
// https://github.com/EladVaknin/System_programming_2022 */

// #include "Matrix.hpp"
// #include "doctest.h"
// #include <vector>
// #include <fstream>
// #include <iostream>

// using namespace zich;
// using namespace std;

// TEST_CASE("bool"){
//     Matrix tmp ({0,0,0,0},2,2);
//     Matrix tmp2 ({1,1,1,1},2,2);
//     Matrix tmp3 ({2,2,2,2},2,2);
//     Matrix tmp4 ({0,0,0,0},2,2);
     
//     CHECK_THROWS(bool ans = tmp == tmp2);
//     CHECK_THROWS(bool ans =tmp == tmp3);
//     CHECK_THROWS(bool ans = tmp2 == tmp3);
//     CHECK_THROWS(bool ans = tmp == tmp4);
//     CHECK_THROWS(bool ans = tmp == tmp);
//     CHECK_THROWS(bool ans = tmp <= tmp2);
//     CHECK_THROWS(bool ans = tmp <= tmp3);
//     CHECK_THROWS(bool ans = tmp2 <= tmp2);
//     CHECK_THROWS(bool ans = tmp >= tmp2);
//     CHECK_THROWS(bool ans = tmp >= tmp3);
//     CHECK_THROWS(bool ans = tmp2 >= tmp2);
//     CHECK_THROWS(bool ans = tmp < tmp2);
//     CHECK_THROWS(bool ans = tmp < tmp3);
//     CHECK_THROWS(bool ans = tmp2 < tmp2);
//     CHECK_THROWS(bool ans = tmp > tmp2);
//     CHECK_THROWS(bool ans = tmp > tmp3);
//     CHECK_THROWS(bool ans = tmp2 > tmp2);
//     CHECK_THROWS(bool ans = tmp != tmp2);
//     CHECK_THROWS(bool ans = tmp != tmp3);
//     CHECK_THROWS(bool ans = tmp2 != tmp2);
//     CHECK_THROWS(bool ans = tmp != tmp4);
// }

// TEST_CASE("Plus and Minus"){
//     Matrix tmp ({0,0,0,0},2,2);
//     Matrix tmp2 ({1,1,1,1},2,2);
//     Matrix tmp3 ({2,2,2,2},2,2);
//     Matrix tmp4 ({0,0,0,0},2,2);
//     double skalar = 8;
//     CHECK_THROWS(tmp + tmp2);
//     CHECK_THROWS(tmp + tmp3);
//     CHECK_THROWS(tmp2 + tmp3);
//     CHECK_THROWS(tmp + tmp4);
//     CHECK_THROWS(tmp - tmp2);
//     CHECK_THROWS(tmp  -tmp3);
//     CHECK_THROWS(tmp2 - tmp3);
//     CHECK_THROWS(tmp - tmp4);
//     CHECK_THROWS(tmp + skalar);
//     CHECK_THROWS(tmp2 + skalar);
//     CHECK_THROWS(tmp3 + skalar);
//     CHECK_THROWS(skalar + tmp);
//     CHECK_THROWS(skalar + tmp2);
//     CHECK_THROWS(skalar + tmp3);
//     CHECK_THROWS(tmp - skalar);
//     CHECK_THROWS(tmp2 - skalar);
//     CHECK_THROWS(tmp3 - skalar);
//     CHECK_THROWS(skalar - tmp);
//     CHECK_THROWS(skalar - tmp2);
//     CHECK_THROWS(skalar - tmp3);
//     CHECK_THROWS(tmp += skalar);
//     CHECK_THROWS(tmp2 += skalar);
//     CHECK_THROWS(tmp3 += skalar);
//     CHECK_THROWS(tmp -= skalar);
//     CHECK_THROWS(tmp2 -= skalar);
//     CHECK_THROWS(tmp3 -= skalar);

// }

// TEST_CASE("Multiplication"){
//     Matrix tmp ({0,0,0,0},2,2);
//     Matrix tmp2 ({1,1,1,1},2,2);
//     Matrix tmp3 ({2,2,2,2},2,2);
//     Matrix tmp4 ({0,0,0,0},2,2);
//     double skalar = 4;
//     CHECK_THROWS(tmp * skalar);
//     CHECK_THROWS(tmp2 * skalar);
//     CHECK_THROWS(tmp3 * skalar);
//     CHECK_THROWS(skalar * tmp);
//     CHECK_THROWS(skalar * tmp2);
//     CHECK_THROWS(skalar * tmp3);
//     CHECK_THROWS(tmp *= skalar);
//     CHECK_THROWS(tmp2 *= skalar);
//     CHECK_THROWS(tmp3 *= skalar);
//     // CHECK_THROWS(skalar *= tmp);
//     // CHECK_THROWS(skalar *= tmp2);
//     // CHECK_THROWS(skalar *= tmp3);
    
// }
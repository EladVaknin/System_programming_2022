/**

 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2021-02
 */
#include <string>
#include <algorithm>
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
// input symbols from the web.
	// char symbols [11] = {'@', '-' ,'$', '%','#','+',':)','!','^','&','*'};
	// string symbols2 [11] = {"@", "-" ,"$", "%","#","+",":)","!","^","&","*"};


TEST_CASE("Good input") {
	// input symbols from the web.
	char symbols [11] = {'@', '-' ,'$', '%','#','+',':','!','^','&','*'};
	string symbols2 [11] = {"@", "-" ,"$", "%","#","+",":)","!","^","&","*"};


	//randoms numbers 0- 100
	int random1 ,random2;
	random1 = rand() % 100;
	random2 = rand() % 100;
	// random number 0-9;
	int random3 = rand () % 10;
	int random4 = rand () % 10;

    // regular cases.
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(3,5,'-','#'))==nospaces("---\n"
												"-#-\n"
												"-#-\n"
												"-#-\n"
												"---"	));	

	CHECK(nospaces(mat(7,3,'$','@'))==nospaces("$$$$$$$\n"
												"$@@@@@$\n"
												"$$$$$$$"));

	CHECK(nospaces(mat(7,5,'!','-'))==nospaces("!!!!!!!\n"
												"$!-----!$\n"
												"$!-!!!-!$\n"
												"$!-----!$\n"
												"!!!!!!!"));

	CHECK(nospaces(mat(5,3,'%','*'))==nospaces("%%%\n"
												"%*%\n"
												"%%%"));
												

	
	
	
     //case that int1 == int2 
	CHECK(nospaces(mat(5,5,'#','#'))==nospaces("######\n"
												"######\n"
												"######\n"
												"######\n"
												"######"));

	CHECK(nospaces(mat(7,7,'$','$'))==nospaces("&&&&&&&\n"
												"&&&&&&&\n"
												"&&&&&&&\n"
												"&&&&&&&\n"
												"&&&&&&&\n"
												"&&&&&&&\n"
												"&&&&&&&"));

	CHECK(nospaces(mat(3,3,'!','!'))==nospaces("!!!\n"
												"!!!\n"
												"!!!"));																					



	// in case that we have only 1 char as a input.

	CHECK(nospaces(mat(1,1,'$','@'))==nospaces("$"));
	CHECK(nospaces(mat(1,1,'#','-'))==nospaces("#"));
	CHECK(nospaces(mat(1,1,'%','@'))==nospaces("%"));
	CHECK(nospaces(mat(1,1,'!','!'))==nospaces("!"));
	CHECK(nospaces(mat(1,1,'*','*'))==nospaces("*"));




	
									
}

TEST_CASE("Bad input") {
	char symbols [11] = {'@', '-' ,'$', '%','#','+',':','!','^','&','*'};
	int random1 ,random2;
	srand(0);
	random1 = rand() % 100;
	random2 = rand() % 100;
	int random3 = rand () % 10;
	int random4 = rand () % 10;

    // if its even number
	CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(8, 2, '$', '!'));
	CHECK_THROWS(mat(6, 4, '-', '#'));
	CHECK_THROWS(mat(4, 10, '#', '%'));
	CHECK_THROWS(mat(12, 6, '!', '!'));
	CHECK_THROWS(mat(4, 4, '%', '#'));
	CHECK_THROWS(mat(2, 8, '@', '^'));
	CHECK_THROWS(mat(8, 6, '*', '*'));

    if (random1%2 == 0 || random2%2 == 0){
            CHECK_THROWS(mat(random1, random2, symbols[random3], symbols[random4]));
            CHECK_THROWS(mat(random1, random2, symbols[random4], symbols[random3]));
			CHECK_THROWS(mat(random1, random2, symbols[random4], symbols[random4]));
			CHECK_THROWS(mat(random1, random2, symbols[random3], symbols[random3]));
    }
    // didnt recevie any values.
    if (random1 == 0 && random2 == 0){
            CHECK_THROWS(mat(random1, random2, symbols[random3], symbols[random4]));
            CHECK_THROWS(mat(random1, random2, symbols[random4], symbols[random3]));
			CHECK_THROWS(mat(random1, random2, symbols[random4], symbols[random4]));
			CHECK_THROWS(mat(random1, random2, symbols[random3], symbols[random3]));

			

    }
	


    
}



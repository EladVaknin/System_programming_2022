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
#include "Game.hpp"
#include "Game.cpp"
using namespace std;
// using namespace coup;
#pragma once

namespace cuop{

    class Player{

    private:
    
    public:
    Player();  // empty constructor;

    //actions  
    void income();
    void foreign_aid ();
    void coup();
    /////
    string role();
    int coins ();
    };


}
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
#include "Game.cpp"
#include "Player.hpp"
using namespace std;
// using namespace coup;
#pragma once

namespace cuop{
    class Ambassdor:public Player{

    private:
    // coup::Game &game;
    string name;
    
    public:
    Ambassdor(){}  // empty constructor;
    Ambassdor(Game &_game ,const string name){}

    //Actions
    void move_coin();
    void block_steal();




    };

}
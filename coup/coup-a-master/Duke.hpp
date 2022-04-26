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
#include "Player.hpp"
using namespace std;
// using namespace coup;
#pragma once

namespace cuop{
    class Duke:public Player{

    private:
    
    public:
    Duke();
    Duke(Game &_game ,const string name);

    //Actions
    void take_taxes();
    void block_foreign_aid();
    
    };


}
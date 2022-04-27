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

namespace coup{
    class Ambassdor:public Player{

    // private:
    // // coup::Game &game;
    // string name;
    
    public:
    // Ambassdor(){}  // empty constructor;
    Ambassdor(Game &_game ,const string &name) : Player(_game,name){
        this->name =name;
        _game.add_player(this);

    }
    //Actions
    void transfer(Player& from ,Player&to);
    void block(Player &block_capitan);   //block steal from the capitan
    };

}
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


namespace coup{
    class Capitan:public Player{

    // private:
    
    public:
    // Capitan();  // empty constructor;
    Capitan(Game &_game ,const string &name) : Player(_game,name){
        this->name =name;
        _game.add_player(this);

    }

    //Actions
    void steal(Player &player);
    void block(Player &player);



    };


}
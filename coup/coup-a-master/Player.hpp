/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
#include "Game.hpp"
#include "Game.cpp"
using namespace std;
// using namespace coup;
#pragma once

namespace cuop{

    class Player{
    private:
    int counter_coin;
    
    public:
    string name;
    Player();  // empty constructor;
    
    Player(Game &_game ,const string &name) {
         this->name = name;
        _game.add_player();
    }

    //actions  
    void income();
    void foreign_aid ();
    void coup(Player &player);
    /////
    string role();
    int coins ();
    };


}
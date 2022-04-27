/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
#include "Game.hpp"
using namespace std;
#pragma once

namespace coup{
    class Game;

    class Player{

        // private:
        
        public:
        //fields
        string name;
        int counter_coin;
        //cons
        Player(Game &_game ,const string &name) {
            this->name = name;
            _game.add_player(this);
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
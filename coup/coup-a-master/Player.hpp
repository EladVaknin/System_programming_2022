/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include<string>
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
        string role_player;
        int counter_coin;
        //cons
        Player(Game &_game ,const string &name) { //:Game(_game)
            this->name = name;
            _game.add_player(this);
        }
        ~Player(){};

        //actions  
        void income();
        void foreign_aid ();
        void coup(Player &player);
        /////
        string role();
        int coins ();


        };
}
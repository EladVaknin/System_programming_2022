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

        private:
        Game* _game;
        
        public: 
        //fields
        string name;
        string role_player;
        int counter_coin;

        //cons
        Player(Game &_game ,const string &name) { 
            this->name = name;
            this->_game=&_game;
            _game.add_player(this);
            _game.in_the_game.push_back(this);         //add the player to vector players in the game 
            _game.listPlayer.push_back(this->name);     //add the player name to vector players list for players function in game.cpp
        }
        ~Player(){};

        //actions  
        void income();
        void foreign_aid ();
        void coup(Player &player);

        ///// 
        string role();
        int coins ();
        void check_turn(Game &_game);


        };
}
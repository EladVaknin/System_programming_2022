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
        
        public: 
        //fields
        Game* _game;
        string name;
        string role_player;
        int counter_coin;
        Player* just_for_block;

        //cons
        Player(Game &_game ,const string &name) { 
            this->name = name;
            this->_game=&_game;
            _game.add_player(this);           //check if we have place to this player in the game.
            _game.in_the_game.push_back(this);         //add the player to vector players in the game 
            _game.listPlayer.push_back(name);     //add the player name to vector players list for players function in game.cpp
        }
        ~Player(){};

        //actions  
        void income();
        void foreign_aid ();
        virtual void coup(Player &player);

        ///// 
        string role();
        int coins ();
        void check_turn(Game &_game);


        };
}
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
#include "Player.hpp"
#include "Game.hpp"

using namespace std;
// using namespace coup;

namespace coup{

    unsigned int Max_coins =10;
    unsigned int Min_players =2;
    unsigned int Max_players =6;
    unsigned int cost_of_coup =7;
    unsigned int add_coins = 2;

    //checks
    void check_turn(){       
        // if(_game->turn() != this->name) {
        // throw invalid_argument ("You cant play - thats not your turn");
        // }
    }



    //actions  
    void Player::income(){
        if(_game->turn() != this->name ||_game->listPlayer.size()<2) {
            throw invalid_argument ("You cant play - thats not your turn");
        }
        this->counter_coin++;
        _game->listTurns.at(_game->counter_turns) ="income";
        _game->counter_turns+=1;
    }

    void Player::foreign_aid (){
        if(_game->turn() != this->name||_game->listPlayer.size()<2) {
            throw invalid_argument ("You cant play - thats not your turn");
        }
        this->counter_coin+=add_coins;
        _game->listTurns.at(_game->counter_turns) ="foreign_aid";
        _game->counter_turns+=1;


    }
    void Player::coup(Player &player){
        if(_game->turn() != this->name) {
            throw invalid_argument ("You cant play - thats not your turn");
        }
        if (this->counter_coin<cost_of_coup){
            throw invalid_argument ("You cant play - you dont have enough coins");
        }
        this->counter_coin -= cost_of_coup;
        // _game->in_the_game.pop_back();      // need to think how to remove  (need to use in player)
        // _game->listPlayer.erase(player.name);   // need to think how to remove the name


        vector<string>::iterator new_end;
        // new_end = remove(_game->listPlayer.begin(),_game->listPlayer.end(),player.name);
        // _game->listPlayer.erase(std::remove(_game->listPlayer.begin(),_game->listPlayer.end(),player.name));         //https://iq.opengenus.org/ways-to-remove-elements-from-vector-cpp/
        _game->listTurns.at(_game->counter_turns) ="coup";
        _game->counter_turns+=1;
    }



    string Player::role(){             //return the role of the player
        return this->role_player;
    }

    int Player::coins (){
        return this->counter_coin;        //return the number of the coins
    }

}
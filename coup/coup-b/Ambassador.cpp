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
#include "Ambassador.hpp"
// #include "Game.hpp"
using namespace std;

namespace coup{

    //Actions
    void Ambassador::transfer(Player& from ,Player&to){
        if(_game->turn() != this->name){
            throw invalid_argument("Thats not your turn");
        }
        if (from.counter_coin<1){           // need to add checks if the player in the game
            throw invalid_argument ("you cant do the transfer - don't have enough coins");
        }
        from.counter_coin --;
        to.counter_coin ++;
        _game->listTurns.at(_game->counter_turns) ="transfer";
        _game->counter_turns+=1;

    }
    void Ambassador::block(Player &block_capitan){
        if(block_capitan.role_player != "Captain"){
            throw invalid_argument ("you cant block this player");
        }
        block_capitan.counter_coin-=2;
        //need to add 2 coins to the player fthat the coins stoled

    }
    

}
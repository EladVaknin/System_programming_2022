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
// #include "Game.hpp"
#include "Duke.hpp"
using namespace std;
// using namespace coup;

namespace coup{

    void Duke::tax(){
        if(_game->turn()!=this->name){
            throw invalid_argument ("Thats not your turn");
        }
        this->counter_coin = this->counter_coin+3;
        _game->listTurns.at(_game->counter_turns) ="tax";
        _game->counter_turns+=1;
    }

    void Duke::block(Player &player){
        if (_game->listTurns.at(0) != "foreign_aid"){
            throw invalid_argument ("You cant do this block");
        }
        if(player.counter_coin<2){
            throw invalid_argument ("You cant do this block");
        }
        player.counter_coin -=2;
        _game->listTurns.at(_game->counter_turns) ="block";




    }


}
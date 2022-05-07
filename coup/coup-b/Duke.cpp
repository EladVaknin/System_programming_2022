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

    }


}
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
#include "Captain.hpp"
using namespace std;
// using namespace coup;

namespace coup{

    void Captain::steal(Player &player){
        if(player.counter_coin<1){
           throw invalid_argument ("you can't still from this player - don't have enough coins");
        }
        if (player.counter_coin == 1 ){
            player.counter_coin --;
            this->counter_coin ++;
            _game->listTurns.at(_game->counter_turns) ="steal";
            _game->counter_turns+=1;
        }else{
            player.counter_coin -= 2 ;
            this->counter_coin += 2;
            _game->listTurns.at(_game->counter_turns) ="steal";
            _game->counter_turns+=1;
        }
    }
    void Captain::block(Player &player){
        if(player.role_player != "Captain"){
            throw invalid_argument ("you can block only capitans");
        }
        if(_game->listTurns.at(0)=="steal" ){
            throw invalid_argument ("you cant block this now");
        }
        player.counter_coin-=2;
        Captain &captain = dynamic_cast<Captain&>(player);
        captain.just_for_block->counter_coin += 2;
        _game->listTurns.at(_game->counter_turns) ="block";
        


    }

}
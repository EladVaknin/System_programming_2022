/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <iostream>
#include <stdexcept>
// #include "Game.hpp"
#include "Assassin.hpp"
using namespace std;
// using namespace coup;


namespace coup{
    //Actions
    unsigned int assain_cost_of_coup = 3;
    void Assassin::coup(Player &player){
         if(_game->turn() != this->name) {
            throw invalid_argument ("You cant play - thats not your turn");
        }
        if (this->counter_coin<assain_cost_of_coup){
            throw invalid_argument ("You cant play - you dont have enough coins");
        }
        this->counter_coin -= assain_cost_of_coup;
        // neeed to implem the coup




        _game->listTurns.at(_game->counter_turns) ="coup";



    }

}
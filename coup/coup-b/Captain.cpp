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
        }else{
            player.counter_coin -= 2 ;
            this->counter_coin += 2;
        }
    }
    void Captain::block(Player &player){

    }

}
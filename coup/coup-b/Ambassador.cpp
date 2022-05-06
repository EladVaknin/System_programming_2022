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
        if (from.counter_coin<1 || to.counter_coin<1){           // need to add checks if the player in the game
            throw invalid_argument ("you cant do the transfer - don't have enough coins");
        }
        from.counter_coin --;
        to.counter_coin ++;

    }
    void Ambassador::block(Player &block_capitan){

    }
    

}
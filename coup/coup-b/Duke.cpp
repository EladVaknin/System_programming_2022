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
        this->counter_coin = this->counter_coin+3;
    }
    
    void Duke::block(Player &player){

    }


}
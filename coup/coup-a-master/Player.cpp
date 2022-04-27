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


    //actions  
    void Player::income(){
        this->counter_coin++;
    }

    void Player::foreign_aid (){

    }
    void Player::coup(Player &player){

    }
    string Player::role(){
        string tmp="";
        return tmp;

    }
    int Player::coins (){
        int x=0;
        return x;

    }

}
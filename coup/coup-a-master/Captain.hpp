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
#include "Player.hpp"
using namespace std;
// using namespace coup;


namespace coup{
    class Captain:public Player{

    // private:
    
    public: 
    // Capitan();  // empty constructor;
    Captain(Game &_game ,const string &name) :Player(_game,name){
        this->name =name;
        this->counter_coin=0;
        this->role_player = "Captain";
        _game.add_player(this);

    }

    //Actions
    void steal(Player &player);
    void block(Player &player);



    };


}
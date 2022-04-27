/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <iostream>
#include <stdexcept>
// #include "Game.hpp"
#include "Player.hpp"
using namespace std;
// using namespace coup;

namespace coup{
    class Assassin:public Player{

    // private:
    
    public: 
    // Assassian();  // empty constructor;
    Assassin(Game &_game ,const string &name) :Player(_game,name){
        this->name =name;
        this->counter_coin=0;
        this->role_player = "Assassin";
        _game.add_player(this);

    }

    //Actions
    void coup(Player &player);



    };


}
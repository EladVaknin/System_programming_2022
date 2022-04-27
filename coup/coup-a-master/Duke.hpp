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
// #include "Game.hpp"
using namespace std;
// using namespace coup;

namespace coup{ 
    class Duke:public Player{     

    // private:
    
    public:            
    // Duke();
    Duke(Game &_game ,const string &name) :Player(_game,name){
        this->name =name;
        this->counter_coin=0;
        this->role_player = "Duke";
        _game.add_player(this);

    }

    //Actions
    void tax();
    void block(Player &player);

    };


}
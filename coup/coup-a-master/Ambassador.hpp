/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <iostream>
#include <stdexcept>
#include "Player.hpp"
// #include "Game.hpp"
using namespace std;
// using namespace coup;

namespace coup{
    class Ambassador:public Player{
        // private:
        public:      
        // Ambassdor(){}  // empty constructor;
        Ambassador(Game &_game ,const string &name) :Player(_game,name){
            this->name =name;
            this->counter_coin=0;
            this->role_player = "Ambassador";
            _game.add_player(this);

        }
        //Actions
        void transfer(Player& from ,Player&to);
        void block(Player &block_capitan);   //block steal from the capitan
        };

}
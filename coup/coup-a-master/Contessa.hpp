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
    class Contessa:public Player{

    private:
    
    public: 
    // Contessa();  // empty constructor;
    Contessa(Game &_game ,const string &name) : Player(_game,name){
        this->name =name;
        this->counter_coin=0;
        this->role_player = "Contessa";
        _game.add_player(this);

    }

    //Actions

    void block(Player &assassian);  //block_assassination



    };


}
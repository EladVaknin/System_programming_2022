/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
using namespace std;
#include"Player.hpp"
#pragma once


namespace coup{
    class player;

    class Game{

        
    public:
        Game(){}
        vector<Player*> in_the_game;
        vector<string> players();
        string turn();
        string winner ();
        void add_player(Player* player);

    
    };


}
/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
#include <string>
using namespace std;
// #include"Player.hpp"
#pragma once


namespace coup{
    class Player;
    class Game{
        public:
            Game(){}   //cons
            vector<Player*> in_the_game;   //players in the game
            vector <string> listPlayer;     // 
            vector <string> listTurns;      //list that save the turns
            int counter_turns = 0;           // for we can advance the turn in the vector - next place in the vector.    
 

            //actions
            vector<string> players();
            string turn();
            string winner ();
            void add_player(Player* player);
        };


}
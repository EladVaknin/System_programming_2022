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
#include"Game.hpp"
#include"Player.hpp"
using namespace std;
// using namespace coup;


namespace coup{

    int Min_players =2;
    int Max_players =6;

    vector<string> Game::players(){
        if (this->listPlayer.size() == 0 ){
            throw invalid_argument ("Don't have any player in the game");
        }
        // vector<string> result;
        // for (int i=0 ;i<this->in_the_game.size();i++){
        //     result.at(i).push_back(listPlayer.at(i));
        // }
        return listPlayer ;
    }


    string Game::turn(){          //returns the name of the current turn 
        if(this->listPlayer.size()==0){
            throw invalid_argument("The game is over/not started");
        }
        string results = this->listPlayer.at((this->counter_turns)%(this->listPlayer.size()));
        return results;
    }

    string Game::winner (){
        if(this->listPlayer.size() > 1){
            throw invalid_argument ("The game not over");
        }
        string result = this->listPlayer.at(0);       
        return result;
    }

    void Game::add_player(Player* player){
        if(this->listPlayer.size() >= Max_players){
            throw invalid_argument ("The num of participants full");
        }
    }



}
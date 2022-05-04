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
        if (this->in_the_game.size() == 0 ){
            throw invalid_argument ("Don't have any player in the game");
        }
        vector<string> result;
        // for (int i=0 ;i<this->in_the_game.size();i++){
        //     result.at(i).push_back(listPlayer.at(i));
        // }
        return listPlayer ;
    }
    string Game::turn(){          //returns the name of the current turn 
        string tmp = "";
        return tmp;
    }
    
    string Game::winner (){
        if(this->in_the_game.size()>1){
            throw invalid_argument ("The game not over");
        }
        string result = this->listPlayer.back();       //not correct - need to think hot to return the last name in the list
        return result;
    }

    void Game::add_player(Player* player){
        if(this->in_the_game.size() > Max_players){
            throw invalid_argument ("The num of participants full");
        }

    }



}
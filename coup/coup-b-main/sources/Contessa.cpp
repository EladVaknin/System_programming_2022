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
#include "Contessa.hpp"
using namespace std;
// using namespace coup;


namespace coup{

      //Actions

    void Contessa::block(Player &assassian){ //block_assassination
        if(assassian.role_player != "Assassin"){
            throw invalid_argument ("you cant block this player");
        }
        if(_game->listTurns.at(0)=="coup" ){
            throw invalid_argument ("you cant block this now");
        }
        /// need to imple the block
    

    }  

}
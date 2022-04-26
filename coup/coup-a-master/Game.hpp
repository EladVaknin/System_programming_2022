/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
#include "Player.hpp"
class player;
using namespace std;
// using namespace coup;
// #pragma once


namespace cuop{
    class Game{
        
        public:
        Game();
        vector<string> players();
        string turn();
        string winner ();
        void add_player();

    };


}
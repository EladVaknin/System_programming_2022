/**
 * AUTHORS: <Elad Vaknin>
 * 
 * Date: 2022-04
 */
#include<vector>
#include <stdexcept>
using namespace std;
#pragma once


namespace cuop{
    class player;

    class Game{
        
    public:
        Game();
        vector<string> players();
        string turn();
        string winner ();
        void add_player();

    };


}
/**
 *
 * @author Elad Vaknin
 * @since 2022-05
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include "Team.hpp";
// #pragma once
using namespace std;

namespace ariel 
{
    class Game {
        public:
        int game_score = 0;
        // Team *home;
        // Team *gests;
        Game();   
        
        Game(Team* home,Team* gests){
            who_winner(home,gests);

        }

        void who_winner(Team* home,Team* gests){
            int home_bonos_pts =5;
            int skill_bonos_pts = 10;
            int home_random_score =0;          // need to be num between 55-100
            int gest_random_score =0;          // 50 -100


            if (home->skills > gests->skills){     // how get the skill bonos
                home_random_score += skill_bonos_pts;
            }else{
                gest_random_score+=skill_bonos_pts;
            }

            if(home_random_score == gest_random_score){    // if its draw
                if (home->skills > gests->skills){
                    home->winners_counter++;
                    gests->loser_counter ++;
                }else{
                    gests->winners_counter ++;
                    home->loser_counter ++;
                }
            }
            if(home_random_score > gest_random_score){   // home win
                home->winners_counter ++;
                gests->loser_counter ++;

            }else{                                      // gests win
                gests->winners_counter ++;
                home->loser_counter ++;

            }
        }





    };

}
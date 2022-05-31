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
        int game_score = 0;       // to know the difference obtained from each game
        // Team *home;
        // Team *gests;

        Game();   
        
        Game(Team* home,Team* gests){
            who_winner(home,gests);

        }

        void who_winner(Team* home,Team* gests){
            int home_bonos_pts =5;
            int skill_bonos_pts = 10;
            int home_random_score = rand() %50 +55;          // 55-100
            int gest_random_score =rand() %50 +50;          // 50 -100


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
                game_score = 0;
            }
            if(home_random_score > gest_random_score){   // home win
                home->winners_counter ++;
                gests->loser_counter ++;
                game_score = home_random_score - gest_random_score;
                home->difference_basket  +=game_score;
                gests->difference_basket -=game_score;

            }else{                                      // gests win
                gests->winners_counter ++;
                home->loser_counter ++;
                game_score = gest_random_score - home_random_score;
                home->difference_basket -= game_score;
                gests->difference_basket+= game_score;
            }            
        }





    };

}
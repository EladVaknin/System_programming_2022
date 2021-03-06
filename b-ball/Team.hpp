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
// #pragma once
using namespace std;

namespace ariel 
{

    class Team {

        public:
        string name;
        double skills;
        int winners_counter;
        int loser_counter;
        int difference_basket;
        
        ///// need to implements list of result w/l - to know the strike
        Team(); // defult;

        Team(string name ,double skills ,int winner_counter,int loser_counter,int difference_basket){
            this->name =name;
            this->skills=skills;
            this->winners_counter=0;
            this->loser_counter=0;
            this->difference_basket=0;
        }

        void Change_skills(double skill_cahnge){      // if i want to change the skills of the team
            this->skills =skill_cahnge;
        }
    };
    
}
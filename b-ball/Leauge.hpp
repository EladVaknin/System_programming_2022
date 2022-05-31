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
#include <algorithm>
#include "Team.hpp"
// #pragma once
using namespace std;

namespace ariel 
{
    class Leauge{
        private:
        int counter_num_teams =20;

        public:

        vector<Team*> My_Leauge;

        Leauge(){
            Create_random_leauge();
        }

        ~Leauge();


        void Create_random_leauge(){
            string name_club [10] = {"Maccabi","Hapoel","Elitzor","Irony","Beitar","BC","Real","United","Partizan","CSKA"};
            string cities [10] = {"Tel Aviv","Madrid","Manchester","Jerusalem","Petah-Tikva","Ness Tziona","Hadera","Eilat","Ashkelon","Paris"};
            int random_club = 0;
            int random_city =0;
            double random_skill=0;
            string name_after_random;

            while(this->counter_num_teams == 0){
                random_city = rand () % 10 ;   // num between 0-10 
                random_club = rand () % 10 ;   // num between 0-10
                random_skill = rand();   // num 0-1
                srand(time(0));     // every iteration we get new numbers;
                name_after_random =name_club[random_club] +" "+ cities[random_city];  
                this->My_Leauge.push_back(new Team (name_after_random,random_skill,0,0,0));
                this->counter_num_teams--;
            }
        }

        void print_leauge(){
            for (int i =0 ; i<this->My_Leauge.size();i++){
                cout<<this->My_Leauge.at(i)<<endl;
            }
        }



        void return_the_leaders (int number){   // return the leader teames by the input
            sort(this->My_Leauge.begin(),this->My_Leauge.end(), this->My_Leauge.at(0)->winners_counter);         //sort by winner counter

            for (int i =0 ;i<number;i++){
                cout<<this->My_Leauge.at(i)->name<<endl;     // print the name of the teams
            }
        }

        int winner_sequence();
        int loser_sequence();

        void sort_leauge (Leauge &leauge){
        }
    };
    
}
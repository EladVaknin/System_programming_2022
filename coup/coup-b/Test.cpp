#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"


using namespace std;
using namespace coup;

  
TEST_CASE("checks"){

    Game game_1{};
	Duke duke{game_1, "Moshe"};   //
	Assassin assassin{game_1, "Yossi"};  // 
	Ambassador ambassador{game_1, "Meirav"};  // 
	Captain captain{game_1, "Reut"}; // 
	Contessa contessa{game_1, "Gilad"};  // 



//game_1 

// game_1.add_player(duke);
// game_1.add_player(assassin);
// game_1.add_player(ambassador);
// game_1.add_player(ducaptainke);
// game_1.add_player(contessa);
// CHECK(game_1.players() == "Moshe,Yossi,Meirav,Reut,Gilad" );
CHECK_THROWS(game_1.turn());
CHECK_THROWS(game_1.winner());
// CHECK_THROWS(game_1.add_player());


// duke
    // CHECK(duke.name == "Moshe");
	CHECK_THROWS(duke.income());
	CHECK_THROWS(duke.tax());
	CHECK_THROWS(duke.foreign_aid());
	CHECK_THROWS(duke.income());


//ambassador
    // CHECK(ambassador.name == "Meirav");
	CHECK_THROWS(ambassador.income());
	// CHECK(ambassador.counter_coin == 1);
	CHECK_THROWS(ambassador.foreign_aid());
	// CHECK(ambassador.counter_coin ==3);
	CHECK_THROWS(ambassador.transfer(duke,captain));
	// CHECK(ambassador.counter_coin ==2);
	CHECK_THROWS(ambassador.block(captain));

//captain
    // CHECK(captain.name == "Reut");
	CHECK_THROWS(captain.income());
	// CHECK(captain.counter_coin ==1);
	CHECK_THROWS(captain.foreign_aid());
	// CHECK(captain.counter_coin ==3);
	CHECK_THROWS(captain.coup(duke));
	CHECK_THROWS(captain.block(captain));
	CHECK_THROWS(captain.steal(contessa));



//assassin
    // CHECK(assassin.name == "Yossi");
	CHECK_THROWS(assassin.income());
	// CHECK(assassin.counter_coin ==1);
	CHECK_THROWS(assassin.foreign_aid());
	// CHECK(assassin.counter_coin ==3);
	CHECK_THROWS(assassin.coup(duke));
	

//contessa
    // CHECK(contessa.name == "Gilad");
	CHECK_THROWS(contessa.income());
	// CHECK(contessa.counter_coin ==1);
	CHECK_THROWS(contessa.foreign_aid());
	// CHECK(contessa.counter_coin ==3);
	CHECK_THROWS(contessa.coup(duke));










	


 
}

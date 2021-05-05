#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

TEST_CASE("Dispatcher"){ 
    Board board;
    Dispatcher player{board,Algiers};
    player.take_card(Algiers);
    player.build(); //in Algiers
    player.take_card(Madrid).take_card(Paris).take_card(Istanbul);
    CHECK_NOTHROW(player.fly_direct(Cairo)); //no cinnection between the cities
    CHECK_THROWS(player.fly_direct(Atlanta)); //not have research station
    CHECK_THROWS(player.build()); //has no card of atlanta 
}

TEST_CASE("FieldDoctor"){ 
    Board board;
    FieldDoctor player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    CHECK_NOTHROW(player.treat(Paris));
    player.take_card(Chicago); //connected to "SanFrancisco LosAngeles MexicoCity Atlanta Montreal"
    player.fly_direct(Chicago); 
    CHECK_NOTHROW(player.treat(LosAngeles));
    CHECK_NOTHROW(player.treat(Montreal));
}

TEST_CASE("GeneSplicer"){ 
    Board board;
    GeneSplicer player{board,Algiers};
    player.take_card(Milan).
    take_card(Algiers).
    take_card(StPetersburg).
    take_card(Cairo).
    take_card(Baghdad);
    CHECK_NOTHROW(player.discover_cure(Blue));
    CHECK_NOTHROW(player.discover_cure(Black));
}

TEST_CASE("Virologist"){ 
    Board board;
    Virologist player{board,Algiers};
    player.take_card(Milan);
    CHECK_NOTHROW(player.treat(Santiago));
    CHECK_NOTHROW(player.treat(Tehran));
}

TEST_CASE("Medic"){ 
    Board board;
    Medic player{board,Algiers};
    player.take_card(Milan);
    CHECK_NOTHROW(player.treat(Algiers));
    CHECK(board[Algiers]==0);
    CHECK(board[Milan]==0);
}

TEST_CASE("OperationsExpert"){ 
    Board board;
    OperationsExpert player{board,Algiers};
    CHECK_NOTHROW(player.build());
    player.take_card(Milan);
    player.fly_direct(Milan);
    CHECK_NOTHROW(player.build());
}

TEST_CASE("Researcher"){
    Board board;
    Researcher player{board,Algiers};
    CHECK_THROWS(player.discover_cure(Black)); //has no cards
    player.take_card(Algiers).
    take_card(Baghdad).
    take_card(Cairo);
    CHECK_THROWS(player.discover_cure(Black)); //still dont have enough cards
    player.take_card(Chennai).
    take_card(Delhi);
    CHECK_NOTHROW(player.discover_cure(Black));
}

TEST_CASE("Scientist"){
    Board board;
    Scientist player{board,Algiers,2};
    CHECK_THROWS(player.discover_cure(Black)); //has no cards
    player.take_card(Algiers).
    take_card(Cairo);
    CHECK_NOTHROW(player.discover_cure(Black)); 
}






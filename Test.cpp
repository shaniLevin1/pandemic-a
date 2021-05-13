#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace pandemic;
using namespace std;


TEST_CASE("Simple player"){ 
    Board board;

    CHECK(board.is_clean());
    
    Player player{board,Algiers,""}; //connected to "Madrid, Paris, Istanbul, Cairo" Color->Black
    player.take_card(Algiers) //connected to "Madrid, Paris, Istanbul, Cairo"  Color->Black
    .take_card(NewYork)  //connected to "Montreal Washington London Madrid"  Color->Blue
    .take_card(Manila)  //connected to "Taipei SanFrancisco HoChiMinhCity Sydney"  Color->Red
    .take_card(Paris)  //connected to "Algiers Essen Madrid Milan London"  Color->Blue
    .take_card(London) //connected to "NewYork Madrid Essen Paris" Color->Blue
    .take_card(Cairo) //connected to "Algiers Istanbul Baghdad Khartoum Riyadh" Color->Black
    .take_card(Atlanta) //blue
    .take_card(Chicago) //blue
    .take_card(Essen) //blue
    .take_card(Madrid) //blue
    .take_card(Milan) //blue
    .take_card(MexicoCity); //red
    board[NewYork]=4;
    board[Manila]=3;
    //cards->Algiers, NewYork, Manila, Paris, London, Cairo, Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity

    //*************drive************************************ 
    //just connected city 
    
    CHECK_NOTHROW(player.drive(Madrid)); //connected ->"London NewYork Paris SaoPaulo Algiers"
    CHECK_THROWS(player.drive(LosAngeles)); //not connected to "Madrid"

    //*************fly_direct************************************ 
    //drop the card of the city he move to   
    
    CHECK_NOTHROW(player.fly_direct(Algiers)); //have card of "Algiers"
    //cards->NewYork, Manila, Paris, London, Cairo, , Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity
    CHECK_THROWS(player.fly_direct(Paris)); //dont have card of "Paris"

    //*************fly_charter************************************
    //drop the card of the city he is in it
    
    //player city->Algiers
    CHECK_THROWS(player.fly_direct(Manila)); //dont have "Algiers" card

    player.drive(Paris);
    
    CHECK_NOTHROW(player.fly_direct(Montreal)); //have "Paris" card   connected to->"Chicago Washington NewYork" Color->Blue
    //cards->NewYork, Manila, London, Cairo, , Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity    

    //*************build************************************
    //drop the card of the city he is in it,if there is research station he keep the card
    
    //player city->Montreal
    CHECK_THROWS(player.build()); //dont have "Montreal" card
    
    player.drive(NewYork); //connected
    
    CHECK_NOTHROW(player.build());  //have "NewYork" card
    //cards->Manila, London, Cairo, , Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity
    player.drive(London); //connected
    
    CHECK_NOTHROW(player.build()); //have "London" card
    //cards->Manila, Cairo, , Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity

    //*************fly_shuttle************************************
    //if have research station can fly to another city that have without drop any card
    
    //player city->London
    CHECK_NOTHROW(player.fly_shuttle(NewYork)); //two of the cities have research stations
    //player city->NewYork
    CHECK_THROWS(player.fly_shuttle(Cairo)); //"Cairo" dont have research station

    //*************discover_cure************************************
    //need to be in a city that have research station and drop 5 cards in the color of the deseas

    //player city->NewYork  ->have research station
    //cards->Manila, Cairo, Atlanta, Chicago, Essen, Madrid, Milan, MexicoCity
    CHECK_THROWS(player.discover_cure(Yellow));
    CHECK_THROWS(player.discover_cure(Red));
    CHECK_NOTHROW(player.discover_cure(Blue)); //there is 5 blue cards
    //cards->,Manila, Cairo,

    //*************treat************************************ 
    //remove one deseas cube from the city, if there was discover cure to this deseas remove all the cubes
    
    //player city-> NewYork 4 diseas cubes color->blue
    CHECK_NOTHROW(player.treat(NewYork)); //there is cure for color-> blue 
    CHECK_EQ(board[NewYork],0);
    CHECK_THROWS(player.treat(NewYork)); //have 0 diseas cubes so throw exeption

    player.fly_direct(Manila); 

    //cards->Cairo,
    CHECK_NOTHROW(player.treat(Manila)); //have 3 diseas cubes
    CHECK_EQ(board[Manila],2);
}

TEST_CASE("Operator[]"){
    Board board;
    Player player{board,Algiers,""}; 
    player.take_card(Algiers) 
    .take_card(NewYork)  
    .take_card(Manila);
    board[NewYork]=3;
    board[Manila]=2;
    CHECK_EQ(board[Algiers],0); //no deffinition of the number of deseas cubes in this city
    board[Algiers]=1;
    player.treat(Algiers);
    CHECK_EQ(board[Algiers],0);
}

TEST_CASE("role"){
    Board board;
    Dispatcher player1{board,Baghdad}; 
    CHECK_EQ(player1.role(),"Dispatcher");
    FieldDoctor player2{board,Madrid}; 
    CHECK_EQ(player2.role(),"FieldDoctor");
    CHECK_FALSE(player2.role()=="Scientist");
    GeneSplicer player3{board,HongKong}; 
    CHECK_EQ(player3.role(),"GeneSplicer");
}

//if he is in research station he can fly direct any city ho wants without dropping city card
TEST_CASE("Dispatcher"){ 
    Board board;
    Dispatcher player{board,Algiers};
    player.take_card(Algiers); //connected to "Madrid, Paris, Istanbul, Cairo"
    player.build(); //research station in Algiers
    player.take_card(Madrid).
    take_card(Paris).
    take_card(Istanbul);

    CHECK_NOTHROW(player.fly_direct(Cairo)); //there is research station in Algiers
    CHECK_THROWS(player.fly_direct(Atlanta)); //not have research station in Cairo
    CHECK_THROWS(player.build()); //has no card of atlanta 
    CHECK_EQ(player.role(),"Dispatcher");
}

//can do "treat" in any city that connected to his city without dropping city card
TEST_CASE("FieldDoctor"){ 
    Board board;
    FieldDoctor player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    player.take_card(Chicago); //connected to "SanFrancisco LosAngeles MexicoCity Atlanta Montreal"

    CHECK_NOTHROW(player.treat(Paris)); 

    player.fly_direct(Chicago); 
    board[LosAngeles]=2;

    CHECK_NOTHROW(player.treat(LosAngeles));
    CHECK_EQ(board[LosAngeles],1);
    CHECK_NOTHROW(player.treat(LosAngeles));
    CHECK_EQ(board[LosAngeles],0);
    CHECK_THROWS(player.treat(LosAngeles)); //the number of diseas cubes in "LosAngeles" is 0
    
    board[Madrid]=3;
    board[Cairo]=2;

    CHECK_THROWS(player.treat(Madrid)); //not connected to Chicago 
    CHECK_THROWS(player.treat(Cairo)); //not connected to Chicago
    CHECK_EQ(player.role(),"FieldDoctor");
}

//can do "discover cure" with each 5 cards he has (not just the color of the diseas)
TEST_CASE("GeneSplicer"){ 
    Board board;
    GeneSplicer player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    player.take_card(Milan).
    take_card(Algiers).
    take_card(StPetersburg).
    take_card(Cairo).
    take_card(Baghdad);

    CHECK_NOTHROW(player.discover_cure(Blue));
    CHECK_THROWS(player.discover_cure(Black));//dont have any cards
    CHECK_EQ(player.role(),"GeneSplicer");
}

//can do "treat" on every city ho wants by dropping this city card
TEST_CASE("Virologist"){ 
    Board board;
    Virologist player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    player.take_card(Milan);

    CHECK_THROWS(player.treat(Santiago)); //dont have "Santiago" card
    CHECK_NOTHROW(player.treat(Milan)); //has "Milan" card
    CHECK_EQ(player.role(),"Virologist");
}

//when ho do "treat" he remove all diseas cubes in this city 
TEST_CASE("Medic"){ 
    Board board;
    Medic player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    player.take_card(Milan);

    CHECK_NOTHROW(player.treat(Algiers));
    CHECK(board[Algiers]==0);
    CHECK(board[Milan]==0);
    CHECK_EQ(player.role(),"Medic");
}

//can do "build" in any city he is available without drop any card
TEST_CASE("OperationsExpert"){ 
    Board board;
    OperationsExpert player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    CHECK_NOTHROW(player.build());

    player.take_card(Milan);
    player.fly_direct(Milan);

    CHECK_NOTHROW(player.build());
    CHECK_EQ(player.role(),"OperationsExpert");
}

//can do discover cure in any city even without research station
TEST_CASE("Researcher"){
    Board board;
    Researcher player{board,Algiers}; //connected to "Madrid Paris Istanbul Cairo"
    CHECK_THROWS(player.discover_cure(Black)); //has no cards
    player.take_card(Algiers).
    take_card(Baghdad).
    take_card(Cairo);

    CHECK_THROWS(player.discover_cure(Black)); //still dont have enough cards

    player.take_card(Chennai).
    take_card(Delhi);

    CHECK_NOTHROW(player.discover_cure(Black));
    CHECK_EQ(player.role(),"Researcher");
}

//can do discover cure with "n" cards (not 5) according the deffinition of the Scientist
TEST_CASE("Scientist"){
    Board board;
    Scientist player{board,Algiers,2}; //connected to "Madrid Paris Istanbul Cairo"

    CHECK_THROWS(player.discover_cure(Black)); //has no cards
    
    player.take_card(Algiers).
    take_card(Cairo);

    CHECK_NOTHROW(player.discover_cure(Black)); 
    CHECK_EQ(player.role(),"Scientist");
}






#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<string>
#include"Color.hpp"
#include"City.hpp"
#include "Board.hpp"

using namespace std;
namespace pandemic{
class Player{
    protected:
    Board b;
    City c;
    // string type;
    public:
        // inline Player(Board &b,City c,string type):b(b),c(c),type(type){}
        inline Player(Board &b,City c):b(b),c(c){}
        Player& drive(City city);
        virtual Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);  
        virtual Player& treat(City city);
        Player& take_card(City city);
        Player& role(); //dont sure about what the func returns
        friend ostream& operator<<(ostream& out, Player const &player);
};
}
#endif
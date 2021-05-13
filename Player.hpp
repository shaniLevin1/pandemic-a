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
        Board& board;
        City city;
        set<City> cards;
        string special_role;
    public:
        inline Player(Board &b,City c,string special_role):board(b),city(c),special_role(special_role){}
        Player& drive(City city);
        virtual Player& fly_direct(City city);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color);  
        virtual Player& treat(City city);
        Player& take_card(City city);
        string role(); 
        void remove_cards();
        friend ostream& operator<<(ostream& out, Player const &player);
};
}
#endif
#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Virologist:public Player{
    private:
        Board board;
        City city;
        string special_role;
    public:
        Player& treat(City City) override;
        inline Virologist(Board board, City city):Player(board,city,"Virologist"){}
};
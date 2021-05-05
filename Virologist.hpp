#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Virologist:public Player{
    private:
        Board board;
        City city;
    public:
        Player& treat(City City) override;
        inline Virologist(Board board, City city):Player(board,city){}
};
#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Medic:public Player{
    private:
        Board board;
        City city;
        // string role;

    public:
        Player& treat(City City) override;
        inline Medic(Board board, City city):Player(board,city,"Medic"){}
};
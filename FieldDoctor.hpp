#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class FieldDoctor:public Player{
    private:
        Board board;
        City city;
        // string role;
    public:
        Player& treat(City city) override;
        inline FieldDoctor(Board board, City city):Player(board,city,"FieldDoctor"){}
};
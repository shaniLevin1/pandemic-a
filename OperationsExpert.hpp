#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class OperationsExpert:public Player{
    private:
        Board board;
        City city;
        // string role="OperationsExpert";
    public:
        Player& build() override;
        inline OperationsExpert(Board board, City city):Player(board,city,"OperationsExpert"){}
};
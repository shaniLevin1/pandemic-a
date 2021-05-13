#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Researcher:public Player{
    private:
        Board board;
        City city;
        // string special_role;
    public:
        Player& discover_cure(Color color) override;
        inline Researcher(Board board, City city):Player(board,city,"Researcher"){}
};
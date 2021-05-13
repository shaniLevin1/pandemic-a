#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;
class Scientist:public Player{
    private:
        Board board;
        City city;
        int n;
        // string special_role;

    public:
        Player& discover_cure(Color color) override;
        inline Scientist(Board board, City city, int n):Player(board,city,"Scientist"){}
};
#pragma once
#ifndef _BOARD_H_
#define _BOARD_H_
#include<string>
#include<map>
#include<set>
#include<list>
#include"City.hpp"
#include"Color.hpp"


namespace pandemic{
    class Board{
        private:
            static map<City,Color> city_color;
            static map<City,set<City>> city_connection;
            static map<City, int> city_diseas_cubes;
            map<City, bool> city_if_have_research_stations;
            // // smaktatic bool city_madication[4]; //bool[0]=1=true-blue bool[1]=0-false-yellow  map<Color,bool> 
            map<Color,bool> color_madication;

        public: 
            // Board();
           int& operator[](City city);
           friend ostream& operator<<(ostream& out,const Board& board);
           static bool is_clean(); //should be static
           void remove_cures();

    };
}
#endif

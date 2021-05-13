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
            static map<City, int> city_if_have_research_stations;
            // smaktatic bool city_madication[4]; //bool[0]=1=true-blue bool[1]=0-false-yellow  map<Color,bool> 
            static map<Color,bool> color_madication;
        
        public: 
           int& operator[](City city);
           friend ostream& operator<<(ostream& out,const Board& board);
           static bool is_clean(); //should be static
           static void remove_cures();
           static bool city_connected(City& city1,City& city2);
           static int city_research_stations(City& city);
           static void update_research_station(City& city,int num);
           static Color color_of_city(City& city);
           static bool find_madication(Color& color);
           static void update_madication(Color& color);
           static bool if_found_madication(Color& color);
           static void update_color_madication(Color& color);
           static void remove_stations();
        //    static int diseas_cubes_of_city(City& city);
        //    static void update_diseas_cubes(City& city,int);
    };
}
#endif

#include"Board.hpp"
#include <map>
#include <string>
#include<set>
using namespace std;
namespace pandemic{

    int& Board::operator[](City city){
        return city_diseas_cubes[city];
    } 
    ostream& operator<<(ostream& out,const Board& board){
        return out;
    }
    bool Board::is_clean(){
        for(auto& city: Board::city_diseas_cubes) {
            if(city.second>0) {
                return false;
            }
        }
        return true;
    }
    void Board::remove_cures(){
        map<Color, bool>::iterator it;
        for (it = Board::color_madication.begin(); it != Board::color_madication.end(); it++){
           Board::color_madication.at(it->first)=false;
        }
    }
    bool Board::city_connected(City& city1, City& city2) {
        return city_connection.at(city1).count(city2)==1; //if count func return 1-contains if 0-not
    }
    
    int Board::city_research_stations(City& city){
        return Board::city_if_have_research_stations.at(city);
    }

    void Board::update_research_station(City& city,int num){
        Board::city_if_have_research_stations.at(city)=num;
    }

    Color Board::color_of_city(City& city){
        return city_color.at(city);
    }

    bool Board::find_madication(Color& color){
        return color_madication.at(color);
    }

    void Board::update_madication(Color& color){
        color_madication.at(color);
    }

    bool Board::if_found_madication(Color& color){
        return color_madication.at(color);
    }

    void Board::remove_stations(){
        map<City,int>::iterator it;
        for (it = Board::city_if_have_research_stations.begin(); it != Board::city_if_have_research_stations.end(); it++){
           city_if_have_research_stations.at(it->first)=0;
        }
    }

    // int Board::diseas_cubes_of_city(City& city){
    //     return city_diseas_cubes.at(city);
    // }

    map<City,Color> Board::city_color={{Algiers,Black},
                        {Madrid,Black},
                        {Paris,Blue},
                        {Istanbul,Black},
                        {Cairo,Black},
                        {Atlanta,Blue},
                        {Chicago,Blue},
                        {Miami,Blue},
                        {Washington,Blue},
                        {Baghdad,Black},
                        {Tehran,Black},
                        {Riyadh,Black},
                        {Karachi,Black},
                        {Bangkok,Red},
                        {Kolkata,Black},
                        {Chennai,Black},
                        {Jakarta,Black},
                        {HoChiMinhCity,Red},
                        {HongKong,Red},
                        {Beijing,Red},
                        {Shanghai,Red},
                        {Seoul,Red},
                        {Bogota,Yellow},
                        {MexicoCity,Blue},
                        {Lima,Yellow},
                        {Mumbai,Black},
                        {SaoPaulo,Yellow},
                        {BuenosAires,Yellow},
                        {Khartoum,Red},
                        {Delhi,Black},
                        {Essen,Blue},
                        {London,Blue},
                        {Milan,Blue},
                        {StPetersburg,Blue},
                        {Manila,Red},
                        {Taipei,Red},
                        {Moscow,Black},
                        {Sydney,Red},
                        {Johannesburg,Yellow},
                        {Kinshasa,Red},
                        {Lagos,Red},
                        {NewYork,Blue},
                        {Santiago,Yellow},
                        {Montreal,Blue},
                        {Osaka,Red},
                        {Tokyo,Red},
                        {LosAngeles,Blue},
                        {SanFrancisco,Blue}
                        };
    map<City,set<City>> Board::city_connection{
        { Algiers, {Madrid, Paris, Istanbul, Cairo } },
        { Atlanta, {Chicago, Miami, Washington } },
        { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
        { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
        { Beijing, {Shanghai, Seoul } },
        { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
        { BuenosAires, {Bogota, SaoPaulo } },
        { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
        { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
        { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
        { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
        { Essen, {London, Paris, Milan, StPetersburg } },
        { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
        { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
        { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
        { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
        { Johannesburg, {Kinshasa, Khartoum } },
        { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
        { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
        { Kinshasa, {Lagos, Khartoum, Johannesburg } },
        { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
        { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
        { Lima, {MexicoCity, Bogota, Santiago } },
        { London, {NewYork, Madrid, Essen, Paris } },
        { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
        { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
        { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
        { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
        { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
        { Milan, {Essen, Paris, Istanbul } },
        { Montreal, {Chicago, Washington, NewYork } },
        { Moscow, {StPetersburg, Istanbul, Tehran } },
        { Mumbai, {Karachi, Delhi, Chennai } },
        { NewYork, {Montreal, Washington, London, Madrid } },
        { Osaka, {Taipei, Tokyo } },
        { Paris, {Algiers, Essen, Madrid, Milan, London } },
        { Riyadh, {Baghdad, Cairo, Karachi } },
        { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
        { Santiago, {Lima } },
        { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
        { Seoul, {Beijing, Shanghai, Tokyo } },
        { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
        { StPetersburg, {Essen, Istanbul, Moscow } },
        { Sydney, {Jakarta, Manila, LosAngeles } },
        { Taipei, {Shanghai, HongKong, Osaka, Manila } },
        { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
        { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
        { Washington, {Atlanta, NewYork, Montreal, Miami } }
    };
    
    map<City, int> Board::city_diseas_cubes{
        {{Algiers,0},
            {Madrid,0},
            {Paris,0},
            {Istanbul,0},
            {Cairo,0},
            {Atlanta,0},
            {Chicago,0},
            {Miami,0},
            {Washington,0},
            {Baghdad,0},
            {Tehran,0},
            {Riyadh,0},
            {Karachi,0},
            {Bangkok,0},
            {Kolkata,0},
            {Chennai,0},
            {Jakarta,0},
            {HoChiMinhCity,0},
            {HongKong,0},
            {Beijing,0},
            {Shanghai,0},
            {Seoul,0},
            {Bogota,0},
            {MexicoCity,0},
            {Lima,0},
            {Mumbai,0},
            {SaoPaulo,0},
            {BuenosAires,0},
            {Khartoum,0},
            {Delhi,0},
            {Essen,0},
            {London,0},
            {Milan,0},
            {StPetersburg,0},
            {Manila,0},
            {Taipei,0},
            {Moscow,0},
            {Sydney,0},
            {Johannesburg,0},
            {Kinshasa,0},
            {Lagos,0},
            {NewYork,0},
            {Santiago,0},
            {Montreal,0},
            {Osaka,0},
            {Tokyo,0},
            {LosAngeles,0},
            {SanFrancisco,0} }
        };
        map<City, int> Board::city_if_have_research_stations{
        {{Algiers,0},
            {Madrid,0},
            {Paris,0},
            {Istanbul,0},
            {Cairo,0},
            {Atlanta,0},
            {Chicago,0},
            {Miami,0},
            {Washington,0},
            {Baghdad,0},
            {Tehran,0},
            {Riyadh,0},
            {Karachi,0},
            {Bangkok,0},
            {Kolkata,0},
            {Chennai,0},
            {Jakarta,0},
            {HoChiMinhCity,0},
            {HongKong,0},
            {Beijing,0},
            {Shanghai,0},
            {Seoul,0},
            {Bogota,0},
            {MexicoCity,0},
            {Lima,0},
            {Mumbai,0},
            {SaoPaulo,0},
            {BuenosAires,0},
            {Khartoum,0},
            {Delhi,0},
            {Essen,0},
            {London,0},
            {Milan,0},
            {StPetersburg,0},
            {Manila,0},
            {Taipei,0},
            {Moscow,0},
            {Sydney,0},
            {Johannesburg,0},
            {Kinshasa,0},
            {Lagos,0},
            {NewYork,0},
            {Santiago,0},
            {Montreal,0},
            {Osaka,0},
            {Tokyo,0},
            {LosAngeles,0},
            {SanFrancisco,0} }
        };
        map<Color,bool> Board::color_madication{
            {{Black,false},
            {Blue,false},
            {Yellow,false},
            {Red,false}}
            };
  
}
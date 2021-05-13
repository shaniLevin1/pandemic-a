#include"Player.hpp"
#include"Board.hpp"
#include"City.hpp"
#include<iterator>
#include<map>
using namespace std;
namespace pandemic{
    
    Player& Player::drive(City city){ 
        // if(Player::city==city){ //trying to drive to the city that 
        //     throw invalid_argument{"Execption-> "};

        // }
        // if(Board::city_connected(Player::city,city)){
        //     Player::city=city;
        // }
        // else{
        //     throw invalid_argument{"Execption-> there is no cinnection between the cities"};
        // }
        return *this;
    }
    Player& Player::fly_direct(City city){
        // if(Player::cards.count(city)==1){ //the player has the card of the city 
        //     Player::city=city;
        //     cards.erase(city);
        // }
        // else{
        //     throw invalid_argument{"Execption-> dont have the card of the city"};
        // }
        return *this;
    }
    Player& Player::fly_charter(City city){
        // if(Player::cards.count(Player::city)==1){ //the player has the card of the city 
        //     Player::city=city;
        //     cards.erase(Player::city);
        // }
        // else{
        //     throw invalid_argument{"Execption-> dont have the card of the city"};
        // }
        return *this;
    }
    Player& Player::fly_shuttle(City city){ //need to check if we need to drop card from the set
        // if(Board::city_research_stations(Player::city)&&Board::city_research_stations(city)){
        //     Player::city=city;
        // }
        // else{
        //     throw invalid_argument{"Execption-> there is no research station in one of the cities"};
        // }
        return *this;
    }
    Player& Player::build(){
        // if(Player::cards.count(Player::city)==1){
        //     if(!Board::city_research_stations(Player::city)){ //there is no research_stations in this city
        //         Board::add_research_station(Player::city);
        //         cards.erase(Player::city);
        //     }
        //     else return *this;
        // }  
        // else{
        //     throw invalid_argument{"Execption-> dont have the card of the city"};
        // }  
     return *this;
    }
    Player& Player::discover_cure(Color color){
//         if(!Board::find_madication(color)){ //if the madication for this color did not found yet
//             if(Board::city_research_stations(Player::city)){
//                 int count=0; 
//                 bool flag=false;
//                 for (auto card : Player::cards){
//                     if(Board::color_of_city(card)==color){
//                         count++;
//                     }
//                 }
//                 if(count>5){
//                     flag=true;
//                     count=0;
//                 for (auto card : Player::cards){
//                         if(count<5){
//                             if(Board::color_of_city(card)==color){
//                                 Player::cards.erase(card);
//                                 count++;
//                             }    
//                         }    
//                     }
//                 }   
//             if(flag){
//               Board::update_madication(color);  
//             } 
//             }
//             }   
        return *this;
    } 
// //     טיפול במחלה - treat - הורדת קוביית-מחלה אחת מהעיר שנמצאים בה (הפחתת רמת המחלה ב-1).
// // אם כבר התגלתה תרופה למחלה בצבע של העיר, אז פעולת "ריפוי מחלה" מורידה את כל קוביות המחלה מהעיר שנמצאים בה (הפחתת רמת המחלה ל-0).
// // אם אין בכלל זיהום בעיר (רמת המחלה היא 0), אז הפעולה תזרוק חריגה.
    Player& Player::treat(City city){
//         Color color=Board::color_of_city(city);
//         if(Player::board[city]==0){ //if there is no diseas in the city
//             throw invalid_argument{"Execption-> there is no diseas in the city"};
//         }
//         else if(Board::if_found_madication(color)){ //if there is a medication for this color of city
//             Player::board[city]=0;
//         }
//         else{
//             Player::board[city]=Player::board[city]-1;
        
        return *this;
    }
    Player& Player::take_card(City city){
        // if(!Player::cards.count(city)){ //if the player dont have the card of this city
        //     Player::cards.insert(city);
        // }    
        return *this;
    }
    string Player::role(){ //dont sure about what the func returns
        return Player::special_role;
    }
    ostream& operator<<(ostream& out, Player const &player){
        return out;
    }
}
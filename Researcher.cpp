#include"Researcher.hpp"

using namespace pandemic;

Player& Researcher::discover_cure(Color color){
    // if(!Board::find_madication(color)){ //if the madication for this color did not found yet
    //     // if(Board::city_research_stations(Player::city)){
    //         int count=0; 
    //         bool flag=false;
    //         for (auto card : Player::cards){
    //             if(Board::color_of_city(card)==color){
    //                 count++;
    //             }
    //         }
    //         if(count>5){
    //             flag=true;
    //             count=0;
    //         for (auto card : Player::cards){
    //                 if(count<5){
    //                     if(Board::color_of_city(card)==color){
    //                         Player::cards.erase(card);
    //                         count++;
    //                     }    
    //                 }    
    //             }
    //         }   
    //     if(flag){
    //         Board::update_madication(color);  
    //     } 
    //     }
    //     // }   
        return *this;
    } 
#include"Player.hpp"

using namespace std;
namespace pandemic{
    // Player::Player(Board &b,City c,string type){
    //     this->b=b;
    //     this->c=c;
    //     this->type=type;
    // }
    Player& Player::drive(City city){   
        return *this;
    }
    Player& Player::fly_direct(City city){
        return *this;
    }
    Player& Player::fly_charter(City city){
        return *this;
    }
    Player& Player::fly_shuttle(City city){
       return *this;
    }
    Player& Player::build(){
     return *this;
    }
    Player& Player::discover_cure(Color color){
        return *this;
    } 
    Player& Player::treat(City city){
        return *this;
    }
    Player& Player::take_card(City city){
        return *this;
    }
    Player& Player::role(){ //dont sure about what the func returns
        return *this;
    }
    ostream& operator<<(ostream& out, Player const &player){
        return out;
    }
}
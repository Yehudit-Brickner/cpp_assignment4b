
#include "Turn.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

using namespace coup;

Turn::Turn(Player &  p,int c, string s, vector<Player*> v){
    this->_whoPlayed = &p;
    this->coins_stolen=c;
    this->_action=s;
    this->_doneTo=v;
    this->_blocked=false;        
}

Turn::Turn(Player & p,int c, string s){
    this->_whoPlayed = &p;
    this->coins_stolen=c;
    this->_action=s;
    this->_blocked=false; 
}


// Turn::Turn(const Turn &o){
// this->_whoPlayed=o._whoPlayed;
// this->_action=o._action;
// this->coins_stolen=o.coins_stolen;
// this->_doneTo=o._doneTo;
// this->_blocked=o._blocked;
// }
    
Player* Turn::getPlayer(){
    return this->_whoPlayed;
}

int Turn::getCoins_stolen(){
    return this->coins_stolen; 
}

string Turn::getAction(){
    return this->_action;
}

vector<Player*> Turn::getDoneTo(){
    return this->_doneTo;
}

bool Turn::getBlocked(){
    return this->_blocked;
}

void Turn::setBlocked(bool b){
    this->_blocked=b;
}

void Turn::print(){
    cout<<"starting printing"<<endl;
    cout<< this->_whoPlayed <<"  "; 
    Player * p=this->_whoPlayed;
    cout<< this->_action<<"   ";
    cout<< this->coins_stolen<< "   ";
    cout << this->_blocked;
    cout<<" "<<endl;
}
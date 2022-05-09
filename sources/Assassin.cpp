#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Assassin::Assassin(Game & g, string  n):Player(g, std::move(n)) {

}

void Assassin::coup(Player & p){

    const int seven=7;
    const int three=3;
    const int one=1;
    this->_game->_started=true;
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_game->_player.size()<=one){
      throw std::invalid_argument( "cant play with 1 player or less!" );    
    }
    this->_game->_started=true;
    vector<string>play=this->_game->players();
    bool found=false;
    for (unsigned long i=0; i<play.size();i++){
        if(play[i]==p.getName()){
            found=true;
        }
    }
    if( !found){
       throw std::invalid_argument( "player not in game" ); 
    }
    if(this->_coins>=seven){
        this->updateCoins(-seven);
        p.setState(2);
        string s= this->getName();
        s.append(",0,coup7,");
        s.append(p.getName());
        s.append(",null");
        this->setLastturn(s);
        this->_game->updateTurn();     
    }
    else{
        if(this->_coins<three){
            throw std::invalid_argument( "cant pay 3 coins" ); 
        }
    this->updateCoins(-three);
    p.setState(1);
    string s= this->getName();
    s.append(",0,coup3,");
    s.append(p.getName());
    s.append(",null");
    this->setLastturn(s);
    this->_game->updateTurn(); 
    }
}

string Assassin::role(){
    return "Assassin";
}

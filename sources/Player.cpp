#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

using namespace coup;

Player::Player(Game & g, string  n) {
    const int six=6;
    bool canadd=g._started;
    if (g._player.size()<six && !canadd){
        this->_game=& g;
        this->_name=std::move(n);
        this->_coins=0;
        this->_lastturn="none";
        this->_state=0;
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
       
}


int Player::coins()const{
    return this->_coins;
}

void Player::updateCoins(int u){
    int num = this->getCoins();
    num=num+u;
    this->_coins=num;
}

int  Player::getCoins()const{
    return this->_coins;
}

string Player::getName() const{
    return this->_name;
}

void Player::setState(int s){
    this->_state=s;
}

void Player::setLastturn(string s){
    this->_lastturn=std::move(s);
}

string Player::getLastturn()const{
    return this->_lastturn;
}

string Player::role(){
    return this->getName();
}


void Player::income(){
    const int ten=10;
    const int one=1;
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
        throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=ten){
        throw std::invalid_argument( "you have to do coup!" );  
    }
    if(this->_game->_player.size()<=one){
      throw std::invalid_argument( "cant play with 1 player or less!" );    
    }
    this->_game->_started=true;
    updateCoins(1);
    string s= this->getName();
    s.append(",0,income,null,null");
    this->setLastturn(s);
    this->_game->updateTurn();
}

void Player::foreign_aid(){
    const int ten=10; 
    const int one=1;
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=ten){
        throw std::invalid_argument( "you have to do coup!" );  
    }
    if(this->_game->_player.size()<=one){
      throw std::invalid_argument( "cant play with 1 player or less!" );    
    }
    this->_game->_started=true;
    updateCoins(2);
    string s= this->getName();
   
    s.append(",0,forign_aid,null,null");
    this->setLastturn(s);
    this->_game->updateTurn();
}

void Player::block(coup::Player & p){
    throw std::invalid_argument( "this player cant block the other player" );     
}

void Player::coup(coup::Player & p){
    const int  seven=7;
    const int three=3;
    const int one=1;
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
    if (this->_coins<seven){
        throw std::invalid_argument( "cant pay 7 coins" );  
    }
    p.setState(2);
    string s= this->getName();
    s.append(",0,coup7,");
    s.append(p.getName());
    s.append(",null");
    this->setLastturn(s);
    this->updateCoins(-seven);
    this->_game->updateTurn(); 
    }


void Player::print(){
    cout<<this<< "  "<<this->role()<< "  "<< this->getName() <<endl;
}
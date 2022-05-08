

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

using namespace coup;

Player::Player(Game & g, string  n){
    const int six=6;
    cout<< "this is a constructor for player"<< endl;
    bool canadd=g._started;
    if (g._player.size()<six && !canadd){
        this->_game=& g;
        this->_name=n;
        this->_coins=0;
        this->_role="Player";
        this->_lastturn="none";
        // g.addplayer(n);
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
    
}

Player::Player(){
  
}

string Player::getName() const{
    return this->_name;
}

int  Player::getCoins()const{
    return this->_coins;
}

void Player::updateCoins(int u){
    int num = this->getCoins();
    num=num+u;
    this->_coins=num;
}

int Player::coins()const{
    return this->_coins;
}

void Player::setState(int s){
    this->_state=s;
}

void Player::setLastturn(string s){
    this->_lastturn=s;
}

string Player::getLastturn()const{
    return this->_lastturn;
}

void Player::print(){
    cout<<this<< "  "<<this->role()<< "  "<< this->getName() <<endl;
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
    cout<<"forign_aid"<<endl;
    updateCoins(2);
    cout<<"added 2 coins"<<endl;
    string s= this->getName();
   
    s.append(",0,forign_aid,null,null");
    this->setLastturn(s);
    this->_game->updateTurn();
}


void Player::block(coup::Player & p){
    throw std::invalid_argument( "this player cant block the other player" );     
}



string Player::role(){
    return this->getName();
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

    // cout << "a player is trying to coup. the player has " << this->_coins << " coins"<<endl;
   

    if (this->_coins<seven){
        throw std::invalid_argument( "cant pay 7 coins" );  
    }

    p.setState(2);
    cout<<"the assigned player state is "<< p._state <<endl;
    string s= this->getName();
    s.append(",0,coup7,");
    s.append(p.getName());
    s.append(",null");
    this->setLastturn(s);
    this->updateCoins(-seven);
    this->_game->updateTurn(); 
    }



// bool Player::operator== (const Player & p )const{
//     return (this->_name==p._name && this->_role==p._role);
// }
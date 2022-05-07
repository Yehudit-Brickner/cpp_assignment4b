

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

using namespace coup;

Player::Player(Game & g, string n){
    cout<< "this is a constructor for player"<< endl;
    this->_game=& g;
    this->_name=n;
    this->_coins=0;
    this->_role="Player";
    if (g._player.size()<6){
        g._player.push_back(& *this);
    }
    g.addplayer(n);
}

Player::Player(){
  
}

string Player::getName(){
    return this->_name;
}

int  Player::getCoins(){
    return this->_coins;
}

void Player::updateCoins(int u){
    int num = this->getCoins();
    num=num+u;
    this->_coins=num;
}

int Player::coins(){
    return this->_coins;
}

void Player::setState(int s){
    this->_state=1;
}


void Player::print(){
    cout<<this<< "  "<<this->role()<< "  "<< this->getName() <<endl;
}


void Player::income(){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
        throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=10){
        throw std::invalid_argument( "you have to do coup!" );  
    }

    cout<<"income"<<endl;
    updateCoins(1);
    cout<<"added a coin"<<endl;
    Turn t1{*this, 0,"income"};
    // this->_game->gameTurns.push(&t1);
    this->_game->_gameTurns.push_back(&t1);
    this->_game->updateTurn();
}

void Player::foreign_aid(){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=10){
        throw std::invalid_argument( "you have to do coup!" );  
    }
    
    cout<<"forign_aid"<<endl;
    updateCoins(2);
    cout<<"added 2 coins"<<endl;
    Turn t2{*this, 0,"forign_aid"};
    // this->_game->gameTurns.push(&t2);
    this->_game->_gameTurns.push_back(&t2);
    this->_game->updateTurn();
}


// void Player::block(coup::Player p){
//     // will need a queue to hold the last full turns of things to know what to block and how to rool back
//     cout<< "blocked"<<endl;
// }



string Player::role(){
    return this->getName();
}


void Player::coup(coup::Player p){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    cout << "a player is trying to coup. the player has " << this->_coins << " coins"<<endl;
    int const money1=7;
    int const money2=3;

    
    if (this->_role=="assassin"){
        if (this->_coins<money2){
            throw std::invalid_argument( "cant pay 7 coins" ); 
        }
        p.setState(1);
        vector<Player*> v1={&p};
        Turn t1{*this, 0,"coup", v1};
        // this->_game->gameTurns.push(&t1);
        this->_game->_gameTurns.push_back(&t1);
        this->_game->updateTurn();

    }
    else{
        if (this->_coins<money1){
            throw std::invalid_argument( "cant pay 7 coins" );  
        }
    
        p.setState(1);
        cout<<"the assigned player state is "<< p._state <<endl;
        vector<Player*> v1={&p};
        Turn t1{*this, 0,"coup",v1};
        // this->_game->gameTurns.push(&t1);
        this->_game->_gameTurns.push_back(&t1);
        this->_game->updateTurn(); 
    }
}

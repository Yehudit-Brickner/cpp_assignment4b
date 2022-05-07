#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Assassin::Assassin(Game & g, string n) {
    cout<< "this is a constructor for Assassin"<< endl;
    this->_game= & g;
    this->_name=n;
    this->_coins=0;
    this->_role="Assassin";
    this->_state = 0;
     if (g._player.size()<6){
        g._player.push_back(& *this);
    }
    g.addplayer(n);
}



string Assassin::role(){
    return this->_role;
}


void Assassin::coup(Player & p){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=7){
        cout<<"Assasin coup7"<<endl;
        this->updateCoins(-7);
        p.setState(1);
        // vector<Player*> v1={&p};
        Turn t1{*this, 0,"coup7",p};
        // this->_game->gameTurns.push(&t1);
        this->_game->_gameTurns.push_back(&t1);
        this->_game->updateTurn();     
    }
    if(this->_coins<3){
         throw std::invalid_argument( "cant pay 3 coins" ); 
    }
    cout<<"Assasin coup3"<<endl;
    this->updateCoins(-3);
    p.setState(1);
    // vector<Player*> v1={&p};
    Turn t1{*this,0, "coup3",p};
    // this->_game->gameTurns.push(&t1);
    this->_game->_gameTurns.push_back(&t1);
    this->_game->updateTurn(); 
}
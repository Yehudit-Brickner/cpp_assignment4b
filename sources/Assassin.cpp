#include "Assassin.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Assassin::Assassin(Game & g, string n) {
    cout<< "this is a constructor for Assassin"<< endl;
    if (g._player.size()<6){
        this->_game= & g;
        this->_name=n;
        this->_coins=0;
        this->_role="Assassin";
        this->_state = 0;
        this->_lastturn="none";
        g._player.push_back(& *this);
        g.addplayer(n);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
    
}



string Assassin::role(){
    return this->_role;
}


void Assassin::coup(Player & p){

    const int seven=7;
    const int three=3;
    const int one=1;
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_game->_player.size()<=one){
      throw std::invalid_argument( "cant play with 1 player or less!" );    
    }
    vector<string>play=this->_game->players();
    bool found=false;
    for (unsigned long i=0; i<play.size();i++){
        if(play[i]==p.getName()){
            found=true;
        }
    }
    if( found==false){
       throw std::invalid_argument( "player not in game" ); 
    }
    if(this->_coins>=seven){
        cout<<"Assasin coup7"<<endl;
        this->updateCoins(-7);
        p.setState(2);
        string s= this->getName();
        s.append(" 0 coup7 ");
        s.append(p.getName());
        s.append(" null");
        this->setLastturn(s);

        // vector<Player*> v1={&p};
        // Turn t1{*this, 0,"coup7",p};
        // this->_game->gameTurns.push(&t1);
        // this->_game->_gameTurns.push_back(&t1);
        this->_game->updateTurn();     
    }
    else{
        if(this->_coins<three){
            throw std::invalid_argument( "cant pay 3 coins" ); 
        }
    cout<<"Assasin coup3"<<endl;
    this->updateCoins(-3);
    p.setState(1);
    string s= this->getName();
    s.append(" 0 coup3 ");
    s.append(p.getName());
    s.append(" null");
    this->setLastturn(s);
    // vector<Player*> v1={&p};
    // Turn t1{*this,0, "coup3",p};
    // this->_game->gameTurns.push(&t1);
    // this->_game->_gameTurns.push_back(&t1);
    this->_game->updateTurn(); 
    }
}
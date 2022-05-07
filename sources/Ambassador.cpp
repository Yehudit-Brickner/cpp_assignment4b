
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Ambassador::Ambassador(Game & g, string n){
    cout<< "this is a constructor for Ambassador"<< endl;
    this->_game= & g;
    this->_name=n;
    this->_coins=0;
    this->_role="Ambassador";
    this->_state = 0;
     if (g._player.size()<6){
        g._player.push_back(& *this);
    }
    g.addplayer(n);
}

string Ambassador::role(){
    return this->_role;
}


void Ambassador::transfer(coup::Player p1, coup::Player p2){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=10){
        throw std::invalid_argument( "you have to do coup!" );  
    }
    p1.updateCoins(-1);
    p2.updateCoins(1);
    vector<Player*> v1={&p1,&p2};
    Turn t1{*this, 1,"transfer",v1};
    // this->_game->gameTurns.push(&t1);
    this->_game->_gameTurns.push_back(&t1);
    this->_game->updateTurn(); 
}

void Ambassador::block(coup::Captain c){
    int start=(int)this->_game->_gameTurns.size()-1;
    int size=(int)this->_game->_player.size();
    int end=start-size;
    if(end<0){
        end=0;
    }
    for (unsigned long i=(unsigned long)start; i >= (unsigned long) end;i--){
        if(this->_game->_gameTurns[i]->getPlayer()==&c and this->_game->_gameTurns[i]->getAction()=="steal" and this->_game->_gameTurns[i]->getBlocked()==false ){
           cout<<"blocked"<<endl;
           vector<Player*> p=this->_game->_gameTurns[i]->getDoneTo();
           p[0]->updateCoins(2);
           c.updateCoins(-2); 
           this->_game->_gameTurns[i]->setBlocked(true);  
        }
    }
}
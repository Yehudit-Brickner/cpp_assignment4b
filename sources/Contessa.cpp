#include "Contessa.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Contessa::Contessa(Game & g, string n){
    cout<< "this is a constructor for Contessa"<< endl;
   bool canadd=g._started;
    // for (unsigned long i=0; i<g._player.size();i++){
    //     if(g._player[i]->getLastturn()!="none"){
    //         canadd=false;
    //     }
    // }
    if (g._player.size()<6 && !canadd){
        this->_game=& g;
        this->_name=n;
        this->_coins=0;
        this->_role="Contessa";
        this->_state = 0;
        this->_lastturn="none";
        g.addplayer(n);
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
   
}


string Contessa::role(){
    return this->_role;
}

// void Contessa::block(coup::Assassin a){
    
//     int start=(int)this->_game->_gameTurns.size()-1;
//     int size=(int)this->_game->_player.size();
//     int end=start-size;
//     if(end<0){
//         end=0;
//     }
//     for (unsigned long i=(unsigned long)start; i > (unsigned long)end;i--){
//         if(this->_game->_gameTurns[i]->getPlayer()==&a and this->_game->_gameTurns[i]->getAction()=="coup3" and this->_game->_gameTurns[i]->getBlocked()==false ){
//            cout<<"blocked"<<endl;
//            vector<Player*> p=this->_game->_gameTurns[i]->getDoneTo();
//            p[0]->setState(0);
//            this->_game->_gameTurns[i]->setBlocked(true);
//         } 
//     }

// }
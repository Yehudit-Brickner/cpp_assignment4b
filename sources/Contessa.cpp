#include "Contessa.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Contessa::Contessa(Game & g, string n){
    const int six=6;
    bool canadd=g._started;
    if (g._player.size()<six && !canadd){
        this->_game=& g;
        this->_name=std::move(n);
        this->_coins=0;
        this->_role="Contessa";
        this->_state = 0;
        this->_lastturn="none";
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
   
}


string Contessa::role(){
    return this->_role;
}


void Contessa::block(Player & p){
    if(p.role()!="Assassin"){
        throw std::invalid_argument( "this player cant block the other player" );
    }
    for (unsigned long i=0; i<this->_game->_player.size();i++){
        if (this->_game->_player[i]->getName()==p.getName()){
            vector<string> str;
            stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
            while(s_stream1.good()) {
                string substr;
                getline(s_stream1, substr, ','); //get first string delimited by a space
                str.push_back(substr);
            }
            if (str[2]=="coup3"){
                string n1=str[3];
                for (unsigned long j=0; j<this->_game->_player.size();j++){
                    if(this->_game->_player[j]->getName()==n1){
                        this->_game->_player[j]->setState(0); 
                        return;
                    }
                }    
            }
        }
    }
    throw std::invalid_argument( "can't block!" );
}
    
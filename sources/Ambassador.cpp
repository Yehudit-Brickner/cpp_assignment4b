
#include "Ambassador.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

using namespace coup;


Ambassador::Ambassador(Game & g, string  n): Player(g, std::move(n)){
     
}

void Ambassador::block(Player & p){
   
    if(p.role()!="Captain"){
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
            if (str[2]=="steal"){
                string n1=str[3];
                int change=stoi(str[1]);
                for (unsigned long j=0; j<this->_game->_player.size();j++){
                    if(this->_game->_player[j]->getName()==n1){
                        this->_game->_player[j]->updateCoins(change); 
                        p.updateCoins(-change);
                        return;
                    }
                }    
            }
        
        }
    }
    throw std::invalid_argument( "can't block!");
}

string Ambassador::role(){
    return "Ambassador";
}

void Ambassador::transfer(coup::Player& p1, coup::Player &p2){
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
    if(p1.coins()>=one){
        p1.updateCoins(-1);
        p2.updateCoins(1);
        string s= this->getName();
        s.append(",0,transfer,");
        s.append(p1.getName());
        s.append(",");
        s.append(p2.getName());
        this->setLastturn(s);
        this->_game->updateTurn(); 
    }
    else{
       throw std::invalid_argument( "not enough coins to transfer" );  
    }
}
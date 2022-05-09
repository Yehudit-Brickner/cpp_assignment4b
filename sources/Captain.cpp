#include "Captain.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

using namespace coup;


Captain::Captain(Game & g, string  n):Player(g,std::move(n)){
  
}

string Captain::role(){
    return "Captain";
}

void Captain::steal(coup::Player & p){
    const int ten=10; 
    const int two=2;
    const int one=1;
    this->_game->_started=true;
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
    if(p.coins()>=two){
        p.updateCoins(-2);
        this->updateCoins(2);
        string s= this->getName();
        s.append(",2,steal,");
        s.append(p.getName());
        s.append(",null");
        this->setLastturn(s);
        this->_game->updateTurn(); 
    }
    else if(p.coins()==one){
        p.updateCoins(-1);
        this->updateCoins(1);
        string s= this->getName();
        s.append(",1,steal,");
        s.append(p.getName());
        s.append(",null");
        this->setLastturn(s);
        this->_game->updateTurn();
    }
    else{
       throw std::invalid_argument( "no coins to steal" );  
    }  
}



void Captain::block(Player & p){
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
    throw std::invalid_argument( "can't block!" );
}
    
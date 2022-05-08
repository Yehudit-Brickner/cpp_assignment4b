#include "Duke.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

using namespace coup;


Duke::Duke(Game & g, string  n){
    const int six=6;
    // cout<< "this is a constructor for Duke"<< endl;
    bool canadd=g._started;
    if (g._player.size()<six && !canadd){
        this->_game = & g;
        this->_name = std::move(n);
        this->_coins = 0;
        this->_role = "Duke";
        this->_state = 0;
        this->_lastturn="none";
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
}


string Duke::role(){
    return this->_role;
}

void Duke::tax(){
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
    this->updateCoins(3);
    // cout<<"duke took tax"<<endl;
    string s= this->getName();
    s.append(",0,tax,null,null");
    
    this->setLastturn(s);
    this->_game->updateTurn(); 
}

void Duke::block(Player & p){
    // cout<< "Duke blocking Player"<<endl;
    for (unsigned long i=0; i<this->_game->_player.size();i++){
        if (this->_game->_player[i]->getName()==p.getName()){
            vector<string> str;
            stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
            while(s_stream1.good()) {
                string substr;
                getline(s_stream1, substr, ','); //get first string delimited by a space
                str.push_back(substr);
            }        
            if (str[2]=="forign_aid"){
                string n1=str[0];
                for (unsigned long j=0; j<this->_game->_player.size();j++){ 
                    if(this->_game->_player[j]->getName()==n1){
                        this->_game->_player[j]->updateCoins(-2); 
                        return;  
                    }
                }    
            }
        }
    }
    throw std::invalid_argument( "can't block!" );
}


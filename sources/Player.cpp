

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

using namespace coup;

Player::Player(Game & g, string n){
    cout<< "this is a constructor for player"<< endl;
    // bool canadd=true;
    // for (unsigned long i=0; i<g._player.size();i++){
    //     if(g._player[i]->getLastturn()!="none"){
    //         canadd=false;
    //     }
    // }
    bool canadd=g._started;
    if (g._player.size()<6 && !canadd){
        this->_game=& g;
        this->_name=n;
        this->_coins=0;
        this->_role="Player";
        this->_lastturn="none";
        g.addplayer(n);
        g._player.push_back(& *this);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
    
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
    this->_state=s;
}

void Player::setLastturn(string s){
    this->_lastturn=s;
}

string Player::getLastturn(){
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

    /*
    // cout<< "someone played block \n"<< endl;
    // if( this->role()=="Contessa" && p.role()=="Assassin"){
    //     cout<< "Contessa blocking Assassin"<<endl;
    //     for (unsigned long i=0; i<this->_game->_player.size();i++){
    //         if (this->_game->_player[i]->getName()==p.getName()){
    //             cout<<"match?"<<endl;
    //             vector<string> str;
    //             stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
    //             while(s_stream1.good()) {
    //                 string substr;
    //                 getline(s_stream1, substr, ','); //get first string delimited by a space
    //                 str.push_back(substr);
    //             }
    //             // for (unsigned long a=0; a<str.size();a++){
    //             //     cout<< str[a]<<endl;
    //             // }
    //             for (unsigned long b=0; b<str.size();b++){
    //                 if (str[b]=="coup3"){
    //                     for (unsigned long j=0; j<this->_game->_player.size();j++){
    //                         string n1=str[b+1];
    //                         string n2=str[b+1]+" "+str[b+2];
    //                         if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
    //                             this->_game->_player[j]->setState(0); 
    //                             return;
    //                         }
    //                     }    
    //                 }
    //             }
    //         }
    //     }
    // }
    // if(this->role()=="Ambassador" && p.role()=="Captain"){
    //      cout<< "Ambassador blocking Captain"<<endl;
    //     for (unsigned long i=0; i<this->_game->_player.size();i++){
    //         if (this->_game->_player[i]->getName()==p.getName()){
    //             cout<<"match?"<<endl;
    //             vector<string> str;
    //             stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
    //             while(s_stream1.good()) {
    //                 string substr;
    //                 getline(s_stream1, substr, ','); //get first string delimited by a space
    //                 str.push_back(substr);
    //             }
    //             // for (unsigned long a=0; a<str.size();a++){
    //             //     cout<< str[a]<<endl;
    //             // }
    //             for (unsigned long b=0; b<str.size();b++){
    //                 if (str[b]=="steal"){
    //                     for (unsigned long j=0; j<this->_game->_player.size();j++){
    //                         string n1=str[b+1];
    //                         string n2=str[b+1]+" "+str[b+2];
    //                         if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
    //                             this->_game->_player[j]->updateCoins(2); 
    //                             p.updateCoins(-2);
    //                             return;
    //                         }
    //                     }    
    //                 }
    //             }
    //         }
    //     }
    // }
    // else if(this->role()=="Captain" && p.role()=="Captain"){
    //      cout<< "Captain blocking Captain"<<endl;
    //     for (unsigned long i=0; i<this->_game->_player.size();i++){
    //         if (this->_game->_player[i]->getName()==p.getName()){
    //             cout<<"match?"<<endl;
    //             vector<string> str;
    //             stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
    //             while(s_stream1.good()) {
    //                 string substr;
    //                 getline(s_stream1, substr, ','); //get first string delimited by a space
    //                 str.push_back(substr);
    //             }
    //             // for (unsigned long a=0; a<str.size();a++){
    //             //     cout<< str[a]<<endl;
    //             // }
    //             for (unsigned long b=0; b<str.size();b++){
    //                 if (str[b]=="steal"){
    //                     for (unsigned long j=0; j<this->_game->_player.size();j++){
    //                         string n1=str[b+1];
    //                         string n2=str[b+1]+" "+str[b+2];
    //                         if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
    //                             this->_game->_player[j]->updateCoins(2); 
    //                             p.updateCoins(-2);
    //                             return;
    //                         }
    //                     }    
    //                 }
    //             }
    //         }
    //     }
    // }
    // else if(this->role()=="Duke" ){
    //     cout<< "Duke blocking Player"<<endl;
    //     for (unsigned long i=0; i<this->_game->_player.size();i++){
    //         if (this->_game->_player[i]->getName()==p.getName()){
    //             cout<<"match?"<<endl;
    //             vector<string> str;
    //             stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
    //             while(s_stream1.good()) {
    //                 string substr;
    //                 getline(s_stream1, substr, ','); //get first string delimited by a space
    //                 str.push_back(substr);
    //             }
    //             // for (unsigned long a=0; a<str.size();a++){
    //             //     cout<< str[a]<<endl;
    //             // }
    //             for (unsigned long b=0; b<str.size();b++){
    //                 if (str[b]=="forign_aid"){
    //                     for (unsigned long j=0; j<this->_game->_player.size();j++){
    //                         string n1=str[0];
    //                         string n2=str[0]+" "+str[1];
    //                         if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
    //                             this->_game->_player[j]->updateCoins(-2); 
    //                             return;  
    //                         }
    //                     }    
    //                 }
    //             }
    //         }
    //     }
    // }
   */
    throw std::invalid_argument( "this player cant block the other player" );     
}



string Player::role(){
    return this->getName();
}


void Player::coup(coup::Player & p){
    const int  money1=7;
    const int money2=3;
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
    if( found==false){
       throw std::invalid_argument( "player not in game" ); 
    }

    // cout << "a player is trying to coup. the player has " << this->_coins << " coins"<<endl;
   

    if (this->_coins<money1){
        throw std::invalid_argument( "cant pay 7 coins" );  
    }

    p.setState(2);
    cout<<"the assigned player state is "<< p._state <<endl;
    string s= this->getName();
    s.append(",0,coup7,");
    s.append(p.getName());
    s.append(",null");
    this->setLastturn(s);
    this->updateCoins(-7);
    this->_game->updateTurn(); 
    }



// bool Player::operator== (const Player & p )const{
//     return (this->_name==p._name && this->_role==p._role);
// }
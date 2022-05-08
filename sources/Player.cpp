

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

using namespace coup;

Player::Player(Game & g, string n){
    cout<< "this is a constructor for player"<< endl;
    if (g._player.size()<6){
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

    // cout<<"income"<<endl;
    updateCoins(1);
    string s= this->getName();
    s.append(" 0 income null null");
    this->setLastturn(s);
    // cout<<"added a coin"<<endl;
    // Turn t1{*this, 0,"income"};
    // this->_game->gameTurns.push(&t1);
    // this->_game->_gameTurns.push_back(&t1);
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
    
    cout<<"forign_aid"<<endl;
    updateCoins(2);
    cout<<"added 2 coins"<<endl;
    string s= this->getName();
   
    s.append(" 0 forign_aid null null");
    this->setLastturn(s);
    // Turn t2{*this, 0,"forign_aid"};
    // this->_game->gameTurns.push(&t2);
    // this->_game->_gameTurns.push_back(&t2);
    this->_game->updateTurn();
}


void Player::block(coup::Player & p){
    
    cout<< "someone played block \n"<< endl;
    if( this->role()=="Contessa" && p.role()=="Assassin"){
        cout<< "Contessa blocking Assassin"<<endl;
        for (unsigned long i=0; i<this->_game->_player.size();i++){
            if (this->_game->_player[i]->getName()==p.getName()){
                cout<<"match?"<<endl;
                vector<string> str;
                stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
                while(s_stream1.good()) {
                    string substr;
                    getline(s_stream1, substr, ' '); //get first string delimited by a space
                    str.push_back(substr);
                }
                // for (unsigned long a=0; a<str.size();a++){
                //     cout<< str[a]<<endl;
                // }
                for (unsigned long b=0; b<str.size();b++){
                    if (str[b]=="coup3"){
                        for (unsigned long j=0; j<this->_game->_player.size();j++){
                            string n1=str[b+1];
                            string n2=str[b+1]+" "+str[b+2];
                            if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
                                this->_game->_player[j]->setState(0); 
                                return;
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(this->role()=="Ambassador" && p.role()=="Captain"){
         cout<< "Ambassador blocking Captain"<<endl;
        for (unsigned long i=0; i<this->_game->_player.size();i++){
            if (this->_game->_player[i]->getName()==p.getName()){
                cout<<"match?"<<endl;
                vector<string> str;
                stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
                while(s_stream1.good()) {
                    string substr;
                    getline(s_stream1, substr, ' '); //get first string delimited by a space
                    str.push_back(substr);
                }
                // for (unsigned long a=0; a<str.size();a++){
                //     cout<< str[a]<<endl;
                // }
                for (unsigned long b=0; b<str.size();b++){
                    if (str[b]=="steal"){
                        for (unsigned long j=0; j<this->_game->_player.size();j++){
                            string n1=str[b+1];
                            string n2=str[b+1]+" "+str[b+2];
                            if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
                                this->_game->_player[j]->updateCoins(2); 
                                p.updateCoins(-2);
                                return;
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(this->role()=="Captain" && p.role()=="Captain"){
         cout<< "Captain blocking Captain"<<endl;
        for (unsigned long i=0; i<this->_game->_player.size();i++){
            if (this->_game->_player[i]->getName()==p.getName()){
                cout<<"match?"<<endl;
                vector<string> str;
                stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
                while(s_stream1.good()) {
                    string substr;
                    getline(s_stream1, substr, ' '); //get first string delimited by a space
                    str.push_back(substr);
                }
                // for (unsigned long a=0; a<str.size();a++){
                //     cout<< str[a]<<endl;
                // }
                for (unsigned long b=0; b<str.size();b++){
                    if (str[b]=="steal"){
                        for (unsigned long j=0; j<this->_game->_player.size();j++){
                            string n1=str[b+1];
                            string n2=str[b+1]+" "+str[b+2];
                            if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
                                this->_game->_player[j]->updateCoins(2); 
                                p.updateCoins(-2);
                                return;
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(this->role()=="Duke" ){
        cout<< "Duke blocking Player"<<endl;
        for (unsigned long i=0; i<this->_game->_player.size();i++){
            if (this->_game->_player[i]->getName()==p.getName()){
                cout<<"match?"<<endl;
                vector<string> str;
                stringstream s_stream1(this->_game->_player[i]->getLastturn()); //create string stream from the string
                while(s_stream1.good()) {
                    string substr;
                    getline(s_stream1, substr, ' '); //get first string delimited by a space
                    str.push_back(substr);
                }
                // for (unsigned long a=0; a<str.size();a++){
                //     cout<< str[a]<<endl;
                // }
                for (unsigned long b=0; b<str.size();b++){
                    if (str[b]=="forign_aid"){
                        for (unsigned long j=0; j<this->_game->_player.size();j++){
                            string n1=str[0];
                            string n2=str[0]+" "+str[1];
                            if(this->_game->_player[j]->getName()==n1 || this->_game->_player[j]->getName()==n2){
                                this->_game->_player[j]->updateCoins(-2); 
                                return;  
                            }
                        }    
                    }
                }
            }
        }
    }
   
    throw std::invalid_argument( "this player cant block the other player" ); 
    
        // int start=(int)this->_game->_gameTurns.size()-1;
        // int size=(int)this->_game->_player.size();
        // int end=start-size;
        // if(end<0){
        //     end=0;
        // }
        // cout<< "start and end "<< start<<  "  "<< end<< endl;
        
        // for (unsigned long i=(unsigned long)start; i > (unsigned long)end;i--){
        //     cout<<i<<endl;
            // if(this->_game->_gameTurns[i]->_blocked==false ){
            //     cout<<"hasnt been blocked yet"<<endl;
            //     cout<<this->_game->_gameTurns[i]->_action<<endl;
            //     if( this->_game->_gameTurns[i]->_action=="coup3"){
            //         cout<<"matched action"<<endl;
            //         // cout<< this->_game->_gameTurns[i]->_action<<endl;
            //         if((this->_game->_gameTurns[i]->_whoPlayed)==p){
            //             cout<< "matched player"<<endl;
            //             // vector<Player*> play=this->_game->_gameTurns[i]->getDoneTo();
            //             // play[0]->setState(0);
            //             this->_game->_gameTurns[i]->_doneto1.setState(0);
            //             this->_game->_gameTurns[i]->setBlocked(true);
            //             cout<<"blocked"<<endl;
            //         } 
            //     }
            // }
        // }
    
}



string Player::role(){
    return this->getName();
}


void Player::coup(coup::Player & p){
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
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

    cout << "a player is trying to coup. the player has " << this->_coins << " coins"<<endl;
    const int  money1=7;
    const int money2=3;

    
    // if (this->_role=="assassin"){
    //     if(this->_coins>=money1){
    //         cout<<"Assasin coup7"<<endl;
    //         this->updateCoins(-7);
    //         p.setState(2);
    //         string s= this->getName();
    //         s.append(" 0 coup7 ");
    //         s.append(p.getName());
    //         s.append(" null");
    //         this->setLastturn(s);
    //         // vector<Player*> v1={&p};
    //         // Turn t1{*this, 0,"coup7",p};
    //         // this->_game->gameTurns.push(&t1);
    //         // this->_game->_gameTurns.push_back(&t1);
    //         this->_game->updateTurn();     
    //     }
    //     if(this->_coins<money2){
    //         throw std::invalid_argument( "cant pay 3 coins" ); 
    //     }
    //     cout<<"Assasin coup3"<<endl;
    //     this->updateCoins(-3);
    //     p.setState(1);
    //     string s= this->getName();
    //     s.append(" 0 coup3 ");
    //     s.append(p.getName());
    //     s.append(" null");
    //     this->setLastturn(s);
    //     // vector<Player*> v1={&p};
    //     // Turn t1{*this,0, "coup3",p};
    //     // this->_game->gameTurns.push(&t1);
    //     // this->_game->_gameTurns.push_back(&t1);
    //     this->_game->updateTurn(); 

    // }
    // else{
        if (this->_coins<money1){
            throw std::invalid_argument( "cant pay 7 coins" );  
        }
    
        p.setState(2);
        cout<<"the assigned player state is "<< p._state <<endl;
        string s= this->getName();
        s.append(" 0 coup7 ");
        s.append(p.getName());
        s.append(" null");
        this->setLastturn(s);
        // vector<Player*> v1={&p};
        // Turn t1{*this, 0,"coup", p};
        // this->_game->gameTurns.push(&t1);
        // this->_game->_gameTurns.push_back(&t1);
        this->updateCoins(-7);
        this->_game->updateTurn(); 
    }
// }


bool Player::operator== (const Player & p )const{
    return (this->_name==p._name && this->_role==p._role);
}
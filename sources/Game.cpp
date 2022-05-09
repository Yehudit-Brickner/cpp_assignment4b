

#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <queue>

using namespace coup;

    Game::Game(){
        std:: vector<coup::Player*> _player;
        _turn = 0;
        _started=false;   
    }

    // uodate who is playing
    void Game::updateTurn(){    
        int s=1;
        while (s!=0){
            this->_turn=(this->_turn+1)%(int)this->_player.size();
            s=this->_player[(unsigned long)this->_turn]->_state;
            if(s==1){
                int el=this->_turn;
                this->_player.erase(this->_player.begin() + el);
                this->_turn=(this->_turn-1)%(int)this->_player.size();
            }
            if(s==2){
                int el=this->_turn;
                this->_player.erase(this->_player.begin() + el);
                this->_turn=(this->_turn-1)%(int)this->_player.size();
            }
        }
    }
 
    // make a vector of the players name
    std::vector<string> Game::players(){
        std::vector<string> aliveplayers;
        for (unsigned long i=0;i<this->_player.size();i++){
            if(this->_player[i]->_state==0){
                aliveplayers.push_back(this->_player[i]->_name);
            }
        }
        return aliveplayers;
    }

    // return whos turn it is
    string Game::turn(){
        unsigned long t=(unsigned long)this->_turn;
        vector<string> p=this->players();
        return p[t];        
    }

     // return the winners name
    string Game::winner(){
        // cout<<"checking if there is a winner"<<endl;
        if (this ->_player.size()==1 && this->_started){
            return this->_player[0]->getName();
        }
        throw std::invalid_argument( "there is no winner" ); 
    }

  
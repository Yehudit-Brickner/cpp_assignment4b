

#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <queue>

using namespace coup;

    Game::Game(){
        std:: vector<coup::Player*> _player;
        std:: vector<string> _p; 
        _turn = 0;
        // queue<Turn> gameTurns;
        std::vector<Turn*> _gameTurns;
        
        
    }

    void Game::print(){
        for (unsigned long i=0; i<this->_p.size();i++){
            // cout<< this->_p[i].getName() << "  ";
            cout<< _p[i]<< "   "<< endl;
        }
        cout << " "<<endl;
    }



    void Game::addplayer(string const s){
        int const max_player=6;
        if(_p.size()<max_player){
            _p.push_back(s);
        }
        // throw std::invalid_argument( "too many players" ); 
    }


    // void Game::setTurn(int t){
    //     cout<<"new turn="<< t<<endl;
    //     int size=this->_p.size();
    //     cout<< "size=" << size<<endl;
    //     this->_turn=t%size;
    // }


    void Game::updateTurn(){    
        cout<<"state of old player "<<this->_player[(unsigned long)this->_turn]->_state<< endl; 
        cout<< "address of old player "<< this->_player[(unsigned long)this->_turn]<<endl;       
        this->_turn=(this->_turn+1)%(int)this->_player.size();
        cout<<"state of new player "<<this->_player[(unsigned long)this->_turn]->_state<< endl;
        cout<< "address of new player "<< this->_player[(unsigned long)this->_turn]<<endl;
    }

 

    
 
    // make a vector of the players name
    std::vector<string> Game::players(){
        return this->_p;

    }

    string Game::turn(){
        int t=this->_turn;
        unsigned long tu=(unsigned long)this->_turn;
        vector<string> p=this->players();
        return p[tu];        
    }

    string Game::winner(){
        // if (this ->_p.size()==1){
        //     return this->_p[0].getName();
        // }
        // else{
        //     //throw exception
        // }
        return "string";
    }
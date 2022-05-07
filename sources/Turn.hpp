#pragma once
#include "Player.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace coup {
    class Player;  
    class Turn{
        public:
        
        Player * _whoPlayed;
        int coins_stolen;
        string _action;
        std::vector<Player*> _doneTo;
        bool _blocked; 

        Turn(Player & p, int c, string s, vector<Player*> v);
        Turn(Player & p, int c, string s);
        // Turn(const Turn &o);
        ~Turn(){}
        Player* getPlayer();
        int getCoins_stolen();
        string getAction();
        std::vector<Player*> getDoneTo();
        bool getBlocked();

        void setBlocked(bool b);
        void print();
       
    };
}
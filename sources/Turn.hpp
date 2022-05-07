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
        // std::vector<Player*> _doneTo;
        Player * _doneto1;
        Player * _doneto2;
        bool _blocked; 

        Turn(Player & p, int c, string s, Player & d1, Player & d2);
        Turn(Player & p, int c, string s, Player & d1);
        Turn(Player & p, int c, string s);
        // Turn(const Turn &o);
        ~Turn(){}
        Player* getPlayer();
        int getCoins_stolen();
        string getAction();
        // std::vector<Player*> getDoneTo();
        Player* getDoneto1();
        Player* getDoneto2();
        bool getBlocked();

        void setBlocked(bool b);
        void print();
       
    };
}
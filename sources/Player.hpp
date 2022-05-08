
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;

namespace coup {
    class Game;

    class Player {
        public:
            int _coins;
            coup::Game* _game;
            string _name;
            string _role;
            int _state;
            string _lastturn;
        
            //constructers
            Player(coup::Game & g, string n);
            Player();
            ~Player(){}
            
            int coins();
            void updateCoins(int u);
            void updateTurn();
            string getName();
            int getCoins();
            virtual string role();
            void income();
            void foreign_aid(); 
            void virtual coup(Player & p);
            void virtual block(Player & p);
            void setState(int s);
            void setLastturn(string s);
            string getLastturn();
            void print();
            bool operator==(const Player & m ) const;
    };

}








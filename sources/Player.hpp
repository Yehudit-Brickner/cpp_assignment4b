
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
            int _state;
            string _lastturn;
        
            //constructers
            Player(coup::Game & g, string  n);
            
            int coins() const;
            void updateCoins(int u);
            void updateTurn();
            string getName()const;
            int getCoins()const;
            virtual string role();
            void income();
            void foreign_aid(); 
            void virtual coup(Player & p);
            void virtual block(Player & p);
            void setState(int s);
            void setLastturn(string s) ;
            string getLastturn()const;
            void print();
            bool operator==(const Player & m ) const;
    };

}








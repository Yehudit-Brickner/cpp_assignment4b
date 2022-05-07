
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Turn.hpp"

using namespace std;

namespace coup {
    class Game;
    class Turn;

    class Player {
        public:
            int _coins;
            coup::Game* _game;
            string _name;
            string _role;
            int _state;
        
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
            void virtual coup(Player p) ;
            // void virtual block(Player p);
            void setState(int s);
            void print();
    };



   

    class Assassin : public Player{

        public:
            Assassin(Game & g, string n);
            ~Assassin(){}     
            void coup(Player p) override;
            string role() override;
    };

     class Duke : public Player {

        public:
            Duke(Game & g, string n);
            ~Duke(){} 
            void tax();
            void block(coup::Player p);
            string role() override;
    };   

    class Captain : public Player{

        public:
            Captain(Game & g, string n);
            ~Captain(){}  
            void steal(coup::Player p);
            void block(coup::Captain c);
            // void block(coup:: Duke d);
            string role() override;
    };
    
     class Ambassador : public Player{

        public: 
            Ambassador(Game & g, string n);
            ~Ambassador(){}              
            void block(coup::Captain c);
            void transfer(coup::Player p1, coup::Player p2);
            string role() override;
    
    };

    class Contessa : public Player{

       public:
            Contessa(Game & g, string n);      
            ~Contessa(){} 
            void block(coup::Assassin a);
            string role() override;
            
    };

    

}








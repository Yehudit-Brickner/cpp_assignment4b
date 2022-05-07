#pragma once
#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup{
//     class Ambassador : public Player{


//     public: 
//         // int _coins;
//         // Game _game;
//         // string _name; 


//         //constructer
//         Ambassador(Game g, string n);
                        

//         void income();
//         int coins();
//         void foreign_aid();
//         void block(Player p);
//         void coup(Player p);
//         void transfer(Player p1, Player p2);
    
//     };
// }
 class Ambassador : public Player{

        public: 
            Ambassador(Game & g, string n);
            ~Ambassador(){}              
            // void block(coup::Captain c);
            void transfer(coup::Player p1, coup::Player p2);
            string role() override;
    
    };
}
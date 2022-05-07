#pragma once
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup{
//     class Duke : public Player {


//         public:

//             // int _coins;
//             // Game _game;
//             // string _name;

//             //constructer
//             Duke(Game g, string n);
        
//             void income();
//             int coins();
//             void foreign_aid();
//             void block(Player p);
//             void coup(Player p);
//             void tax();
//     };
// }
class Duke : public Player {

        public:
            Duke(Game & g, string n);
            ~Duke(){} 
            void tax();
            // void block(coup::Player p) override;
            string role() override;
    };   
}
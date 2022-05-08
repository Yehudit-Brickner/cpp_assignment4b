#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup{
//     class Captain : public Player{


//         public:

//             // int _coins;
//             // Game _game;
//             // string _name;

//             //constructer
//             Captain(Game g, string n);
               
//             void income();
//             int coins();
//             void foreign_aid();
//             void block(Duke d);
//             void coup(Player p);
//             void steal(Player p);
//     };
// }
  class Captain : public Player{

        public:
            Captain(Game & g, string n);
            ~Captain(){}  
            void steal(coup::Player & p);
            void block(coup::Player & p)override;
            string role() override;
    };
}
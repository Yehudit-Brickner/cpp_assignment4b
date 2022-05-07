#pragma once

#include "Player.hpp"

using namespace std;

namespace coup{
//     class Assassin : public Player{

//         public:

//             // int _coins;
//             // Game _game;
//             // string _name;

//             //constructer
//             Assassin(Game g, string n);
                
//             void income();
//             int coins();
//             void foreign_aid();
//             void block(Player p);
//             void coup(Player p);
//             void coup(Player p);
//     };
// }
class Assassin : public Player{

        public:
            Assassin(Game & g, string n);
            ~Assassin(){}     
            void coup(Player & p) override;
            string role() override;
    };
}
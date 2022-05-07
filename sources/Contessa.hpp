#pragma once
#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup{
//     class Contessa : public Player{

//        public:
//             // int _coins;
//             // Game _game;
//             // string _name;
    
//            //constructer
//             Contessa(Game g, string n);      

//             void income();
//             int coins();
//             void foreign_aid();
//             void coup(Player p);
//             void block(Assassin a);
            
//     };
// }
 class Contessa : public Player{

       public:
            Contessa(Game & g, string n);      
            ~Contessa(){} 
            // void block(coup::Assassin a);
            string role() override;
            
    };
}

#pragma once
#include "Player.hpp"
#include "Assassin.hpp"

using namespace std;

namespace coup{
 class Contessa : public Player{

       public:
            Contessa(Game & g, string n);      
            ~Contessa(){} 
            void block(coup::Player & ) override;
            string role() override;
            
    };
}

#pragma once
#include "Player.hpp"

using namespace std;

namespace coup{
 class Contessa : public Player{

       public:
            Contessa(Game & g, string  n);      
            void block(coup::Player & ) override;
            string role() override;
            
    };
}

#pragma once
#include <iostream>
#include "Player.hpp"
#include "Captain.hpp"

using namespace std;

namespace coup{

 class Ambassador : public Player{

        public: 
            Ambassador(Game & g, string  n);              
            void block(Player & p) override;
            void transfer(coup::Player & p1, coup::Player & p2);
            string role() override;
    
    };
}
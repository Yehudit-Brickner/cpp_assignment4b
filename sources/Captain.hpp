#pragma once

#include "Player.hpp"
#include "Duke.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup{

  class Captain : public Player{
        public:
            Captain(Game & g, string  n);
            ~Captain(){}  
            void steal(coup::Player & p);
            void block(coup::Player & p)override;
            string role() override;
    };
}
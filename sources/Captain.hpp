#pragma once

#include "Player.hpp"
using namespace std;

namespace coup{

  class Captain : public Player{
        public:
            Captain(Game & g, string  n); 
            void steal(coup::Player & p);
            void block(coup::Player & p)override;
            string role() override;
    };
}
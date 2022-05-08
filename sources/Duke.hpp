#pragma once
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup{
class Duke : public Player {

        public:
            Duke(Game & g, string n);
            ~Duke(){} 
            void tax();
            void block(coup::Player & p) override;
            string role() override;
    };   
}
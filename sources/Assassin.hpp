#pragma once
#include "Player.hpp"

using namespace std;

namespace coup{
class Assassin : public Player{
        public:
            Assassin(Game & g, string  n);    
            void coup(Player & p) override;
            string role() override;
    };
}
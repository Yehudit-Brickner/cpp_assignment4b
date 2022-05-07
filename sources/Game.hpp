
#pragma once
#include "Player.hpp"
#include "Turn.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <queue>



using namespace std;

namespace coup {
    class Player;
    class Turn;
    class Game {
        

        public:
        std:: vector<coup::Player*> _player;
        std:: vector<string> _p;
        int _turn;
        // queue<Turn> gameTurns;
        std:: vector<coup::Turn*>_gameTurns;

        //constructer
        Game();
        ~Game(){}
       
        void addplayer(string const s);

        void print();

        // void setTurn(int t);

        void updateTurn();     
        

        // return a vector of the players name
        std::vector<string> players();

        // return whos turn it is
        string turn();

        // return the winners name
        string winner();


    };
}

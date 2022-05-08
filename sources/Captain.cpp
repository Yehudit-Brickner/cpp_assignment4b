#include "Captain.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Captain::Captain(Game & g, string n){
    cout<< "this is a constructor for Captain"<< endl;
    if (g._player.size()<6){
        this->_game=& g;
        this->_name=n;
        this->_coins=0;
        this->_role="Captain";
        this->_state = 0;
        this->_lastturn="none";
        g._player.push_back(& *this);
        g.addplayer(n);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
}

string Captain::role(){
    return this->_role;
}

void Captain::steal(coup::Player & p){
    const int ten=10; 
    const int two=2;
    const int one=1;
    unsigned long turnn=(unsigned long)this->_game->_turn;
    if(this->_game->_player[turnn]!=this){
         throw std::invalid_argument( "not your turn!" ); 
    }
    if(this->_coins>=ten){
        throw std::invalid_argument( "you have to do coup!" );  
    }
    if(this->_game->_player.size()<=one){
      throw std::invalid_argument( "cant play with 1 player or less!" );    
    }
    if(p.coins()>=two){
        p.updateCoins(-2);
        this->updateCoins(2);
        string s= this->getName();
        s.append(" 2 steal ");
        s.append(p.getName());
        s.append(" null");
        this->setLastturn(s);
        this->_game->updateTurn(); 
    }
    else if(p.coins()==one){
        p.updateCoins(-1);
        this->updateCoins(1);
        string s= this->getName();
        s.append(" 1 steal ");
        s.append(p.getName());
        s.append(" null");
        this->setLastturn(s);
        this->_game->updateTurn();
    }
    else{
       throw std::invalid_argument( "no coins to steal" );  
    }
    
    // vector<Player*> v1={&p};
    // Turn t1{*this,2, "steal",p};
    // this->_game->gameTurns.push(&t1);
    // this->_game->_gameTurns.push_back(&t1);
    
}


// void Captain::block(coup::Captain c){
//     int start=(int)this->_game->_gameTurns.size()-1;
//     int size=(int)this->_game->_player.size();
//     int end=start-size;
//     if(end<0){
//         end=0;
//     }
//     for (unsigned long i=(unsigned long)start; i > (unsigned long) end;i--){
//         if(this->_game->_gameTurns[i]->getPlayer()==&c and this->_game->_gameTurns[i]->getAction()=="steal" and this->_game->_gameTurns[i]->getBlocked()==false ){
//            cout<<"blocked"<<endl;
//            vector<Player*> p=this->_game->_gameTurns[i]->getDoneTo();
//            p[0]->updateCoins(2);
//            c.updateCoins(-2);
//            this->_game->_gameTurns[i]->setBlocked(true);
//         }
//     }
// }

// void Captain::block(coup::Duke d){
//     cout<<"blocked"<<endl;
//     // unsigned long start=this->_game->_gameTurns.size()-1;
//     // unsigned long size=this->_game->_player.size();
//     // for (unsigned long i=start; i > start-size;i--){
//     //     if(this->_game->_gameTurns[i].getPlayer()==&d and this->_game->_gameTurns[i].getAction()=="foreign_aid" and this->_game->_gameTurns[i].getBlocked()==false ){
//     //        cout<<"blocked"<<endl;
//     //        vector<Player*> p=this->_game->_gameTurns[i].getDoneTo();
//     //        p[0]->updateCoins(-2);
//     //     }
//     // }
// }
#include "Duke.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

using namespace coup;


Duke::Duke(Game & g, string n){
    cout<< "this is a constructor for Duke"<< endl;
    if (g._player.size()<6){
        this->_game = & g;
        this->_name = n;
        this->_coins = 0;
        this->_role = "Duke";
        this->_state = 0;
        this->_lastturn="none";
        g._player.push_back(& *this);
        g.addplayer(n);
    }
    else{
       throw std::invalid_argument( "too many players!" );  
    }
}


string Duke::role(){
    return this->_role;
}

void Duke::tax(){
    const int ten=10; 
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
    this->updateCoins(3);
    cout<<"duke took tax"<<endl;
    string s= this->getName();
    s.append(" 0 tax null null");
    
    this->setLastturn(s);
    // Turn t1{*this,0, "tax"};
    // this->_game->gameTurns.push(&t1);
    // this->_game->_gameTurns.push_back(&t1);
    this->_game->updateTurn(); 
}


// void Duke::block(Player pl){
//     cout<<"enter block"<<endl;
//     int start=(int)this->_game->_gameTurns.size()-1;
//     int size=(int)this->_game->_player.size()-1;
//     int end=start-size;
//     if(end<0){
//         end=0;
//     }
//     cout<< "start= "<< start<< " end= "<< end <<endl;
//     unsigned long s =(unsigned long) start;
//     unsigned long e =(unsigned long) end;
//     cout<< "s= "<< s<< " e= "<< e <<endl;
//     for (unsigned long i=s; i >= e; i--){
//         cout<< "i= "<<i<< endl;
        
//         // cout<<"who played  "<< (this->_game->_gameTurns[i]->_whoPlayed)<<endl;
//         cout<<this->_game->_gameTurns[i]->_whoPlayed<<endl;
//         if(this->_game->_gameTurns[i]->_action=="forign_aid"){
//             cout<< "correct action"<<endl;
//             if(this->_game->_gameTurns[i]->_blocked==false){
//                 cout<< "turn has not been blocked"<<endl;
//             }
//         }

//         // if(this->_game->_gameTurns[i]->getPlayer()==&pl && this->_game->_gameTurns[i]->getAction()=="forign_aid" && this->_game->_gameTurns[i]->getBlocked()==false ){
//         //    cout<<"blocked"<<endl;
//         //    vector<Player*> p=this->_game->_gameTurns[i]->getDoneTo();
//         //    cout<< "captain2 has "<< p[0]->coins() << " coins"<<endl;
//         //    p[0]->updateCoins(-2);
//         //    cout<< "captain2 has "<< p[0]->coins() << " coins"<<endl;

//         // }
//     }         
// }
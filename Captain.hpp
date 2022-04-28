//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_CAPTAIN_H
#define COUP_A_CAPTAIN_H

#include "Player.hpp"
#include <string>
#include "Game.hpp"
namespace coup{

    using namespace std;
    class Captain : public  Player{
    public:
        Captain(const Game &A,const string &B);
        void steal(Player &player);
        void block(Player &Captain);



    };
}
#endif //COUP_A_CAPTAIN_H

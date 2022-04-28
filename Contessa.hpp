//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_CONTESSA_H
#define COUP_A_CONTESSA_H

#include "Player.hpp"
#include <string>
#include "Game.hpp"
namespace coup{

    using namespace std;
    class Contessa : public Player{
    public:
        Contessa(const Game &A, const string &B);
        void block(Player &assassin);
    };
}


#endif //COUP_A_CONTESSA_H

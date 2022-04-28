//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_ASSASSIN_H
#define COUP_A_ASSASSIN_H
#include "Player.hpp"
#include "Game.hpp"
namespace coup{

    using namespace std;
    class Assassin : public Player {
    public:
        Assassin(const Game &A, const string &B);

    };
}

#endif //COUP_A_ASSASSIN_H

//
// Created by USER on 25/04/2022.
//

#ifndef COUP_A_AMBASSADOR_H
#define COUP_A_AMBASSADOR_H
#include "Player.hpp"

using namespace std;
namespace coup{

    class Ambassador: public Player {
    public:
        Ambassador(const Game &A, const string &B);

        void block(Player &Captain);

        void transfer(Player &A, Player &B);
    };
}
#endif //COUP_A_AMBASSADOR_H

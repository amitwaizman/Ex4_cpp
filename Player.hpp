#ifndef COUP_A_PLAYER_H
#define COUP_A_PLAYER_H
#include "Game.hpp"
#include <string>
using namespace std;
namespace coup{

    class Player{
    public:
        Player(const Game &A, const string &B);
        void income();
       void foreign_aid();
       void coup(Player &player);
       static string role();
       static int coins();
    };
}

#endif //COUP_A_PLAYER_H

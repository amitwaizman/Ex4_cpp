

#ifndef COUP_A_DUKE_H
#define COUP_A_DUKE_H
#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup{

    using namespace std;
    class Duke : public Player {
    public:
        Duke(const Game &A, const string &B);
        void block(Player &player);
        void tax();
    };

}
#endif //COUP_A_DUKE_H

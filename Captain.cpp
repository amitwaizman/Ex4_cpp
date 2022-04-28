#include "Captain.hpp"
using namespace std;
namespace coup {

    Captain::Captain(const Game &A, const string &B):Player::Player(A,B){}

    void Captain::block(Player &captain) {}

    void Captain::steal(Player &player) {}
}

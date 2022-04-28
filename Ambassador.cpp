#include "Ambassador.hpp"
using namespace std;
namespace coup {

    Ambassador::Ambassador(const Game &A, const string &B):Player::Player(A,B){}


    void Ambassador::block(Player &captain) {}

    void Ambassador::transfer(Player &A, Player &B) {}


}
#include "Contessa.hpp"
using namespace std;
namespace coup {

    Contessa::Contessa(const Game &A, const string &B):Player::Player(A,B){}
    void Contessa::block(Player &assassin) {}
}
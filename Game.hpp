#ifndef COUP_A_GAME_H
#define COUP_A_GAME_H
#include <vector>
#include <string>
using namespace std;
namespace coup {
    class Game {
    public:
        string static turn();
        vector <string> static players();
        static string winner();
    };
}
#endif //COUP_A_GAME_H

#include "doctest.h"
#include <string>
#include <algorithm>

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace std;
using namespace coup;

    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};


    Game game_2{};
    Assassin assassin2{game_2, "amit"};
    Ambassador ambassador2{game_2, "yarin"};
    Duke duke2{game_2, "yovel"};

    Game game_3{};
    Assassin assassin3{game_2, "amit"};
    Duke duke3{game_3, "yovel"};

    Game game_4{};
    Duke duke4{game_4, "a"};
    Contessa contessa4{game_4, "Gilad"};

Game game_5{};
Duke duke5{game_5, "a"};
Captain captain5{game_5, "Reut"};
Contessa contessa5{game_5, "Gilad"};

TEST_CASE("Good input") {
    SUBCASE("income"){
            CHECK_NOTHROW(duke.income());
            CHECK_NOTHROW(assassin.income());
            CHECK_NOTHROW(ambassador.income());
            CHECK_NOTHROW(captain.income());
            CHECK_NOTHROW(contessa.income());
    }

    SUBCASE("foreign_aid"){
            CHECK_NOTHROW(duke.foreign_aid());
            CHECK_NOTHROW(assassin.foreign_aid());
            CHECK_NOTHROW(ambassador.foreign_aid());
            CHECK_NOTHROW(captain.foreign_aid());
            CHECK_NOTHROW(contessa.foreign_aid());
        }
     SUBCASE("block"){
            // foreign_aid
            duke.income();
            assassin.foreign_aid();
            ambassador.income();
            captain.income();
            contessa.income();
            CHECK_NOTHROW(duke.block(assassin));

            assassin2.foreign_aid();
            ambassador2.income();
            CHECK_NOTHROW(duke2.block(assassin2));

        }

        SUBCASE("coup") {
            assassin3.foreign_aid();
            duke3.foreign_aid();
            assassin3.foreign_aid();
            duke3.foreign_aid();
            CHECK_NOTHROW(assassin3.coup(duke3));

        }

        SUBCASE("Steal") {
            duke.foreign_aid();
            assassin.foreign_aid();
            ambassador.foreign_aid();
            CHECK_NOTHROW(captain.steal(duke));
        }

        SUBCASE("tax") {
            duke4.foreign_aid();
            CHECK_NOTHROW(duke4.tax());
        }

        SUBCASE("winner") {
            assassin3.foreign_aid();
            duke3.foreign_aid();
            assassin3.foreign_aid();
            duke3.income();
            assassin3.coup(duke3);
            CHECK_NOTHROW(game_3.winner());
        }

        SUBCASE("transfer") {
            assassin2.income();
            ambassador2.income();
            duke2.income();
            assassin2.income();
            CHECK_NOTHROW(ambassador2.transfer(assassin2,duke2));
        }


    }

    TEST_CASE("Bad input") {
        SUBCASE("Not your turn"){
            duke.income();
            assassin.income();
            //income
            CHECK_THROWS( duke.income());
            CHECK_THROWS( contessa.income());

            CHECK_THROWS( contessa4.income());
            CHECK_THROWS( duke4.income());

            CHECK_THROWS( captain5.income());
            CHECK_THROWS( contessa5.income());

             assassin2.income();
            //foreign_aid
            CHECK_THROWS( assassin2.foreign_aid());
            CHECK_THROWS( duke2.foreign_aid());



        }

        SUBCASE("Can not block"){
            duke.foreign_aid();
            ambassador.foreign_aid();
            CHECK_THROWS( contessa.block(duke));
            CHECK_THROWS( captain.block(ambassador));

            duke4.foreign_aid();
            CHECK_THROWS( contessa4.block(duke4));

        duke5.foreign_aid();
        captain5.foreign_aid();
        CHECK_THROWS( contessa5.block(duke4));




    }

        SUBCASE("coup"){
            duke.income();
            assassin.income();
            ambassador.income();
            captain.income();
            contessa.income();
            //There are not enough coins
            CHECK_THROWS( duke.coup(ambassador));
            CHECK_THROWS( assassin.coup(captain));

            duke4.foreign_aid();
            contessa4.foreign_aid();
            duke4.foreign_aid();
            contessa4.foreign_aid();
            duke4.foreign_aid();
            contessa4.foreign_aid();
            duke4.foreign_aid();
            contessa4.foreign_aid();
            duke4.foreign_aid();
            contessa4.foreign_aid();
           //must to do coup, 10 coins
            CHECK_THROWS( duke4.income());




        }

        SUBCASE("Steal"){
            duke.income();
            assassin.income();
            ambassador.income();
            //There are not enough coins
            CHECK_THROWS(captain.steal(duke));
            CHECK_THROWS(captain5.steal(duke5));

    }
        SUBCASE("winner"){
            duke.income();
            assassin.income();
            CHECK_THROWS(game_1.winner());

            assassin3.foreign_aid();
            duke3.foreign_aid();
            CHECK_THROWS(game_3.winner());

           CHECK_THROWS(game_2.winner());
           CHECK_THROWS(game_4.winner());
           CHECK_THROWS(game_5.winner());

        }

}

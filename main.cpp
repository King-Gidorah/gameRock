#include <iostream>
#include "health.h"
#include "heroes.h"
#include "enemies.h"
#include "gameCycle.h"

using namespace std;

int main() {
    // Create a hero
    Hero h(10, 10);
    h.setName("PlayerHero");

    // Create a tournament
    Tournament tournament;

    // Start the tournament
    tournament.startDay();
    tournament.fightBattles(h);
    tournament.endDay(h);

    return 0;
}
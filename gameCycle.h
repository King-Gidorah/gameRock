#ifndef DAY_CYCLE_H
#define DAY_CYCLE_H

#include "heroes.h"
#include "enemies.h"

class Tournament {
private:
    int currentDay;
    int battlesToday;
    static const int maxBattlesPerDay = 4;

public:
    Tournament();
    int getCurrentDay() const;
    int getBattlesToday() const;
    int getMaxBattlesPerDay() const;
    void startDay();
    void endDay(Hero& player);
    void fightBattles(Hero& player);
};

class Battle {
public:
    Battle();
    void startBattle(Hero& player, Enemy& enemy);
    void resolveBattle(Hero& player, int dayCount);

private:
    bool determineTurnOrder(Hero& player, Enemy& enemy);
    void playerTurn(Hero& player, Enemy& target);
    void enemyTurn(Enemy& enemy, Hero& player);
};

#endif // DAY_CYCLE_H
#include "gameCycle.h"
#include <iostream>

using namespace std;

class Hero;
class Enemy;

// Tournament Class Definitions
Tournament::Tournament() : currentDay(1), battlesToday(0) {}

int Tournament::getCurrentDay() const {
    return currentDay;
}

int Tournament::getBattlesToday() const {
    return battlesToday;
}

int Tournament::getMaxBattlesPerDay() const {
    return maxBattlesPerDay;
}

void Tournament::startDay() {
    cout << "Day " << currentDay << " begins!" << endl;
    battlesToday = 0;
}

void Tournament::endDay(Hero& player) {
    cout << "Day " << currentDay << " ends. Time to rest!" << endl;
    player.lvlUp();
    currentDay++;
}

void Tournament::fightBattles(Hero& player) {
    while (battlesToday < maxBattlesPerDay) {
        cout << "Battle " << (battlesToday + 1) << " of Day " << currentDay << " begins." << endl;

        // Create an enemy based on current day and battle number
        Enemy* enemy = nullptr;
        switch (currentDay) {
        case 1:
            if(battlesToday==0) {
                enemy = new Rat();
            }
            if(battlesToday==1) {
                enemy = new Knight();
            }
            if(battlesToday==2) {
                enemy = new EvilWizard();
            }
            if(battlesToday==3) {
                enemy = new SlimeMonster();
            }
        case 2:
            if(battlesToday==0) {
                enemy = new Dog();
            }
            if(battlesToday==1) {
                enemy = new RoyalKnight();
            }
            if(battlesToday==2) {
                enemy = new EvilWarrior();
            }
            if(battlesToday==3) {
                enemy = new Paladin();
            }
        case 3:
            if(battlesToday==0) {
                enemy = new Cerberus();
            }
            if(battlesToday==1) {
                enemy = new EvilRogue();
            }
            if(battlesToday==2) {
                enemy = new EvilCleric();
            }
            if(battlesToday==3) {
                enemy = new King();
            }
        default:
            cout << "Something went wrong" << endl;;
        }

        // Start and resolve battle
        Battle battle;
        battle.startBattle(player, *enemy);
        battle.resolveBattle(player, currentDay);

        delete enemy; // Cleanup
        battlesToday++;
    }
    cout << "Great work! You've completed " << maxBattlesPerDay << " battles today. Come back tomorrow!" << endl;
}

// Battle Class Definitions
Battle::Battle() = default;

void Battle::startBattle(Hero& player, Enemy& enemy) {
    bool playerGoesFirst = determineTurnOrder(player, enemy);

    while (player.getCurrHealth() > 0 && enemy.getCurrHealth() > 0) {
        if (playerGoesFirst) {
            playerTurn(player, enemy);
            if (enemy.getCurrHealth() > 0) enemyTurn(enemy, player);
        } else {
            enemyTurn(enemy, player);
            if (player.getCurrHealth() > 0) playerTurn(player, enemy);
        }
    }
}

void Battle::resolveBattle(Hero& player, int dayCount) {
    cout << "Resolving battle..." << endl;
    player.resetHealth();
    player.resetShield();
    player.addGold(50 * dayCount);
    cout << "You have won the battle and earned " << 50 * dayCount << "gold!" << endl;
}

bool Battle::determineTurnOrder(Hero& player, Enemy& enemy) {
    return player.getSpeed() >= enemy.getSpeed();
}

void Battle::playerTurn(Hero& player, Enemy& target) {
    cout << "It's your turn! What would you like to do?" << endl;
    cout << "1. Attack  2. Magic  3. Items" << endl;
    int action;
    cin >> action;

    switch (action) {
    case 1:
        player.attack(target);
        break;
    case 2:
        cout << "Choose a spell to use (ends your turn)." << endl;
        // Add spell logic here
        break;
    case 3:
        cout << "Choose an item to use (ends your turn)." << endl;
        // Add item logic here
        break;
    default:
        cout << "Invalid action! Turn skipped." << endl;
    }
}

void Battle::enemyTurn(Enemy& enemy, Hero& player) {
    cout << "The enemy attacks!" << endl;
    enemy.attack(player);
}

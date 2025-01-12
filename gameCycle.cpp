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
    cout << "\n--- Day " << getCurrentDay() << " ---" << endl;
    battlesToday = 0;
}

void Tournament::endDay(Hero& player) {
    cout << "Day " << getCurrentDay() << " ends. Time to rest!" << endl;
    player.lvlUp();
    currentDay++;
}

void Tournament::fightBattles(Hero& player) {
    while (getBattlesToday() < maxBattlesPerDay) {
        cout << "Battle " << (getBattlesToday() + 1) << " of Day " << getCurrentDay() << " begins." << endl;

        // Create an enemy based on current day and battle number
        Enemy* enemy = nullptr;
        switch (getCurrentDay()) {
        case 1:
            if (getBattlesToday() == 0) {
                enemy = new Rat();
                cout << "Get ready to fight a Rat!" << endl;
            } else if (getBattlesToday() == 1) {
                enemy = new Knight();
                cout << "Get ready to fight a Knight!" << endl;
            } else if (getBattlesToday() == 2) {
                enemy = new EvilWizard();
                cout << "Get ready to fight an Evil Wizard!" << endl;
            } else if (getBattlesToday() == 3) {
                enemy = new SlimeMonster();
                cout << "Good luck with today's boss: a Slime Monster!" << endl;
            }
            break; // Ensure fall-through does not occur

        case 2:
            if (getBattlesToday() == 0) {
                enemy = new Dog();
                cout << "Get ready to fight a Dog!" << endl;
            } else if (getBattlesToday() == 1) {
                enemy = new RoyalKnight();
                cout << "Get ready to fight a Royal Knight!" << endl;
            } else if (getBattlesToday() == 2) {
                enemy = new EvilWarrior();
                cout << "Get ready to fight an Evil Warrior!" << endl;
            } else if (getBattlesToday() == 3) {
                enemy = new Paladin();
                cout << "Good luck with today's boss: a Paladin!" << endl;
            }
            break;

        case 3:
            if (getBattlesToday() == 0) {
                enemy = new Cerberus();
                cout << "Get ready to fight a Cerberus!" << endl;
            } else if (getBattlesToday() == 1) {
                enemy = new EvilRogue();
                cout << "Get ready to fight an Evil Rogue!" << endl;
            } else if (getBattlesToday() == 2) {
                enemy = new EvilCleric();
                cout << "Get ready to fight an Evil Cleric!" << endl;
            } else if (getBattlesToday() == 3) {
                enemy = new King();
                cout << "Good luck with the final boss: the King!" << endl;
            }
            break;

        default:
            cout << "Something went wrong. Invalid day: " << getCurrentDay() << endl;
            return; // Exit function on invalid input
        }

        if (!enemy) {
            cout << "Error: Failed to create an enemy for battle " << getBattlesToday() + 1 << endl;
            break; // Exit the loop gracefully if enemy creation fails
        }

        // Start and resolve battle
        Battle battle;
        battle.startBattle(player, *enemy);
        battle.resolveBattle(player, getCurrentDay());

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
    cout << "You have won the battle and earned " << 50 * dayCount << " gold!" << endl;
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

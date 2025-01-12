#include <iostream>
#include <limits>
#include "health.h"
#include "heroes.h"
#include "enemies.h"
#include "gameCycle.h"

using namespace std;

void displayShopMenu() {
    cout << "What would you like to buy?" << endl;
    cout << "1. Health Potion (10 gold)" << endl;
    cout << "2. Shield Potion (10 gold)" << endl;
    cout << "5. Exit Shop" << endl;
}

int main() {
    // Game Introduction
    cout << "Today begins the tournament! Your city hosts an annual game, and" << endl;
    cout << "you are the chosen hero to represent your town." << endl;
    cout << "For the following three days, you will fight 4 battles per day." << endl;
    cout << "Good luck!" << endl;

    // Hero Setup
    cout << "By the way... What is your name?" << endl;
    string name;
    cin >> name;

    cout << "Welcome, " << name << "!" << endl;
    cout << "What type of hero are you?" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Cleric" << endl;
    cout << "3. Wizard" << endl;
    cout << "4. Rogue" << endl;

    int choice;
    Hero* hero = nullptr;

    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please choose a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                hero = new Warrior();
                break;
            case 2:
                hero = new Cleric();
                break;
            case 3:
                hero = new Wizard();
                break;
            case 4:
                hero = new Rogue();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }
        break;
    }

    hero->setName(name);
    cout << "You are a " << hero->getType() << " named " << hero->getName() << "!" << endl;

    // Tournament Setup
    Tournament tournament;

    while (tournament.getCurrentDay() < 3) {
        cout << "\n--- Day " << tournament.getCurrentDay() + 1 << " ---" << endl;
        tournament.startDay();

        cout << "You have " << hero->getCurrHealth() << " health, "
             << hero->getCurrShield() << " shield, "
             << hero->getGold() << " gold, and are at level "
             << hero->getLvl() << "." << endl;

        cout << "1. Visit the shop" << endl;
        cout << "2. Go to the tournament" << endl;

        while (true) {
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please choose 1 or 2." << endl;
                continue;
            }

            if (choice == 1) {
                // Shop Interaction
                while (true) {
                    cout << "You have " << hero->getGold() << " gold." << endl;
                    displayShopMenu();
                    cin >> choice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please choose a valid option." << endl;
                        continue;
                    }

                    switch (choice) {
                        case 1: // Health Potion
                            if (hero->getGold() >= 10) {
                                hero->addGold(-10);
                                hero->setMaxHealth(hero->getMaxHealth() + 10);
                                hero->resetHealth();
                                cout << "You bought a health potion!" << endl;
                            } else {
                                cout << "You don't have enough gold!" << endl;
                            }
                            break;

                        case 2: // Shield Potion
                            if (hero->getGold() >= 10) {
                                hero->addGold(-10);
                                hero->setMaxShield(hero->getMaxShield() + 10);
                                hero->resetShield();
                                cout << "You bought a shield potion!" << endl;
                            } else {
                                cout << "You don't have enough gold!" << endl;
                            }
                            break;

                        case 5: // Exit Shop
                            cout << "Exiting the shop..." << endl;
                            break;

                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            continue;
                    }

                    if (choice == 5) break;
                }
            } else if (choice == 2) {
                // Go to Tournament
                break;
            } else {
                cout << "Invalid choice. Please choose 1 or 2." << endl;
            }
        }

        // Tournament Battles
        for (int i = 0; i < 4; ++i) {
            tournament.fightBattles(*hero);
        }
        tournament.endDay(*hero);
    }

    cout << "\nCongratulations, " << hero->getName() << "! You have completed the tournament!" << endl;

    delete hero; // Clean up dynamic memory
    return 0;
}
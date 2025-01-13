#include <iostream>
#include <limits>
#include "health.h"
#include "heroes.h"
#include "enemies.h"
#include "gameCycle.h"
#include "shop.h"

using namespace std;



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
    Shop shop;

    cout << "The tournament begins!" << endl;

    while (tournament.getCurrentDay() < 4) {
        tournament.startDay();

        cout << "You have " << hero->getCurrHealth() << " health, "
             << hero->getCurrShield() << " shield, "
             << hero->getGold() << " gold, and are at level "
             << hero->getLvl() << "." << endl;

        cout << "1. Visit the shop" << endl;
        cout << "2. Go to the tournament" << endl;

        cin >> choice;
        if (choice == 1) {
            cout << "Welcome to the shop!" << endl;
            if(tournament.getCurrentDay()==2){
                cout << "Congrats on getting through the first day. They only get tougher from here." << endl;
            }
            else if(tournament.getCurrentDay()==3){
                cout << "You're doing great! Keep it up!" << endl;
            }
            else if(tournament.getCurrentDay()==4){
                cout << "You're almost there! Keep pushing!" << endl;
                cout << "I hear the king will be there today." << endl;
            }
            else{
            shop.describeShop();
            }
            cout << "You have " << hero->getGold() << " gold." << endl;
            shop.shopInteraction(hero);
        }
        cout << "Moving to the tournament..." << endl;

        // Tournament Battles
        for (int i = 0; i < 4; ++i) {
            tournament.fightBattles(*hero);
        }
        cout << "Great work! You've completed " << tournament.getMaxBattlesPerDay() << " battles today. Come back tomorrow!" << endl;
        tournament.endDay(*hero);
    }

    cout << "\nCongratulations, " << hero->getName() << "! You have completed the tournament!" << endl;
    cout << "You are level " << hero->getLvl() << " with " << hero->getGold() << " gold." << endl;
    cout << "Thank you for playing!" << endl;

    delete hero; // Clean up dynamic memory
    return 0;
}
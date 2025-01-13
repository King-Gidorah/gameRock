#include <limits>
#include "shop.h"

using namespace std;

Shop::Shop() : choice(0) {}

void Shop::shopWelcome() {
    cout << "Welcome to the shop!" << endl;
}

void Shop::describeShop() {
    cout << "The shop is a small, cozy place with shelves full of potions." << endl;
    cout << "You see a sign that says 'Health Potion: 10 gold' and 'Shield Potion: 10 gold'." << endl;
    cout << "Health potions increase your max health by 10 & shield potions increase your max shield by 10." << endl;
}

void Shop::displayShopMenu() {
    cout << "What would you like to buy?" << endl;
    cout << "1. Health Potion (10 gold)" << endl;  
    cout << "2. Shield Potion (10 gold)" << endl;
    cout << "5. Exit Shop" << endl;
}

void Shop::shopInteraction(Hero* hero) {
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
                buyHealthPotion(hero);
                break;

            case 2: // Shield Potion
                buyShieldPotion(hero);
                break;

            case 5: // Exit Shop
                exitShop();
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        if (choice == 5) break;
    }
}

void Shop::buyHealthPotion(Hero* hero) {
    if (hero->getGold() >= 10) {
        hero->addGold(-10);
        hero->setMaxHealth(hero->getMaxHealth() + 10);
        hero->resetHealth();
        cout << "You bought a health potion!" << endl;
        cout << "Your max health is now " << hero->getMaxHealth() << endl;
    } else {
        cout << "You don't have enough gold!" << endl;
    }
}

void Shop::buyShieldPotion(Hero* hero) {
    if (hero->getGold() >= 10) {
        hero->addGold(-10);
        hero->setMaxShield(hero->getMaxShield() + 10);
        hero->resetShield();
        cout << "You bought a shield potion!" << endl;
        cout << "Your max shield is now " << hero->getMaxShield() << endl;
    } else {
        cout << "You don't have enough gold!" << endl;
    }
}

void Shop::exitShop() {
    cout << "Exiting the shop..." << endl;
}
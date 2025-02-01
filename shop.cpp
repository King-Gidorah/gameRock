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
    cout << "3. Longsword (25 gold)" << endl;
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
            
            case 3: // Longsword
                buyLongsword(hero);
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
        cout << "You bought a health potion!" << endl;
        hero->addItem(Items::healthPotion());
    } else {
        cout << "You don't have enough gold!" << endl;
    }
}

void Shop::buyShieldPotion(Hero* hero) {
    if (hero->getGold() >= 10) {
        hero->addGold(-10);
        cout << "You bought a shield potion!" << endl;
        hero->addItem(Items::shieldPotion());
    } else {
        cout << "You don't have enough gold!" << endl;
    }
}

void Shop::buyLongsword(Hero* hero) {
    if (hero->getGold() >= 25) {
        hero->addGold(-25);
        cout << "You bought a longsword!" << endl;
        hero->addItem(Items::longsword());
    } else {
        cout << "You don't have enough gold!" << endl;
    }
}

void Shop::exitShop() {
    cout << "Exiting the shop..." << endl;
}

Items::Items(string itemName): name(itemName) {}

string Items::getName() const {
    return name;
}

Items Items::healthPotion() {
    return Items("Health Potion");
}

Items Items::shieldPotion() {
    return Items("Shield Potion");
}

Items Items::longsword() {
    return Items("Longsword");
}
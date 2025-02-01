#ifndef SHOP_H
#define SHOP_H

#include "heroes.h"

class Shop {
public:
    Shop();
    void shopWelcome();
    void describeShop();
    void displayShopMenu();
    void shopInteraction(Hero* hero);
    void buyHealthPotion(Hero* hero);
    void buyShieldPotion(Hero* hero);
    void buyLongsword(Hero* hero);
    void exitShop();
private:
    int choice;
};

class Items {
private:
    string name;
public:
    Items()=default;
    Items(string itemName);
    string getName() const;
    static Items healthPotion();
    static Items shieldPotion();
    static Items longsword();
};


#endif
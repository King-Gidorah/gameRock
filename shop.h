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
    void exitShop();
private:
    int choice;
};


#endif // SHOP_H
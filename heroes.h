// heroes.h
#ifndef HEROES_H
#define HEROES_H

#include "health.h"
#include <iostream>
#include <vector>

// Forward declaration of Enemy
class Enemy;
class Items;

class Hero : public Health {
private:
    std::string name;

protected:
    int strength;
    int intellect;
    int constitution;
    float critChance;
    int speed;
    int attackDamage;
    int level;
    int gold;

public:
    Hero(int s, int h);
    virtual ~Hero();

    vector<Items> inventory;
    void setName(std::string n);
    std::string getName();
    int getSpeed();
    int getLvl();
    int getGold();
    virtual std::string getType();
    void lvlUp();
    bool isCriticalHit();
    virtual void attack(Enemy& target);
    void addGold(int amount);
    virtual void spells();
    void addItem(const Items& item);
    void showInventory();
    void useItem(Items& item);
    void useHealthPotion();
    void useShieldPotion();
    void equipLongsword(Items& item);
};

class Warrior : public Hero {
public:
    Warrior();
    string getType();
};

class Cleric : public Hero {
public:
    Cleric();
    void healSelf();
    string getType();
    void spells();
};

class Wizard : public Hero {
public:
    Wizard();
    void fireball(Enemy& target);
    void spells(Enemy& target);
    string getType();
};

class Rogue : public Hero {
public:
    Rogue();
    string getType();
};

#endif // HEROES_H
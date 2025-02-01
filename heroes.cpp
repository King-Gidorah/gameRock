// heroes.cpp
#include "heroes.h"
#include "enemies.h"
#include "shop.h"
#include <iostream>

using namespace std;

// Hero implementations
Hero::Hero(int s, int h)
    : Health(s, h), strength(1), intellect(1), constitution(1), critChance(0.1f), level(1), gold(25) {
    attackDamage = 10 * strength;
}

Hero::~Hero() {}

void Hero::setName(std::string n) {
    name = n;
}

std::string Hero::getName() {
    return name;
}

int Hero::getSpeed() {
    return speed;
}

int Hero::getLvl() {
    return level;
}

int Hero::getGold() {
    return gold;
}

string Hero::getType() {
    return "Hero";
}

void Hero::lvlUp() {
    strength += 1;
    intellect += 1;
    constitution += 1;
    critChance += 0.05f;
    level += 1;
    attackDamage = 10 * strength;
}

bool Hero::isCriticalHit() {
    float randomValue = static_cast<float>(rand()) / RAND_MAX;
    return randomValue < critChance;
}

void Hero::attack(Enemy& target) {
    std::cout << getName() << " attacks for " << attackDamage << "!" << std::endl;
    if (isCriticalHit()) {
        target.takeDamage(attackDamage * 2);
        return;
    }
    target.takeDamage(attackDamage);
}

void Hero::addGold(int amount) {
    gold += amount;
}

void Hero::spells() {
    std::cout << "No spells available" << std::endl;
}

void Hero::addItem(const Items& item) {
    inventory.push_back(item);
}

void Hero::showInventory() {
    for (const auto& item : inventory) {
        std::cout << item.getName() << std::endl;
    }
}

void Hero::useHealthPotion() {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getName() == "Health Potion") {
            gainHealth(25);
            std::cout << "You used a health potion and gained 25 health!" << std::endl;
            inventory.erase(it);
            return;
        }
    }
    std::cout << "You don't have any health potions!" << std::endl;
}

void Hero::useShieldPotion() {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getName() == "Shield Potion") {
            gainShield(25);
            std::cout << "You used a shield potion and gained 25 shield!" << std::endl;
            inventory.erase(it);
            return;
        }
    }
    std::cout << "You don't have any shield potions!" << std::endl;
}

void Hero::useItem(Items& item) {
    if (item.getName() == "Health Potion") {
        useHealthPotion();
    }
    if (item.getName() == "Shield Potion") {
        useShieldPotion();
    }
    if (item.getName() == "Longsword") {
        equipLongsword(item);
    }
}

void Hero::equipLongsword(Items& item) {
    attackDamage += 30;
    std::cout << "You equipped a longsword and gained 30 attack damage!" << std::endl;
}

// Warrior implementation
Warrior::Warrior() : Hero(100, 100) {
    strength = 7;
    intellect = 4;
    constitution = 10;
    critChance = 0.25f;
    speed = 3;
    attackDamage = 10 * strength;
}

string Warrior::getType() {
    return "Warrior";
}

// Cleric implementation
Cleric::Cleric() : Hero(100, 100) {
    strength = 6;
    intellect = 7;
    constitution = 10;
    critChance = 0.25f;
    speed = 4;
    attackDamage = 10 * strength;
}

void Cleric::spells() {
    cout << "1. Heal Self" << endl;
    
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            healSelf();
            break;
        default:
            cout << "Invalid choice" << endl;
            Cleric::spells();
    }
}

string Cleric::getType() {
    return "Cleric";
}

void Cleric::healSelf() {
    gainHealth(25);
    std::cout << "Cleric heals for 25 health" << std::endl;
}

// Wizard implementation
Wizard::Wizard() : Hero(0, 100) {
    strength = 3;
    intellect = 10;
    constitution = 3;
    critChance = 0.30f;
    speed = 5;
    attackDamage = 10 * strength;
}

string Wizard::getType() {
    return "Wizard";
}

void Wizard::fireball(Enemy& target) {
    std::cout << "Wizard uses fireball" << std::endl;
    target.takeDamage(intellect * 25);
}

void Wizard::spells(Enemy& target) {
    cout << "1. fireball" << endl;
    cout << "2. lighning" << endl;
    cout << "3. EXPLOSION" << endl;
    
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            fireball(target);
            break;
        case 2:
            //lightning(target);
            break;
        case 3:
            //explosion(target);
            break;
        default:
            cout << "Invalid choice" << endl;
            Wizard::spells(target);
    }
}


// Rogue implementation
Rogue::Rogue() : Hero(25, 100) {
    strength = 6;
    intellect = 3;
    constitution = 7;
    critChance = 0.75f;
    speed = 9;
    attackDamage = 10 * strength;
}

string Rogue::getType() {
    return "Rogue";
}

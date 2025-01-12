// heroes.cpp
#include "heroes.h"
#include "enemies.h"
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

// Warrior implementation
Warrior::Warrior() : Hero(100, 100) {
    strength = 7;
    intellect = 4;
    constitution = 10;
    critChance = 0.25f;
    speed = 3;
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
}

string Rogue::getType() {
    return "Rogue";
}

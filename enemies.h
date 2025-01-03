// enemies.h
#ifndef ENEMIES_H
#define ENEMIES_H

#include "health.h"
#include <iostream>

// Forward declaration of Hero
class Hero;

class Enemy : public Health {
protected:
    int damage;
    int speed;

public:
    Enemy(int shield, int health, int damage, int speed);
    virtual void attack(Hero& target);
    int getDamage();
    int getSpeed();
};

class Rat : public Enemy {
public:
    Rat();
    void attack(Hero& target) override;
};

class Knight : public Enemy {
public:
    Knight();
};

class EvilWizard : public Enemy {
public:
    EvilWizard();
    void fireball(Hero& target);
};

class SlimeMonster : public Enemy {
public:
    SlimeMonster();
    void heal();
};

class Dog : public Enemy {
public:
    Dog();
    void rage();
};

class RoyalKnight : public Enemy {
public:
    RoyalKnight();
    void shieldUp();
};

class EvilWarrior : public Enemy {
public:
    EvilWarrior();
    void rage();
};

class Paladin : public Enemy {
public:
    Paladin();
    void shieldUp();
    void healthUp();
    void invincible();
};

class Cerberus : public Enemy {
public:
    Cerberus();
    void tripleAttack(Hero& target);
    void doubleAttack(Hero& target);
};

class EvilRogue : public Enemy {
public:
    EvilRogue();
};

class EvilCleric : public Enemy {
public:
    EvilCleric();
    void healSelf();
    void smite(Hero& target);
};

class King : public Enemy {
public:
    King();
    void shieldUp();
    void healthUp();
    void rage();
};

#endif // ENEMIES_H
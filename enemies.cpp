// enemies.cpp
#include "enemies.h"
#include "heroes.h"

// Enemy implementations
Enemy::Enemy(int shield, int health, int damage, int speed)
    : Health(shield, health), damage(damage), speed(speed) {}

void Enemy::attack(Hero& target) {
    target.takeDamage(damage);
}

int Enemy::getDamage() {
    return damage;
}

int Enemy::getSpeed() {
    return speed;
}

// Rat implementations
Rat::Rat() : Enemy(0, 50, 20, 7) {}

void Rat::attack(Hero& target) {
    std::cout << "Rat attacks " << target.getName() << " for " << getDamage() << std::endl;
    target.takeDamage(getDamage());
}

// Knight implementation
Knight::Knight() : Enemy(50, 50, 40, 3) {}

// EvilWizard implementation
EvilWizard::EvilWizard() : Enemy(0, 70, 60, 6) {}

void EvilWizard::fireball(Hero& target) {
    target.takeDamage(40);
}

// SlimeMonster implementation
SlimeMonster::SlimeMonster() : Enemy(0, 200, 20, 4) {}

void SlimeMonster::heal() {
    gainHealth(40);
}

// Dog implementation
EvilWolf::EvilWolf() : Enemy(10, 100, 30, 9) {}

void EvilWolf::rage() {
    damage *= 2;
}

// RoyalKnight implementation
RoyalKnight::RoyalKnight() : Enemy(100, 100, 50, 4) {}

void RoyalKnight::shieldUp() {
    gainShield(100);
}

// EvilWarrior implementation
EvilWarrior::EvilWarrior() : Enemy(100, 100, 45, 4) {}

void EvilWarrior::rage() {
    damage *= 2;
}

// Paladin implementation
Paladin::Paladin() : Enemy(125, 125, 45, 5) {}

void Paladin::shieldUp() {
    gainShield(100);
}

void Paladin::healthUp() {
    gainHealth(100);
}

void Paladin::invincible() {
    // Implementation for invincibility
}

// Cerberus implementation
Cerberus::Cerberus() : Enemy(25, 150, 30, 6) {}

void Cerberus::tripleAttack(Hero& target) {
    std::cout << "Cerberus attacks with all three heads" << std::endl;
    target.takeDamage(30 * 3);
}

void Cerberus::doubleAttack(Hero& target) {
    std::cout << "Cerberus attacks with two heads" << std::endl;
    target.takeDamage(30 * 2);
}

// EvilRogue implementation
EvilRogue::EvilRogue() : Enemy(0, 120, 60, 8) {}

// EvilCleric implementation
EvilCleric::EvilCleric() : Enemy(100, 100, 50, 6) {}

void EvilCleric::healSelf() {
    gainHealth(75);
}

void EvilCleric::smite(Hero& target) {
    target.takeDamage(75);
}

// King implementation
King::King() : Enemy(200, 200, 55, 6) {}

void King::shieldUp() {
    gainShield(100);
}

void King::healthUp() {
    gainHealth(100);
}

void King::rage() {
    damage *= 2;
}

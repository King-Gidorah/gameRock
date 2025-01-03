#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>


using namespace std;

class Health {
private:
    int currHealth = 1;
    int maxHealth = 1;
    int currShield = 1;
    int maxShield = 1;
public:
    Health(int s, int h): currHealth(h), maxHealth(h), currShield(s), maxShield(s) {}

    int getCurrHealth(){
        return currHealth;
    }
    int getMaxHealth(){
        return maxHealth;
    }
    int getCurrShield() {
        return currShield;
    }
    int getMaxShield() {
        return maxShield;
    }

    void setMaxHealth(int amount) {
        maxHealth=amount;
    }

    void setMaxShield(int amount) {
        maxShield=amount;
    }

    void resetHealth() {
        currHealth=maxHealth;
    }

    void resetShield() {
        currShield=maxShield;
    }

    void takeDamage(int amount, bool ignoreShield = false) {
        if (ignoreShield) {
            currHealth = max(0, getCurrHealth() - amount);
            return;
        } 
        if (amount <= getCurrShield()) {
            currShield -= amount;
            return;
        }
        amount -= getCurrShield();
        currShield = 0;
        currHealth = max(0, getCurrHealth() - amount);
    }

    void gainHealth(int amount) {
        if(amount+getCurrHealth()<getMaxHealth()){
            resetHealth();
            return;
        }
        currHealth+=amount;
    }

    void gainShield(int amount) {
        if(amount+getCurrShield()<getMaxShield()){
            resetShield();
            return;
        }
        currShield+=amount;
    }

    bool isAlive() {
        if(getCurrHealth()==0){
            return false;
        }
        return true;
    }

};


#endif // HEALTH_H
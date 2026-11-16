#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include <iostream>

class Boss : public Enemy { // Enemy classaas udamshsan huchtei Boss class
private:
    string specialAttackName; // Tusgai chadvaryn ner

public:
    Boss(string n, int h, int p, string skill) // Boss konstruktor
        : Enemy(n, h, p), specialAttackName(skill) {}

    void attack(Character* target) override { // Boss-iin tusgai dovtolgoo (Polymorphism)
        cout << "!!! BOSS " << name << " unleashes " << specialAttackName << " !!!\n"; // Tusgai chadvaraa zarlana
        target->takeDamage(power + 5); // Engiin huch deer +5 nemelt hohirol uchruulna
    }
};

#endif

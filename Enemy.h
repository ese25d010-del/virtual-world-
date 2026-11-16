#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character { // Character classaas udamshsan Daisnii class
public:
    Enemy(string n, int h, int p); // Daisnii konstruktor
    void attack(Character* target) override; // Dovtloh funkts (Polymorphism)
};

#endif

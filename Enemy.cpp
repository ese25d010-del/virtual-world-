#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(string n, int h, int p) : Character(n, h, p) {} // Etseg classiin konstruktoriig duudna

void Enemy::attack(Character* target) { // Daisan toglogch ruu dovtloh uildel
    cout << name << " attacks fiercely!" << endl; // Dovtolgoonii medegdel
    target->takeDamage(power); // Zoriltot durd hohirol uchruulna
}

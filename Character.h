#ifndef CHARACTER_H // File davhardaj unshigdahaas sergiileh hamgaalalt
#define CHARACTER_H // Header file-iig todorhoiloh

#include <string> // Text (string) turul ashiglah san
using namespace std; // std:: gej bichihguigeer shuud ashiglah

class Character { // Buh duruudiin (Player, Enemy, NPC) etseg class (Abstraction)
protected: // Zuvhun ene class bolon udamshsan classuud handah erhtei
    string name; // Duriin ner
    int health; // Ami buyu tsusnii onoo
    int power; // Dovtloh huch

public: // Gadnaas handah bolomjtoi funktsuud
    Character(string n, int h, int p) : name(n), health(h), power(p) {} // Konstruktor: anhnii utga onoono
    virtual ~Character() {} // Virtual destruktor: sanah oi zuv chuluulnu
    virtual void attack(Character* target) = 0; // Tsever virtual funkts (Pure virtual -> Abstract class bolgono)
    virtual void info() const; // Duriin medeelel hevleh virtual funkts
    bool isAlive() const { return health > 0; } // Amid esehiig shalgana (tsus > 0 bol unen)
    void takeDamage(int dmg) { health -= dmg; if (health < 0) health = 0; } // Hohirol avch tsusiig hasna
    int getPower() const { return power; } // Huchnii utgiig butsaah getter funkts
};

#endif // Hamgaalaltiin tugsgul

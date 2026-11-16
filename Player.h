#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Quest.h"
#include <vector> // STL vector konteiner ashiglah san
#include <string>

class Player : public Character { // Character-aas udamshsan Toglogchiin class
private: // Buren nuutslal (Encapsulation)
    int level; // Tuvshin
    int xp; // Turshlagiin onoo
    int gold; // Alt
    int armor; // Hamgaalalt
    vector<string> inventory; // Ed zuilsiin jagsaalt (STL vector)
    Quest currentQuest; // Odoo hiij bui daalgavar

public:
    Player(string n); // Konstruktor
    void attack(Character* target) override; // Dovtloh funkts
    void takeReducedDamage(int dmg); // Huyagnii hamgaalalt tootsoj hohirol avah
    void addItem(string item); // Tsunhend zuil nemeh
    void showInventory(); // Tsunhiig haruulah
    void useItem(); // Tsunhneese zuil ashiglah
    void gainXP(int amount); // Turshlaga nemeh ba tuvshin ahih
    void addGold(int amount) { gold += amount; } // Alt nemeh
    int& getGoldRef() { return gold; } // Altiig uurchluh erhtei butsaah
    int& getXPRef() { return xp; } // Turshlagiig uurchluh erhtei butsaah
    vector<string>& getInventoryRef() { return inventory; } // Tsunhnii jagsaaltiig butsaah
    Quest& getQuestRef() { return currentQuest; } // Daalgavriig butsaah
    void recordKill(); // Daisan ustgasniig burtgeh
    void showStats() const; // Toglogchiin uzuuleltuudiig haruulah
    void savePlayer(); // File ruu hadgalah
    void loadPlayer(); // File-aas unshih
};

#endif

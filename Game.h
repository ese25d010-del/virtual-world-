#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "NPC.h"
#include "Shop.h"
#include "Map.h"

class Game { // Togloomiin buh sistemiig udirdah undsen class
private:
    Player* player; // Toglogchiin zaagch object
    Map worldMap; // Gazriin zurgiin object
    Shop villageShop; // Delguuriin object
    NPC* villageNPC; // NPC-iin zaagch object

public:
    Game(); // Konstruktor
    ~Game(); // Destruktor (sanah oi chuluulnu)
    void menu(); // Undsen tses
    void battle(bool forceBoss = false); // Tulaanii sistem
    void explore(); // Delhiig sudlah sistem
};

#endif

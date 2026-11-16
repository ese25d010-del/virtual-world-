
#include "Player.h"
#include <iostream>
#include <fstream> // File-tai ajillah san (ofstream, ifstream)

using namespace std;

Player::Player(string n) : Character(n, 100, 20), level(1), xp(0), gold(50), armor(0) {} // Anhnii utguud

void Player::attack(Character* target) { // Daisan ruu dovtloh
    cout << name << " strikes for " << power << " damage!" << endl;
    target->takeDamage(power);
}

void Player::takeReducedDamage(int dmg) { // Huyagaar hohirol buuruulah
    int actualDmg = dmg - armor; // Niit hohirloos huyagnii hamgaalaltiig hasna
    if (actualDmg < 1) actualDmg = 1; // Hamgiin bagadaa 1 hohirol avna
    takeDamage(actualDmg);
    cout << "Armor blocked " << armor << " damage! Your HP: " << health << endl;
}

void Player::addItem(string item) { // Tsunhend nemeh
    inventory.push_back(item);
}

void Player::showInventory() { // Tsunhen deh zuilsiig hevleh
    cout << "\n--- Inventory (Gold: " << gold << ") ---\n";
    if (inventory.empty()) { // Hooson esehiig shalgah
        cout << "Empty!\n";
        return;
    }
    for (size_t i = 0; i < inventory.size(); i++) { // Buh zuilsiig dugaarlaj haruulah
        cout << i + 1 << ". " << inventory[i] << endl;
    }
}

void Player::useItem() { // Ed zuil heregleh
    showInventory();
    if (inventory.empty()) return;

    cout << "Select item number to use (0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice <= 0 || choice > (int)inventory.size()) return; // Buruu dugaar bol garah

    string item = inventory[choice - 1]; // Songoson zuiliin neriig avah
    if (item == "Health Potion") { // Em bol tsus nuhnu
        health += 30;
        if (health > 100) health = 100; // Tsus 100-aas hetrehgui
        cout << "Drank Health Potion! HP is now " << health << endl;
        inventory.erase(inventory.begin() + choice - 1); // Hereglesen tul tsunhneese hasna
    } else if (item == "Iron Sword") { // Selem bol huch nemne
        power += 10;
        cout << "Equipped Iron Sword! Power is now " << power << endl;
        inventory.erase(inventory.begin() + choice - 1);
    } else if (item == "Steel Armor") { // Huyag bol hamgaalalt nemne
        armor += 5;
        cout << "Equipped Steel Armor! Armor is now " << armor << endl;
        inventory.erase(inventory.begin() + choice - 1);
    } else {
        cout << "Cannot use this item.\n";
    }
}

void Player::recordKill() { // Daalgavriin yavtsiig ahiulah
    if (currentQuest.isActive && !currentQuest.isCompleted) {
        currentQuest.currentKills++; // Alsan toog 1-eer nemne
        cout << "Quest progress: " << currentQuest.currentKills << "/" << currentQuest.targetKills << endl;
    }
}

void Player::showStats() const { // Statistik medeelel haruulah
    cout << "[Player: " << name << " | Lvl: " << level << " | HP: " << health 
         << " | Power: " << power << " | Armor: " << armor << " | Gold: " << gold << "]\n";
    currentQuest.showStatus();
}

void Player::gainXP(int amount) { // Turshlaga nemeh
    xp += amount;
    if (xp >= 100) { // 100 XP hurvel tuvshin ahina
        level++;
        xp -= 100;
        power += 5; // Huch nemegdene
        health = 100; // Tsus duurne
        cout << "LEVEL UP! Now level " << level << "!" << endl;
    }
}

void Player::savePlayer() { // Togloomiin yavtsiig save.txt file-d hadgalah
    ofstream file("save.txt"); // File bichiheer neeh
    file << name << "\n" << health << "\n" << power << "\n" 
         << level << "\n" << xp << "\n" << gold << "\n" << armor << "\n";
    file << inventory.size() << "\n"; // Tsunhen deh zuilsiin toog bichih
    for (auto &i : inventory) { // Zuil buriig mur muruur bichih
        file << i << "\n";
    }
    file.close(); // File-iig haah
    cout << "Game Saved!\n";
}

void Player::loadPlayer() { // save.txt file-aas umnuh togloomiig unshih
    ifstream file("save.txt"); // File unshihaar neeh
    if (!file) { // File baihgui bol
        cout << "No save file found!\n";
        return;
    }
    size_t size;
    getline(file, name); // Neriig unshih
    file >> health >> power >> level >> xp >> gold >> armor >> size; // Toon utguudiig unshih
    file.ignore(); // Shine muriin temdegtiig algasah
    inventory.clear(); // Odoogiin tsunhiig tseverleh
    for (size_t i = 0; i < size; i++) { // Hadgalsan zuilsiig butsaaj tsunhend hiih
        string item;
        getline(file, item);
        inventory.push_back(item);
    }
    file.close(); // File-iig haah
    cout << "Game Loaded!\n";
}

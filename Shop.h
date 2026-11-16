#ifndef SHOP_H
#define SHOP_H

#include "Item.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Shop { // Hudaldaa hiih class
public:
    void openShop(int& playerGold, vector<string>& inventory) { // Delguuriin tsesiig neeh
        Potion p("Health Potion", 20, 30); // Zarah emiin object
        Weapon w("Iron Sword", 50, 10); // Zarah zevsegiin object
        Armor a("Steel Armor", 40, 5); // Zarah huyagnii object

        int choice; // Hereglegchiin songolt
        do {
            cout << "\n==== VILLAGE SHOP (Your Gold: " << playerGold << ") ====\n";
            cout << "1. Buy " << p.getName() << " (+30 HP) - " << p.getPrice() << " Gold\n";
            cout << "2. Buy " << w.getName() << " (+10 Power) - " << w.getPrice() << " Gold\n";
            cout << "3. Buy " << a.getName() << " (+5 Armor) - " << a.getPrice() << " Gold\n";
            cout << "4. Sell an Item (10 Gold each)\n"; // Ed zuil zarah songolt
            cout << "0. Leave Shop\nChoose: ";
            cin >> choice;

            if (choice == 1 && playerGold >= p.getPrice()) { // Em hudaldaj avah
                playerGold -= p.getPrice(); // Altnaas uniig hasna
                inventory.push_back(p.getName()); // Tsunhend nemne
                cout << "Purchased " << p.getName() << "!\n";
            } else if (choice == 2 && playerGold >= w.getPrice()) { // Zevseg hudaldaj avah
                playerGold -= w.getPrice();
                inventory.push_back(w.getName());
                cout << "Purchased " << w.getName() << "!\n";
            } else if (choice == 3 && playerGold >= a.getPrice()) { // Huyag hudaldaj avah
                playerGold -= a.getPrice();
                inventory.push_back(a.getName());
                cout << "Purchased " << a.getName() << "!\n";
            } else if (choice == 4) { // Tsunhneese ed zuil zarah
                if (inventory.empty()) { // Tsunh hooson bol
                    cout << "Nothing to sell!\n";
                } else {
                    for (size_t i = 0; i < inventory.size(); i++) // Tsunhen deh zuilsiig jagsaana
                        cout << i + 1 << ". " << inventory[i] << endl;
                    cout << "Select item number to sell (0 cancel): ";
                    int idx;
                    cin >> idx;
                    if (idx > 0 && idx <= (int)inventory.size()) { // Zuv dugaar songoson bol
                        cout << "Sold " << inventory[idx - 1] << " for 10 Gold!\n";
                        inventory.erase(inventory.begin() + idx - 1); // Tsunhneese ustgana
                        playerGold += 10; // 10 alt nemj ugnu
                    }
                }
            } else if (choice != 0) { // Alt hurehgui esvel buruu tovch darval
                cout << "Not enough gold or invalid option!\n";
            }
        } while (choice != 0); // 0 dartal delguur dotor baina
    }
};

#endif

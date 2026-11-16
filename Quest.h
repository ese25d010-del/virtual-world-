#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <iostream>
using namespace std;

struct Quest { // Daalgavriin medeelel hadgalah butets
    string title; // Daalgavriin ner
    int targetKills; // Ustgah yostoi daisnii too
    int currentKills; // Odoo ustgasan daisnii too
    int rewardGold; // Shagnaliin alt
    int rewardXP; // Shagnaliin turshlagiin onoo
    bool isActive; // Daalgavar avsan eseh tuluv
    bool isCompleted; // Daalgavar bielssen eseh tuluv

    Quest(string t = "Goblin Hunter", int target = 2, int gold = 60, int xp = 50) // Anhdagch utgatai konstruktor
        : title(t), targetKills(target), currentKills(0), rewardGold(gold), rewardXP(xp), isActive(false), isCompleted(false) {}

    void showStatus() const { // Daalgavriin yavtsiig delgetsend haruulah
        if (isCompleted) cout << "[Quest]: " << title << " (COMPLETED)\n"; // Bielssen bol
        else if (isActive) cout << "[Quest]: " << title << " (" << currentKills << "/" << targetKills << ")\n"; // Hiigdej baigaa bol
        else cout << "[Quest]: None active\n"; // Daalgavar avaagui bol
    }
};

#endif

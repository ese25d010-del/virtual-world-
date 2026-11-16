#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Quest.h"
#include <iostream>

class NPC : public Character { // Character classaas udamshsan enh taivanch dur
private:
    Quest quest; // Ene NPC-iin uguh daalgavar

public:
    NPC(string n, Quest q) : Character(n, 100, 0), quest(q) {} // NPC konstruktor

    void attack(Character* target) override { // NPC tulaldahgui gedgiig ilerhiilne
        cout << name << " is peaceful and does not fight.\n";
    }

    void interact(Quest& playerQuest, int& playerGold, int& playerXP) { // Toglogchtoi hariltsah funkts
        cout << "\n=== NPC: " << name << " ===\n";
        if (playerQuest.isCompleted) { // Herev daalgavriig umnu ni duusgasan bol
            cout << "Thank you for saving our village, hero!\n";
        } else if (!playerQuest.isActive) { // Herev daalgavar avaagui baigaa bol shineer ugnu
            playerQuest = quest;
            playerQuest.isActive = true;
            cout << "New Quest Accepted: " << playerQuest.title 
                 << " (Defeat " << playerQuest.targetKills << " enemies)\n";
        } else if (playerQuest.currentKills >= playerQuest.targetKills) { // Daalgavar bielssen bol shagnal ugnu
            cout << "Quest Completed! Reward: " << playerQuest.rewardGold 
                 << " Gold & " << playerQuest.rewardXP << " XP!\n";
            playerGold += playerQuest.rewardGold; // Alt nemne
            playerXP += playerQuest.rewardXP; // Turshlaga nemne
            playerQuest.isActive = false; // Idevhgui bolgono
            playerQuest.isCompleted = true; // Bielssen tuluvt oruulna
        } else { // Daalgavar duusaagui bol yavtsiig sanuulna
            cout << "Keep going! Progress: " << playerQuest.currentKills 
                 << "/" << playerQuest.targetKills << " enemies defeated.\n";
        }
    }
};

#endif

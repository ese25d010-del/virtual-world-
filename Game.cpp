#include "Game.h"
#include <iostream>
#include <cstdlib> // rand(), srand(), system() funktsuudiin san
#include <ctime> // time() funktsiin san

using namespace std;

Game::Game() { // Togloom ehleh ueiin tohirgoo
    system("color 0A"); // Konsoliin textiig tod nogoon ungutei bolgono
    string name;
    cout << "Enter Player Name: ";
    cin >> name;
    player = new Player(name); // Dinamik sanah oid toglogch uusgene
    villageNPC = new NPC("Elder Wizard", Quest("Defeat 2 Monsters", 2, 60, 50)); // NPC uusgene
    srand(time(0)); // Sanamsargui too uusgegchiig tsagaar ehluulne
}

Game::~Game() { // Togloom duusahad dinamik sanah oig chuluulnu
    delete player;
    delete villageNPC;
}

void Game::explore() { // Gazriin zurgaar ayalah
    worldMap.draw(); // Zurgiig zurna
    cout << "Move (w=up, s=down, a=left, d=right): ";
    char dir;
    cin >> dir;

    if (!worldMap.movePlayer(dir)) { // Hudulguun hiih
        cout << "You hit a wall! Try another direction.\n";
        return;
    }

    worldMap.draw(); // Shine bairlaliig zurna
    int x = worldMap.getX(); // Odoogiin X koordinat
    int y = worldMap.getY(); // Odoogiin Y koordinat

    if (x == 0 && y == 0) { // Delguuriin tseg deer irvel
        villageShop.openShop(player->getGoldRef(), player->getInventoryRef());
    } else if (x == 4 && y == 0) { // NPC deer irvel
        villageNPC->interact(player->getQuestRef(), player->getGoldRef(), player->getXPRef());
    } else if (x == 4 && y == 4) { // Boss-iin tseg deer irvel
        cout << "You entered the Dragon's Lair!\n";
        battle(true); // Zaaval Boss-toi tulaldana
    } else { // Busad hooson nudend sanamsargui uildel bolno
        int event = rand() % 3; // 0, 1, 2 gesen sanamsargui too avna
        if (event == 0) battle(false); // Daisan taarna
        else if (event == 1) { // Altnii avdar olno
            cout << "You found a treasure chest with 20 Gold!\n";
            player->addGold(20);
        } else { // Yuu ch bolohgui
            cout << "Peaceful area. Nothing happened.\n";
        }
    }
}

void Game::battle(bool forceBoss) { // Eeljiin tulaanii sistem
    bool isBoss = forceBoss || (rand() % 10 < 2); // Boss esehiig todorhoilno (20% magadlaltai)
    Character* enemy; // Polimorfizm ashiglan etseg classiin zaagch zarlana

    if (isBoss) { // Boss uusgeh
        enemy = new Boss("DRAGON BOSS", 150, 20, "HELLFIRE BREATH");
        cout << "\n!!! WARNING: DRAGON BOSS APPEARS !!!\n";
    } else { // Engiin Goblin uusgeh
        enemy = new Enemy("Goblin", 50, 10);
        cout << "\nA wild Goblin appears!\n";
    }

    while (player->isAlive() && enemy->isAlive()) { // Hoyuulaa amid baih ued tulaan urgeljilne
        cout << "\n1. Attack  2. Use Item  3. Run\nChoose: ";
        int act;
        cin >> act;

        if (act == 1) { // Dovtloh
            player->attack(enemy);
        } else if (act == 2) { // Em/zevseg heregleh
            player->useItem();
        } else if (act == 3) { // Zugtah
            cout << "Escaped safely!\n";
            delete enemy; // Sanah oi chuluulnu
            return;
        }

        if (enemy->isAlive()) { // Daisan amid uldsen bol hariu dovtolno
            enemy->attack(player);
        }
    }

    if (player->isAlive()) { // Toglogch yalsan bol
        int rewardGold = isBoss ? 120 : 25; // Boss bol 120, engiin bol 25 alt
        int rewardXP = isBoss ? 100 : 50; // Boss bol 100, engiin bol 50 XP
        cout << "\nVICTORY! Earned " << rewardGold << " Gold & " << rewardXP << " XP!\n";
        player->gainXP(rewardXP);
        player->addGold(rewardGold);
        player->recordKill(); // Daalgavart tootsno
    } else { // Yalagdsan bol
        cout << "\nYou were defeated...\n";
    }
    delete enemy; // Daisnii sanah oig chuluulnu
}

void Game::menu() { // Togloomiin undsen tses
    int choice;
    do {
        cout << "\n==== VIRTUAL WORLD RPG ====\n";
        player->showStats(); // Toglogchiin uzuuleltiig deer ni haruulna
        cout << "1. Explore (Map)\n2. Quick Battle\n3. Inventory & Use Item\n4. Shop\n5. Talk to NPC\n6. Save Game\n7. Load Game\n0. Exit\nChoose: ";
        cin >> choice;
        switch (choice) { // Songoltiin daguu funkts duudna
            case 1: explore(); break;
            case 2: battle(false); break;
            case 3: player->useItem(); break;
            case 4: villageShop.openShop(player->getGoldRef(), player->getInventoryRef()); break;
            case 5: villageNPC->interact(player->getQuestRef(), player->getGoldRef(), player->getXPRef()); break;
            case 6: player->savePlayer(); break;
            case 7: player->loadPlayer(); break;
            case 0: cout << "Bye!\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0); // 0 dartal davtana
}

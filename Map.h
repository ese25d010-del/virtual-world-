#ifndef MAP_H
#define MAP_H

#include <iostream>
using namespace std;

class Map { // 2 hemjeest gazriin zurgiin class
private:
    int px, py; // Toglogchiin X, Y koordinat

public:
    Map() : px(2), py(2) {} // Toglogchiig gazriin zurgiin tuvd (2,2) bairluulna

    void draw() const { // 5x5 hemjeetei ASCII zurag zurah
        cout << "\n=== WORLD MAP (P=You, S=Shop, N=NPC, B=Boss) ===\n";
        for (int y = 0; y < 5; y++) { // Mur bureer davtana
            for (int x = 0; x < 5; x++) { // Bagana bureer davtana
                if (x == px && y == py) cout << "[P] "; // Toglogchiin bairlal
                else if (x == 0 && y == 0) cout << "[S] "; // Delguuriin bairlal
                else if (x == 4 && y == 0) cout << "[N] "; // NPC-iin bairlal
                else if (x == 4 && y == 4) cout << "[B] "; // Boss-iin bairlal
                else cout << "[.] "; // Hooson talbai
            }
            cout << endl; // Daraagiin murund shiljine
        }
    }

    bool movePlayer(char dir) { // Toglogchiig hudulguh (w,a,s,d)
        if (dir == 'w' && py > 0) { py--; return true; } // Deesh alhah
        if (dir == 's' && py < 4) { py++; return true; } // Doosh alhah
        if (dir == 'a' && px > 0) { px--; return true; } // Zuun tiish alhah
        if (dir == 'd' && px < 4) { px++; return true; } // Baruun tiish alhah
        return false; // Hyazgaaraas hetervel hudluhgui
    }

    int getX() const { return px; } // X koordinat avah
    int getY() const { return py; } // Y koordinat avah
};

#endif

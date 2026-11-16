#include "Character.h" // Character tolgoi file-iig holboh
#include <iostream> // Delgetsend hevleh san

using namespace std;

void Character::info() const { // Duriin erunhii medeelel haruulah funkts
    cout << "Name: " << name // Neriig hevlene
         << " | HP: " << health // Tsusiig hevlene
         << " | Power: " << power << endl; // Huchiig hevlene
}

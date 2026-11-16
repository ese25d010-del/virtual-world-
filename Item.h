#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item { // Ed zuilsiin suuri class (Abstraction)
protected:
    string name; // Ed zuiliin ner
    int price; // Delguurt zaragdah une
    int value; // Uzuuleh nuluunii hemjee (nuhuh tsus, nemeh huch geh met)

public:
    Item(string n, int p, int v) : name(n), price(p), value(v) {} // Konstruktor
    virtual ~Item() {} // Destruktor
    virtual string getType() const = 0; // Turliig butsaah hiisver funkts
    string getName() const { return name; } // Ner avah getter
    int getPrice() const { return price; } // Une avah getter
    int getValue() const { return value; } // Utga avah getter
};

class Weapon : public Item { // Item-aas udamshsan Zevsegiin class (Inheritance)
public:
    Weapon(string n, int p, int dmg) : Item(n, p, dmg) {} // Zevsegiin konstruktor
    string getType() const override { return "Weapon"; } // Turliig "Weapon" gej butsaana
};

class Potion : public Item { // Item-aas udamshsan Emiin class (Inheritance)
public:
    Potion(string n, int p, int heal) : Item(n, p, heal) {} // Emiin konstruktor
    string getType() const override { return "Potion"; } // Turliig "Potion" gej butsaana
};

class Armor : public Item { // Item-aas udamshsan Huyagnii class (Inheritance)
public:
    Armor(string n, int p, int def) : Item(n, p, def) {} // Huyagnii konstruktor
    string getType() const override { return "Armor"; } // Turliig "Armor" gej butsaana
};

#endif

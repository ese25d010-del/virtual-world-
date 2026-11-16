# Virtual World RPG (C++ OOP Project)

Объект хандалтат програмчлалын (OOP) зарчмуудыг ашиглан хөгжүүлсэн консол дээр суурилсан адал явдалт RPG тоглоом.

## Гол боломжууд
- **OOP Зарчмууд:** Удамшил (Inheritance), Полиморфизм (Polymorphism), Хийсвэрлэл (Abstraction), Битүүмжлэл (Encapsulation)
- **5x5 ASCII Газрын зураг:** Тоглогч чөлөөтэй шилжих, мангас болон Луу (Boss)-тай тулалдах
- **Дэлгүүр (Shop) & Эд зүйлс (Item):** Алтаар эм, зэвсэг, хуяг худалдаж авах болон зарах
- **NPC & Даалгавар (Quest):** Тосгоны NPC-ээс даалгавар авч биелүүлэх
- **Хадгалах систем (Save/Load):** Тоглоомын явцыг файлд хадгалж, дахин үргэлжлүүлэх

## UML Class Diagram

```mermaid
classDiagram
    class Character {
        #string name
        #int health
        #int power
        +Character(n, h, p)
        +attack(Character* target)*
        +info()
        +isAlive() bool
        +takeDamage(int)
        +getPower() int
    }

    class Player {
        -int level
        -int xp
        -int gold
        -int armor
        -vector~string~ inventory
        -Quest currentQuest
        +Player(n)
        +attack(Character* target)
        +useItem()
        +gainXP(int)
        +savePlayer()
        +loadPlayer()
    }

    class Enemy {
        +Enemy(n, h, p)
        +attack(Character* target)
    }

    class Boss {
        -string specialAttackName
        +Boss(n, h, p, skill)
        +attack(Character* target)
    }

    class NPC {
        -Quest quest
        +NPC(n, q)
        +attack(Character* target)
        +interact()
    }

    class Item {
        #string name
        #int price
        #int value
        +getType()*
        +getName()
        +getPrice()
    }

    class Weapon
    class Potion
    class Armor

    class Shop {
        +openShop()
    }

    class Map {
        -int px
        -int py
        +draw()
        +movePlayer(char)
    }

    class Quest {
        +string title
        +int targetKills
        +int currentKills
        +showStatus()
    }

    class Game {
        -Player* player
        -Map worldMap
        -Shop villageShop
        -NPC* villageNPC
        +menu()
        +battle()
        +explore()
    }

    Character <|-- Player
    Character <|-- Enemy
    Character <|-- NPC
    Enemy <|-- Boss
    Item <|-- Weapon
    Item <|-- Potion
    Item <|-- Armor
    Game *-- Player
    Game *-- Map
    Game *-- Shop
    Game *-- NPC
    Player *-- Quest

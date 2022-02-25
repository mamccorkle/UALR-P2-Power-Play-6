//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_PLAYER_H
#define UALR___P2___POWER_PLAY_6_PLAYER_H

    #include <map>      // Header files should be dependency-inclusive
    #include "Object.h" // Parent
    #include "Item.h"   // Has-A Relationship

    class Player: public Object
    {
    public:
        Player();
        void levelUp();
        void heal();

        int attack( ) const;
        void defend( int );
        bool isDead() const;
        void battlePrint() const;

    protected:
    private:
        std::map<Item::Type, Item> inventory{  };
        int SP{  };
    };

#endif //UALR___P2___POWER_PLAY_6_PLAYER_H

//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_OBJECT_H
#define UALR___P2___POWER_PLAY_6_OBJECT_H

    #include <map>
    #include "Item.h"

    class Object
    {
    public:
        enum class Type { player, slime, orc, sprite, dragon, numTypes };
        Type name;
        int strength{ 0 };
        int health{ 0 };
        int level{ 0 };
        std::map<Item::Type, Item> inventory;
    protected:
    private:
    };

#endif //UALR___P2___POWER_PLAY_6_OBJECT_H

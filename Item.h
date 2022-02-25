//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_ITEM_H
#define UALR___P2___POWER_PLAY_6_ITEM_H

    class Item
    {
    public:
        enum class Type { sword, armor, shield, numTypes };
    protected:
    private:
        Type clasification{  };
        int bonusValue{  };
    };

#endif //UALR___P2___POWER_PLAY_6_ITEM_H

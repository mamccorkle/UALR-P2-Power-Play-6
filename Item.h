//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_ITEM_H
#define UALR___P2___POWER_PLAY_6_ITEM_H

    class Item
    {
    public:
        enum class Type { sword, armor, shield, numTypes };

        // Constructors:
        Item() = default;
        Item( Type, int );    // Conversion Constructor

        void print() const; // Will need to change to use the operator overload
        Item::Type getClassification() const;
        int getBonusValue() const;
    protected:
    private:
        Type classification{  };
        int bonusValue{  };
    };

#endif //UALR___P2___POWER_PLAY_6_ITEM_H

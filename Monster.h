//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_MONSTER_H
#define UALR___P2___POWER_PLAY_6_MONSTER_H

    #include "Object.h" // Parent

    class Player;   // Forward Declaration
    class Monster: public Object
    {
    public:
        // Constructors:
        Monster() = default;        // Default
        Monster( const Object& );   // Conversion

        // Member Functions:
        int attack( ) const;
        void defend( int );
        void battlePrint() const;

    protected:

    private:
        int AC{ };

    };

#endif //UALR___P2___POWER_PLAY_6_MONSTER_H

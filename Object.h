//
// Created by Mark McCorkle on 2/25/22.
//
#ifndef UALR___P2___POWER_PLAY_6_OBJECT_H
#define UALR___P2___POWER_PLAY_6_OBJECT_H

    #include <map>      // Header files should be dependency-inclusive
    #include <random>   // Header files should be dependency-inclusive

    class Object
    {
    public:
        static std::random_device seed;
        static std::default_random_engine engine;
        enum class Type { player, slime, orc, sprite, dragon, numTypes };
        Object() = default;
        Object( Type, int, int, int );   // Conversion Constructor
    protected:
    private:
        Type name{ Type::player };
        int strength{ 0 };
        int health{ 0 };
        int level{ 0 };
    };

#endif //UALR___P2___POWER_PLAY_6_OBJECT_H

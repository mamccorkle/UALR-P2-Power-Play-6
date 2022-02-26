//
// Created by Mark McCorkle on 2/25/22.
//
#include <iostream>     // Header files should be dependency-inclusive
#include "Object.h"

std::random_device Object::seed;
std::default_random_engine Object::engine(seed());

// Object Conversion Constructor Definition:
Object::Object( Object::Type name, int strength, int health, int level ): name(name), strength(strength),health(health),level(level)
{ }

int Object::getLevel() const
{
    return level;
}

void Object::printName( ) const
{
    std::cout << "L:" << level << " ";
    switch (name)
    {
        case Object::Type::player:
            std::cout << "Player";
            break;
        case Object::Type::slime:
            std::cout << "Slime";
            break;
        case Object::Type::orc:
            std::cout << "Orc";
            break;
        case Object::Type::sprite:
            std::cout << "Sprite";
            break;
        case Object::Type::dragon:
            std::cout << "Dragon";
            break;
    }
}

bool Object::isDead() const
{
    return health <= 0;
}

std::ostream &operator<<( std::ostream& COUT, const Object& object )
{
    COUT << "L:" << object.level << " ";
    switch (object.name)
    {
        case Object::Type::player:
            COUT << "Player";
            break;
        case Object::Type::slime:
            COUT << "Slime";
            break;
        case Object::Type::orc:
            COUT << "Orc";
            break;
        case Object::Type::sprite:
            COUT << "Sprite";
            break;
        case Object::Type::dragon:
            COUT << "Dragon";
            break;
    }
    return COUT;
}


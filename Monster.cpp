//
// Created by Mark McCorkle on 2/25/22.
//
#include "Monster.h"
#include "Player.h"

Monster::Monster( const Object& player )
{
    std::normal_distribution<double> monsterLevel((float)player.level, player.level  / 4.0);
    int level{ std::max(1, (int)monsterLevel(engine)) };

    std::uniform_int_distribution<int> monsterType(1, (int)Object::Type::numTypes  - 1);
    Object::Type name{ (Object::Type)monsterType(engine) };

    double strengthVariance{ 0.0 };
    double healthVariance{ 0.0 };
    switch (name)
    {
        case Object::Type::slime:
            strengthVariance  = level  * 1.5;
            healthVariance  = level  * 1.25;
            break;
        case Object::Type::orc:
            strengthVariance  = level  * 2.0;
            healthVariance  = (long long)level  * level  * 1.25;
            break;
        case Object::Type::sprite:
            strengthVariance  = level  * 1.75;
            healthVariance  = level;
            break;
        case Object::Type::dragon:
            strengthVariance  = level  * 6.0;
            healthVariance  = (long long)level  * level  * 3.0;
            break;
    }
    std::normal_distribution<double> randomStrength(strengthVariance, level  / 4.0);
    std::normal_distribution<double> randomHealth(healthVariance  * 5, level  / 2.0);

    Object monster(
            {
                    name,
                    std::max(1, (int)randomStrength(engine)),
                    std::max(1, (int)randomHealth(engine)),
                    level,
                    {}
            });
}

//
// Created by Mark McCorkle on 2/25/22.
//
#include <iostream>     // Header files should be dependency-inclusive
#include "Item.h"

Item::Item( Type classification, int bonusValue ): classification( classification ), bonusValue( bonusValue )
{

}

void Item::print() const
{
    switch (classification)
    {
        case Item::Type::armor:
            std::cout  << "Armor";
            break;
        case Item::Type::shield:
            std::cout  << "Shield";
            break;
        case Item::Type::sword:
            std::cout  << "Sword";
            break;
    }
    std::cout  << "+" << bonusValue;
}

Item::Type Item::getClassification() const
{
    return classification;
}

int Item::getBonusValue() const
{
    return bonusValue;
}





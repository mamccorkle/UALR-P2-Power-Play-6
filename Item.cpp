//
// Created by Mark McCorkle on 2/25/22.
//
#include <iostream>     // Header files should be dependency-inclusive
#include "Item.h"

Item::Item( Type classification, int bonusValue ): classification( classification ), bonusValue( bonusValue )
{

}

void Item::print( ) const
{
    switch (classification)
    {
        case Item::Type::armor:
            std::cout << "Armor";
            break;
        case Item::Type::shield:
            std::cout << "Shield";
            break;
        case Item::Type::sword:
            std::cout << "Sword";
            break;
    }
    std::cout << "+" << bonusValue;
}

Item::Type Item::getClassification( ) const
{
    return classification;
}

int Item::getBonusValue( ) const
{
    return bonusValue;
}

std::ostream &operator<<( std::ostream& COUT, const Item& item )
{
    switch (item.classification)
    {
        case Item::Type::armor:
            COUT << "Armor";
            break;
        case Item::Type::shield:
            COUT << "Shield";
            break;
        case Item::Type::sword:
            COUT << "Sword";
            break;
    }
    COUT << "+" << item.bonusValue;
    return COUT;
}

bool operator<( const Item &lValue, const Item &rValue )
{
    return lValue < rValue;
}

int& operator+=( int& lValue, const Item& rValue )
{
    lValue += rValue.bonusValue;
    return lValue;
}

//// v2 - Using the NORMAL method
//int& operator+=( int& lValue, const Item& rValue )
//{
//    lValue += rValue.getBonusValue();
//    return lValue;
//}
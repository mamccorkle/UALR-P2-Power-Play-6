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

        // Member Functions:
        void print() const; // Will need to change to use the operator overload
        Item::Type getClassification() const;
        int getBonusValue() const;

    protected:
        // Insertion operator overloading using Friend declaration to access private members from outside the class:
        // Source: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
        friend std::ostream& operator<<( std::ostream& COUT, const Item& item );

        // Less-than operator overloading using Friend declaration to access private members from outside the class:
        // Source: https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/
        friend bool operator<( const Item& lValue, const Item& rValue );

        // v1 - Using the Friend method INSIDE OF CLASS:
        // Plus-Equals operator overloading using Friend declaration to access private members from outside the class:
        // Source: https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
        //         When dealing with binary operators that do modify the left operand (e.g. operator+=), the member
        //         function version is typically preferred.
        friend int& operator+=( int& lValue, const Item& rValue );

    private:
        Type classification{ Type::sword };
        int bonusValue{ };

    };

//    // Uncomment v2 from both the header and the cpp file and comment out v1 to use this method:
//    // v2 - Using the NORMAL method OUTSIDE OF CLASS:
//    // Plus-Equals operator overloading using the NORMAL method:
//    // Source: https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
//    //         When dealing with binary operators that do modify the left operand (e.g. operator+=), the member
//    //         function version is typically preferred.
//    int& operator+=( int& lValue, const Item& rValue );

#endif //UALR___P2___POWER_PLAY_6_ITEM_H

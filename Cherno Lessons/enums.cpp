#include <iostream>

using namespace std;

// Can specify the start and the type (must be integer)
enum Example : unsigned char { X = 5, Y, Z };

int A = 0;
int B = 1;
int C = 2;

// Enum vs Enum Classes
enum Color { red, green, blue };                    // plain enum
enum Card { red_card, green_card, yellow_card };    // another plain enum
enum class Animal { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

void fun() {
    // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;  // no problem

    if (color == Card::red_card)  // no problem (bad)
        cout << "bad" << endl;

    if (card == Color::green)  // no problem (bad)
        cout << "bad" << endl;

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    // int num2 = a;  // error
    //  if (m == a)    // error (good)
    //  cout << "bad" << endl;

    // if (a == Mammal::deer)  // error (good)
    // cout << "bad" << endl;
}

int main() {
    // Problematic since the values are not grouped
    int val = B;
    Example value = X;

    if (value == X) {
        // blah
        fun();
    }

    return 0;
}
#include <iostream>

// At linking this variable is visible to the current translation unit since it is static.
static int s_level = 5;

// To counter-attack the above issue, we could define an external variable. The linker will look for
// the variable in other translation units. Example:

// In this file:
// extern int s_var;
// In another file:
// int s_var = 10;

// However this example will not work as the linker will not find the variable:

// In this file:
// extern int s_val;
// In another file:
// static int s_val = 10;

struct Entity {
    static int x, y;

    void Print() { std::cout << x << ' ' << y << '\n'; }

    // Only works since x & y are static (as if the method was written outside of the class)
    static void Print_s() { std::cout << x << ' ' << y << '\n'; }
};

// Static variables must be defined
int Entity::x;
int Entity::y;

int main() {
    std::cout << s_level << '\n';

    // Works
    Entity e;
    e.x = 2;
    e.y = 3;

    // Does not work (x, y are no longer class members)
    // Entity e1 = {2, 3};
    Entity e1;
    e1.x = 5;
    e1.y = 8;

    // Will print the same values since the variables are class defined not instance defined.
    e.Print();
    e1.Print();

    // It would be more correct to access the variables like this
    Entity::x = 10;
    Entity::y = 11;

    e.Print();
    Entity::Print_s();

    return 0;
}

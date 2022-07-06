#include <iostream>

class Entity_less {
   public:
    float X, Y;

    void Print() { std::cout << X << ' ' << Y << '\n'; }
};

class Entity {
   public:
    float X, Y;

    Entity() {
        X = 0.f;
        Y = 0.f;
    }

    // One way (arguably worse)
    /*Entity(float X, float Y) {
        this->X = X;
        this->Y = Y;
    }*/

    // Better way
    Entity(float X, float Y) : X(X), Y(Y) {}

    // Delete default constructor
    // Entity() = delete;

    void Print() { std::cout << X << ' ' << Y << '\n'; }
};

int main() {
    Entity_less e;

    // Will not work (uninitialized values)
    // std::cout << e.X << '\n';

    // Random values (without constructor)
    e.Print();

    // Calls default constructor
    Entity e1;
    e1.Print();

    return 0;
}
#include <iostream>

class Entity {
   public:
    float X, Y;

    Entity() {
        X = 0.f;
        Y = 0.f;
    }

    Entity(float X, float Y) : X(X), Y(Y) {}

    // Destructor
    ~Entity() { std::cout << "Destroyed entity\n"; }

    void Print() { std::cout << X << ' ' << Y << '\n'; }
};

int main() {
    // Destructor will be called at the end of the lifetime (in this case the main function)
    Entity e;

    e.Print();

    return 0;
}
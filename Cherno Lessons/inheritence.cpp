#include <iostream>

class Entity {
   public:
    float X, Y;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

// Inherits Entity
class Player : public Entity {
   public:
    const char* Name;

    void PrintName() { std::cout << Name << '\n'; }
};

int main() {
    Player player;

    // Accessible since the members are public
    player.Move(1, 2);
    player.X = 2;

    // Prints 8
    std::cout << sizeof(Entity) << '\n';
    // Prints 12
    std::cout << sizeof(Player) << '\n';

    return 0;
}

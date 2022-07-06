#include <iostream>

class Entity {
    // Private by default
   protected:
    int X, Y;

   public:
    Entity() { X = 0; }
};

// Parent visibility
// public -> public inheritance
// private -> public members of the base class become private
// protected -> public members of the base class become protected
class Player : public Entity {
   public:
    Player() {
        // Visible since protected
        X = 3;
    }
};

int main() {
    Entity e;
    // Not visible if private/protected
    // e.x = 2;

    return 0;
}

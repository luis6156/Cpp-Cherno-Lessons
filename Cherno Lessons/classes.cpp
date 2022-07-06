#include <iostream>

struct Player_s {
    // Visibility is by default public
    int x, y;
};

class Player {
    // Visibility is by default private
   public:
    int x, y;
    int speed;

    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

// The object must be passed by reference
void Move_outside(Player& player, int xa, int ya) {
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}

int main() {
    Player player;
    Player_s player_s;

    // Visibility difference
    player.x = 5;
    player_s.x = 10;

    // Using a function defined outside of the class
    Move_outside(player, 1, 2);

    // Using a member function
    player.Move(5, 5);

    return 0;
}

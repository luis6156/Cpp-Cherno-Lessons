#include <iostream>

static int s_Level = 1;
static int s_Speed = 2;

int main() {
    if (s_Level > 5)
        s_Speed = 10;
    else
        s_Speed = 5;

    // Equivalent
    s_Speed = s_Level > 5 ? 10 : 5;

    // Can be faster since you initialize with the correct value
    std::string rank = s_Level > 10 ? "Master" : "Beginner";

    // Nested ifs
    s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;
    s_Speed = s_Level > 5 && s_Level < 100 ? s_Level > 10 ? 15 : 10 : 5;

    return 0;
}
#include <iostream>

class Entity {
   private:
    std::string m_Name;
    int m_DebugCount = 0;
    mutable int m_DebugCountMutable = 0;

   public:
    const std::string& GetName() const {
        // Does not work
        // m_DebugCount++;

        // Mutable allows const methods to change it
        m_DebugCountMutable++;

        return m_Name;
    }
};

int main() {
    const Entity e;

    // Works
    e.GetName();

    int x = 8;

    // Lambda ([&] send all values by ref, [&x] send x by ref, [=] all by value, [=x] x by value)
    auto f = [&]() {
        std::cout << "Hello\n";

        // Works since it is passed by reference
        std::cout << x++ << '\n';
    };
    f();

    auto g = [=]() {
        std::cout << "World\n";

        // Does not work since it is not modifiable
        // std::cout << x++ << '\n';
    };
    g();

    auto h = [=]() mutable {
        std::cout << "!\n";

        // Works since mutable allows variables passed by values to be modifiable (same as writing
        // inside the lambda int y = x, but this is cleaner)
        std::cout << x++ << '\n';
    };
    h();

    return 0;
}
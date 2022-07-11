#include <iostream>

class Entity {
   private:
    std::string m_Name;

   public:
    // Creates two strings (one default and another with Unknown)
    Entity() { m_Name = "Unknown"; }

    Entity(const std::string& name) { m_Name = name; }

    // Better (initializes directly instead of assigning)
    // The order is exactly like you declare the members
    // Entity() : m_Name("Unknown") {}

    const std::string& GetName() const { return m_Name; }
};

int main() {
    Entity e;
    std::cout << e.GetName() << '\n';

    Entity e1("Cherno");
    std::cout << e1.getName() << '\n';

    return 0;
}

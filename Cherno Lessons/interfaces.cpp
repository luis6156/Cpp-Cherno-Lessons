#include <iostream>

class Entity {
   public:
    // Pure virtual function -> class becomes an interface since all functions are pure virtual
    // (must be implemented by children)
    virtual std::string GetName() = 0;
};

class Player : public Entity {
   private:
    std::string m_Name;

   public:
    Player(const std::string& name) : m_Name(name) {}

    // If no override is provided, an error would be thrown
    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) { std::cout << entity->GetName() << '\n'; }

int main() {
    // Interfaces cannot be instantiated
    // Entity* e = new Entity();
    // PrintName(e);

    // Prints Entity
    Player* p = new Player("Cherno");
    PrintName(p);

    return 0;
}

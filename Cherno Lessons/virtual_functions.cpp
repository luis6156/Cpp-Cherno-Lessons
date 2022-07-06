#include <iostream>

class Entity {
   public:
    // Making the method virtual creates a vtable
    virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
   private:
    std::string m_Name;

   public:
    Player(const std::string& name) : m_Name(name) {}

    // override keyword is optional
    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) { std::cout << entity->GetName() << '\n'; }

int main() {
    // Prints Entity
    Entity* e = new Entity();
    PrintName(e);

    // Prints Entity without virtual (not correct)
    Player* p = new Player("Cherno");
    PrintName(p);

    return 0;
}

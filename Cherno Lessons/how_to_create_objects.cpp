#include <iostream>

using String = std::string;

class Entity {
   private:
    String m_Name;

   public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

void Function() {
    // Entity dies after function ends
    Entity entity = Entity("Cherno");
}

int main() {
    // Stack variant (default constructor) - faster
    Entity entity;
    // Heap variant (non-default constructor) - slower
    Entity* e = new Entity("Cherno");
    // Clear heap object (mandatory)
    delete e;

    return 0;
}

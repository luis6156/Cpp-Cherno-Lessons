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

int main() {
    // Stack
    int a = 2;
    // Heap
    int* b = new int[50];

    // Also calls the constructor
    Entity* e = new Entity;

    Entity* p = new (b) Entity;

    // Delete heap object
    delete e;
    delete[] b;

    return 0;
}
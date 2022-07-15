#include <iostream>

class Entity {
   private:
    std::string m_Name;
    int m_Age;

   public:
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {}
    // Disables implicit conversions
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity) {
    // Printing
}

int main() {
    // Implicit conversion (calls the constructors)
    // PrintEntity(22);
    // Can only do one implicit conversion
    PrintEntity(std::string("Cherno"));
    Entity a = std::string("Cherno");
    // Entity b = 22;

    return 0;
}
#include <iostream>

class Entity {
   private:
    int m_X, m_Y;
    int *m_Xp, *m_Yp;

   public:
    // Does not modify class variable members (works only in classes)
    int GetX() const { return m_X; }

    // Returns a pointer that cannot modify the contents, the pointer itself & it does not change
    // the member variables
    const int* const GetXp() const { return m_Xp; }

    void SetX(int x) { m_X = x; }
};

// Cannot modify the Entity (same as const Entity* const e)
void PrintEntity(const Entity& e) {
    // Does not work because of the reference
    // e = Entity();

    // I can call GetX because GetX is a const function
    std::cout << e.GetX() << '\n';
    // Does not work
    // e.SetX(2);
}

int main() {
    // Constant
    const int MAX_AGE = 99;

    // Compile time constant (read-only memory location)
    constexpr int MIN_AGE = 18;

    int* a = new int;
    *a = 2;

    // Break the const promise
    a = (int*)&MAX_AGE;

    // Cannot modify the contents of the pointer
    const int* b = new int;  // or int const* b = new int;
    // Does not work;
    // *b = 10;
    // Works
    b = (int*)&MAX_AGE;

    // Cannot modify the pointer itself
    int* const c = new int;
    // Does work
    *c = 10;
    // Does not work
    // c = (int*)&MAX_AGE;

    // Cannot modify the pointer itself or the contents
    const int* const d = new int;
    // Does not work
    // *d = 10;
    // Does not work
    // d = (int*)&MAX_AGE;

    std::cout << a << '\n';

    return 0;
}
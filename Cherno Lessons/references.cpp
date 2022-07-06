#include <iostream>

using namespace std;

void foo_wrong(int a) { a++; }

void foo_c_like(int *a) { (*a)++; }

void foo_cpp_like(int &a) { a++; }

int main() {
    int a = 5;

    // Standard pointer and address
    void *p = &a;
    cout << p << '\n';

    // Reference acts like an alias
    int &b = a;
    b++;
    cout << b << ' ' << a << '\n';

    // Updating a variable inside the function -> wrong method
    foo_wrong(a);
    cout << a << '\n';

    // C version
    foo_c_like(&a);
    cout << a << '\n';

    // C++ version
    foo_cpp_like(a);
    cout << a << '\n';

    // A reference cannot be reassigned
    int c = 10;
    b = c;
    cout << b << ' ' << a << ' ' << c << '\n';

    return 0;
}

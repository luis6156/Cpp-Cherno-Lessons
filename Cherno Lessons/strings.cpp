#include <iostream>
#include <string>

using namespace std;

// This implementation copies the string parameter (pass it by const reference)
void PrintString(string string) {
    string += "h";
    cout << string << endl;
}

int main() {
    // Classic
    const char* name = "Cherno";

    // New way (use string literals for append)
    string name_cpp = "Cherno"s + " hello";
    name_cpp += " hello";

    // String has a lot of builtin functions
    bool contains = name_cpp.find("no") != string::npos;

    cout << name << ' ' << name_cpp << ' ' << contains << '\n';

    return 0;
}
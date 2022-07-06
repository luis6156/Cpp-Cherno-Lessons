#include <stdlib.h>

#include <iostream>
#include <string>

int main() {
    using namespace std::string_literals;

    char* name = "Cherno";
    // Does not work (undefined behaviour needs to be casted to char *)
    // name[2] = 'a';

    char name_c[] = "Cherno";
    // Now it works
    name_c[2] = 'a';

    // Different char types
    const wchar_t* name2 = L"Cherno";
    const char16_t* name3 = u"Cherno";
    const char32_t* name4 = U"Cherno";
    const char* name5 = u8"Cherno";

    // Makes a string literal
    std::string name6 = "Cherno"s + " hello";
    std::wstring name7 = L"Cherno"s + L" hello";
    std::u32string name8 = U"Cherno"s;

    // Multiple lines
    const char* ex = R"(A
    Line2
    Line3)";

    return 0;
}
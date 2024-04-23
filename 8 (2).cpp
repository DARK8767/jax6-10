// Q2.Create a class String which contains a character pointer (Use new and delete operator).
// Write a C++ program to overload following operators:
// a. ! To reverse the case of each alphabet from given string
// b. == To check equality of two strings

#include <iostream>
#include <cstring>


class String {
private:
    char* str;

public:
    String() {
        str = nullptr;
    }

    String(const char* s) {
        int len = std::strlen(s);
        str = new char[len + 1];
        std::strcpy(str, s);
    }

    String(const String& other) {
        int len = std::strlen(other.str);
        str = new char[len + 1];
        std::strcpy(str, other.str);
    }

    ~String() {
        delete[] str;
    }

    void print() const {
        std::cout << str << std::endl;
    }

    // Overloading the ! operator
    String operator!() const {
        String result(*this);
        for (int i = 0; i < std::strlen(str); i++) {
            if (std::islower(str[i])) {
                result.str[i] = std::toupper(str[i]);
            }
            else if (std::isupper(str[i])) {
                result.str[i] = std::tolower(str[i]);
            }
        }
        return result;
    }

    // Overloading the == operator
    bool operator==(const String& other) const {
        return std::strcmp(str, other.str) == 0;
    }
};

int main()
 {
    String s1("Hello");
    String s2("WORLD");
    String s3("hello");

    std::cout << "s1 = ";
    s1.print();

    std::cout << "s2 = ";
    s2.print();

    std::cout << "s3 = ";
    s3.print();

    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 == s3: " << (s1 == s3) << std::endl;

    std::cout << "s1 reversed: ";
    (!s1).print();

    return 0;
}

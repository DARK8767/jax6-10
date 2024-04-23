// Q1.Write a C++ program to implement a class printdata to overload print function as follows:
// void print(int) - outputs value followed by the value of the integer.
// Eg. print(10) outputs - value 10
// void print(char *) – outputs value followed by the string in double quotes.
// Eg. print(“hi”) outputs value “hi”//program run but warning are show!
#include <iostream>
#include <cstring>
using namespace std;

class printdata {
public:
    void print(int value) {
        cout << "value " << value << endl;
    }
    void print(char* str) {
        cout << "value \"" << str << "\"" << endl;
    }
};

int main() {
    printdata p;
    p.print(10);
    p.print("hi");
    return 0;
}

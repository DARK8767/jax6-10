// Q1.Write a C++ program to subtract two integer numbers of two different classes using friend
// function.
#include<iostream>
using namespace std;

class Number2; // Forward declaration of class Number2

class Number1 {
private:
    int num1;
public:
    Number1(int n1 = 0) {
        num1 = n1;
    }
    friend int subtract(Number1 n1, Number2 n2); // friend function declaration
};

class Number2 {
private:
    int num2;
public:
    Number2(int n2 = 0) {
        num2 = n2;
    }
    friend int subtract(Number1 n1, Number2 n2); // friend function declaration
};

int subtract(Number1 n1, Number2 n2) { // friend function definition
    return n1.num1 - n2.num2;
}

int main() {
    Number1 n1(10);
    Number2 n2(5);
    int result = subtract(n1, n2);
    cout << "The result of subtraction is: " << result << endl;
    return 0;
}

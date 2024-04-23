// Q2.Write a C++ program to design a class complex to represent complex number. The complex class
// uses an external function (as a friend function) to add two complex number. The function should
// return an object of type complex representing the sum of two complex Numbers.
#include<iostream>
using namespace std;

class complex {
    private:
        float real;
        float imag;
    public:
        complex() {
            real = 0;
            imag = 0;
        }
        complex(float r, float i) {
            real = r;
            imag = i;
        }
        friend complex add(complex, complex);
        void display() {
            cout << real << " + i" << imag << endl;
        }
};

complex add(complex c1, complex c2) {
    complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main() {
    complex c1(3.5, 2), c2(1.2, 3.5), c3;
    c3 = add(c1, c2);
    c1.display();
    c2.display();
    c3.display();
    return 0;
}

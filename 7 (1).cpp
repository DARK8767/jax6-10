// Q1.Write a C++ program using class which contains two data members as type integer. Create and
// initialize the objects using default constructor, parameterized constructor with default value.
// Write a member function to display maximum from given two numbers for all objects.//error show in program line 35,18,13
#include <iostream>

using namespace std;

class Number {
  private:
    int num1, num2;

  public:
    Number() { // Default constructor
      num1 = 0;
      num2 = 0;
    }

    Number(int n1 = 0, int n2 = 0) { // Parameterized constructor with default values
      num1 = n1;
      num2 = n2;
    }

    void displayMax() {
      if (num1 > num2) {
        cout << num1 << " is greater than " << num2 << endl;
      } else {
        cout << num2 << " is greater than " << num1 << endl;
      }
    }
};

int main()
{
  // Create and initialize objects using different constructors
  Number num1; // Default constructor
  Number num2(10, 20); // Parameterized constructor with values 10 and 20
  Number num3(50); // Parameterized constructor with value 50 and default value 0

  // Display maximum number for each object
  num1.displayMax(); // Both values are 0, so output is "0 is greater than 0"
  num2.displayMax(); // 20 is greater than 10
  num3.displayMax(); // 50 is greater than 0

  return 0;
}

// Q1.Write a C++ program to create a class employee containing salary as a data member. Write
// necessary member functions to overload the operator unary pre and post decrement "--"
// for decrementing salary.
#include <iostream>
using namespace std;

class Employee {
   private:
      int salary;

   public:
      Employee(int s=0) {
         salary = s;
      }
      
      // Unary Pre-decrement Operator Overloading
      Employee operator --() {
         salary--;
         return Employee(salary);
      }

      // Unary Post-decrement Operator Overloading
      Employee operator --(int) {
         salary--;
         return Employee(salary);
      }

      void displaySalary() {
         cout << "Salary: " << salary << endl;
      }
};

int main()
 {
   Employee emp(50000);
   emp.displaySalary();  // Salary: 50000

   --emp;  // Pre-decrement operator is called
   emp.displaySalary();  // Salary: 49999
   
   emp--;  // Post-decrement operator is called
   emp.displaySalary();  // Salary: 49998
   
   return 0;
}

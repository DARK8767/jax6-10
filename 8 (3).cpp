// or Q2.Write a C++ program to create a class Date which contains three data members as dd,mm,yyyy.
// Create and initialize the object by using parameterized constructor and display date in dd-month-
// yyyy format. (Input: 19-12-2014 Output: 19-Dec-2014) Perform validation for month.//program run but not accepted that second output
#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void display() const {
        std::string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        if (month < 1 || month > 12) {
            std::cout << "Invalid month!" << std::endl;
        }
        else {
            std::cout << day << "-" << monthNames[month - 1] << "-" << year << std::endl;
        }
    }
};
int main() {
    Date d(19, 12, 2014);
    d.display();

    Date invalidDate(31, 13, 2022);
    invalidDate.display();

    return 0;
}

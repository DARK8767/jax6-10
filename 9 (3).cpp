// or Q2. Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a
// C++ program to perform following necessary member functions:
// a. To read time
// b. To display time in format like: hh:mm:ss
// c. To add two different times (Use Objects as argument)

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void readTime() {
        std::cout << "Enter Hours: ";
        std::cin >> hours;
        std::cout << "Enter Minutes: ";
        std::cin >> minutes;
        std::cout << "Enter Seconds: ";
        std::cin >> seconds;
    }

    void displayTime() const {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time addTime(const Time& t) const {
        Time sum;
        int carry = 0;

        sum.seconds = (seconds + t.seconds) % 60;
        carry = (seconds + t.seconds) / 60;

        sum.minutes = (minutes + t.minutes + carry) % 60;
        carry = (minutes + t.minutes + carry) / 60;

        sum.hours = (hours + t.hours + carry) % 24;

        return sum;
    }
};
int main() {
    Time t1, t2, sum;

    std::cout << "Enter Time 1: " << std::endl;
    t1.readTime();

    std::cout << "Enter Time 2: " << std::endl;
    t2.readTime();

    sum = t1.addTime(t2);

    std::cout << "Time 1: ";
    t1.displayTime();

    std::cout << "Time 2: ";
    t2.displayTime();

    std::cout << "Sum: ";
    sum.displayTime();

    return 0;
}

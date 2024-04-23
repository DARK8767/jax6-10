// Q2. Create a Base class Train containing protected data members as Train_no, Train_Name. Derive a
// class Route(Route_id, Source, Destination) from Train class. Also derive a class Reservation
// (Number_of_Seats, Train_Class, Fare, Travel_Date) from Route. Write a C++ program
// to perform following necessary functions:
// a. Enter details of n reservations
// b. Display details of all reservations
// c. Display reservation details of a specified Train class//error in program
#include <iostream>
#include <string>

class Train {
protected:
    int trainNo;
    std::string trainName;

public:
    Train(int no, std::string name) {
        trainNo = no;
        trainName = name;
    }
};

class Route : public Train {
protected:
    int routeId;
    std::string source;
    std::string destination;

public:
    Route(int no, std::string name, int id, std::string src, std::string dest)
        : Train(no, name) {
        routeId = id;
        source = src;
        destination = dest;
    }
};

class Reservation : public Route {
private:
    int numOfSeats;
    std::string trainClass;
    double fare;
    std::string travelDate;

public:
    Reservation(int no, std::string name, int id, std::string src, std::string dest,
                int seats, std::string cls, double f, std::string date)
        : Route(no, name, id, src, dest) {
        numOfSeats = seats;
        trainClass = cls;
        fare = f;
        travelDate = date;
    }

    void display() const {
        std::cout << "Train No: " << trainNo << std::endl;
        std::cout << "Train Name: " << trainName << std::endl;
        std::cout << "Route ID: " << routeId << std::endl;
        std::cout << "Source: " << source << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Number of Seats: " << numOfSeats << std::endl;
        std::cout << "Train Class: " << trainClass << std::endl;
        std::cout << "Fare: " << fare << std::endl;
        std::cout << "Travel Date: " << travelDate << std::endl;
        std::cout << std::endl;
    }

    static void displayByClass(const Reservation* reservations, int n, std::string cls) {
        std::cout << "Reservations for Train Class: " << cls << std::endl;

        for (int i = 0; i < n; i++) {
            if (reservations[i].trainClass == cls) {
                reservations[i].display();
            }
        }
    }
};

int main() {
    int n = 2; // number of reservations
    Reservation reservations[n] = {
        Reservation(1234, "Train A", 1, "City 1", "City 2", 10, "AC", 1000.0, "2023-03-20"),
        Reservation(5678, "Train B", 2, "City 2", "City 3", 5, "Sleeper", 500.0, "2023-03-22")
    };

    // display all reservations
    std::cout << "All Reservations: " << std::endl;
    for (int i = 0; i < n; i++) {
        reservations[i].display();
    }

    // display reservations for a specified train class
    std::string trainClass = "AC";
    Reservation::displayByClass(reservations, n, trainClass);

    return 0;
}

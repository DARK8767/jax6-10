// or Q2. Design two base classes Employee (Name, Designation) and Project (Project_Id, title). Derive
// a class Emp_Proj(Duration) from Employee and Project. Write a menu driven program to
// a. Build a master table. Display a master table
// b. Display Project details in the ascending order of duration.//error show in program 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string name;
    string designation;
public:
    void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter designation: ";
        cin >> designation;
    }
    void display() {
        cout << name << "\t" << designation << "\t";
    }
};

class Project {
protected:
    int projectId;
    string title;
public:
    void getData() {
        cout << "Enter project ID: ";
        cin >> projectId;
        cout << "Enter project title: ";
        cin >> title;
    }
    void display() {
        cout << projectId << "\t" << title << "\t";
    }
};

class Emp_Proj : public Employee, public Project {
private:
    int duration;
public:
    void getData() {
        Employee::getData();
        Project::getData();
        cout << "Enter project duration (in months): ";
        cin >> duration;
    }
    void display() {
        Employee::display();
        Project::display();
        cout << duration << endl;
    }
    int getDuration() const {
        return duration;
    }
};

bool compareDuration(const Emp_Proj& a, const Emp_Proj& b) {
    return a.getDuration() < b.getDuration();
}

int main() {
    vector<Emp_Proj> masterTable;
    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Add an employee-project\n";
        cout << "2. Display master table\n";
        cout << "3. Display projects in ascending order of duration\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Emp_Proj empProj;
                empProj.getData();
                masterTable.push_back(empProj);
                break;
            }
            case 2: {
                if (masterTable.empty()) {
                    cout << "Master table is empty\n";
                } else {
                    cout << "Name\tDesignation\tProject ID\tTitle\tDuration\n";
                    for (const auto& empProj : masterTable) {
                        empProj.display();
                    }
                }
                break;
            }
            case 3: {
                if (masterTable.empty()) {
                    cout << "Master table is empty\n";
                } else {
                    sort(masterTable.begin(), masterTable.end(), compareDuration);
                    cout << "Name\tDesignation\tProject ID\tTitle\tDuration\n";
                    for (const auto& empProj : masterTable) {
                        empProj.display();
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting program\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid choice\n";
            }
        }
    } while (choice != 4);

    return 0;
}

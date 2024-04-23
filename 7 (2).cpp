// Q2.Create a class College containing data members as College_Id, College_Name,
// Establishment_year, University_Name. Write a C++ program with following functions
// a. Accept n College details
// b. Display College details of specified University
// c. Display College details according to Establishment year (Use Array of Objects and
// Function Overloading).
#include <iostream>
#include <string>

using namespace std;

class College {
  private:
    int college_id;
    string college_name;
    int establishment_year;
    string university_name;

  public:
    College() { // Default constructor
      college_id = 0;
      college_name = "";
      establishment_year = 0;
      university_name = "";
    }

    College(int id, string name, int year, string uni) { // Parameterized constructor
      college_id = id;
      college_name = name;
      establishment_year = year;
      university_name = uni;
    }

    void displayCollege() { // Display College details
      cout << "College ID: " << college_id << endl;
      cout << "College Name: " << college_name << endl;
      cout << "Establishment Year: " << establishment_year << endl;
      cout << "University Name: " << university_name << endl;
      cout << endl;
    }

    string getUniversityName() { // Get University Name
      return university_name;
    }

    int getEstablishmentYear() { // Get Establishment Year
      return establishment_year;
    }
};

void displayCollegeDetailsByUniversity(College colleges[], int n, string uni) {
  for (int i = 0; i < n; i++) {
    if (colleges[i].getUniversityName() == uni) {
      colleges[i].displayCollege();
    }
  }
}

void displayCollegeDetailsByEstablishmentYear(College colleges[], int n, int year) {
  for (int i = 0; i < n; i++) {
    if (colleges[i].getEstablishmentYear() == year) {
      colleges[i].displayCollege();
    }
  }
}

int main() {
  int n;
  cout << "Enter number of colleges: ";
  cin >> n;

  College colleges[n];

  for (int i = 0; i < n; i++) {
    int id, year;
    string name, uni;

    cout << "Enter College ID: ";
    cin >> id;

    cout << "Enter College Name: ";
    cin >> name;

    cout << "Enter Establishment Year: ";
    cin >> year;

    cout << "Enter University Name: ";
    cin >> uni;

    colleges[i] = College(id, name, year, uni);
  }

  // Display College details of specified University
  string uni;
  cout << "Enter University Name to display College details: ";
  cin >> uni;
  displayCollegeDetailsByUniversity(colleges, n, uni);

  // Display College details according to Establishment year
  int year;
  cout << "Enter Establishment Year to display College details: ";
  cin >> year;
  displayCollegeDetailsByEstablishmentYear(colleges, n, year);

  return 0;
}

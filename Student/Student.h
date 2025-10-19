#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

//Implementing a struct that holds each Student's information
class Student {
public: 
    string Name;
    string LastName;
    string HomeAddress;
    string Major;
    double GPA;
    int AmountOfCreditHours;
    int Year;   

// Define the InputDetails function
void InputDetails() {
    cout << "Enter student's name: ";
    cin >> Name;
    cout << "Enter student's last name: ";
    cin >> LastName;
    cout << "Enter student's home address: ";
    cin.ignore();  // Ignore newline character from previous input
    getline(cin, HomeAddress);  // Read entire line for home address
    cout << "Enter student's major: ";
    getline(cin, Major);  // Read entire line for home address
    cout << "Enter student's GPA: ";
    cin >> GPA;
    cout << "Enter student's amount of credit hours: ";
    cin >> AmountOfCreditHours;
    cout << "Enter student's year: ";
    cin >> Year;
    // Clear input buffer
    cin.ignore();
}
// Define the DisplayDetails function
void DisplayDetails() {
    cout << "Name: " << Name << endl;
    cout << "Last Name: " << LastName << endl;
    cout << "Home Address: " << HomeAddress << endl;
    cout << "Major: " << Major << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Amount of Credit Hours: " << AmountOfCreditHours << endl;
    cout << "Year: " << Year << endl;
}
};
#endif
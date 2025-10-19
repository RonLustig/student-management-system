#include "Student.h"
#include "LinkedList.h"
#include <iostream> 
#include <string>
#include <vector>

using namespace std;
int main() {
    //Declaring variables
    int numStudents;
    int choice;
    string StudentToRemove;
    string SpesificStudent;
    string ChangeStudent;

    //Creating a vector to create multiple student object
    cout << "Enter the number of students: ";

    // Validate user input
    while (!(cin >> numStudents) || numStudents <= 0) {
        // If the input is not an integer or is less than or equal to zero
        cout << "Invalid input. Please enter a positive integer: ";

        // Clear the input buffer
        cin.clear();

        // Ignore any remaining characters in the input buffer
        cin.ignore(10000, '\n');
    }

    //Vector of students object that will create students objects based on user's input
    vector<Student> students(numStudents);

    //Letiing user enter information about each student
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        students[i].InputDetails();
    }

    //Add students from vector to linked list
    for (int i = 0; i < numStudents; ++i) {
        AddStudent(students[i]);
    }

    //Displaying amount of students in the school system
    int NumberOfStudents = CountStudents();
    cout<<"\nYou have: "<<NumberOfStudents<<" Students in the school System"<<endl;

    //Automatically saving all students from the linked list
    WriteStudentDataLifetime();

    do {
        // Display menu
        cout << "\nChoose an option:" << endl;
        cout << "1. Remove a student from the system" << endl;
        cout << "2. Get lifetime data" << endl;
        cout << "3. Erase current lifetime list of students and create a fresh list" << endl;
        cout << "4. Display all students you just added to the system" << endl;
        cout << "5. Display information of specific student you just added" << endl;
        cout << "6. Get number of new students recently added" << endl;
        cout << "7. To edit student's information" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Removing a student from the system
                cout << "Enter the name of the student you want to remove: ";
                cin >> StudentToRemove;
                RemoveStudent(StudentToRemove);
                break;
            case 2:
                ReadingStudentData();
                break;
            case 3:
                WriteStudentData();
                break;
            case 4:
                DisplayStudents();
                break;
            case 5:
                cout << "Enter name of student you want to display information on: ";
                cin >> SpesificStudent;
                GetStudentData(SpesificStudent);
                break;
            case 6: {
                // Displaying the number of students in the school system
                int NumberOfStudents1 = CountStudents();
                cout << "\nYou added: " << NumberOfStudents1 << " Students in the school System" << endl;
                break;
            }
            case 7:
                cout << "Enter name of student you want to edit information on: ";
                cin >> ChangeStudent;
                EditStudentData(ChangeStudent);
                break;
            case 8:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
        }
    } while (choice != 8);
};
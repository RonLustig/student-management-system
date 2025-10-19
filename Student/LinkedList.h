#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"

#include <iostream> 
#include <string>
#include <vector>

//File libraries
#include <iostream>
#include <fstream>

using namespace std; 

typedef struct StudentNode {
   Student data;
   StudentNode *next;
}* nodePtr;


//Global decleration variables 
 nodePtr head;
 nodePtr curr;
 nodePtr temp;


//Adding a new student to the system
void AddStudent(Student addData) {
    //Making node pointer to point to New Node
    nodePtr n = new StudentNode;
    //Find the node that n is pointing to and access its next element and make that point to null
    n->next = NULL;
    //Whatever data we pass into the node, the node will hold that
    n->data = addData;

    //Checking if its the first node
    if (head==NULL){
        head=n;
    }
    else {
        //current pointer points to head
        curr=head;
        while (curr->next!=NULL){
            curr = curr->next;
        }
        //when found the end of the list finally attach the new node to the end
        curr->next=n;
    }
}

void RemoveStudent(string StudentName) {
    //cheking if its empty, if its empty then just return 
    if (head == NULL) {
        return;
    }

    // Check if the node to delete is the head node
    if (head->data.Name == StudentName) {
        // Move head to the next node and deallocate memory for the original head
        nodePtr temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // Find the node to delete
    curr = head;
    while (curr->next != NULL && curr->next->data.Name != StudentName) {
        curr = curr->next;
    }

    // If the node with the specified data was not found
    if (curr->next == NULL) {
        cout << "Node with data " << StudentName << " not found." << endl;
        return;
    }
    
    // Found the node to delete
    nodePtr delNode = curr->next;
    curr->next = delNode->next;
    delete delNode;
}

//Display all students
void DisplayStudents()
{
    curr=head;
    while (curr != NULL) {
        //cout << curr->data.Name << " " << curr->data.HomeAddress<< endl;
        cout << "Name: " <<curr->data.Name << endl;
        cout << "Last Name: "<<curr->data.LastName << endl;
        cout << "Home Adress: "<<curr->data.HomeAddress << endl;
        cout << "Major: "<<curr->data.Major << endl;
        cout << "GPA: "<<curr->data.GPA << endl;
        cout << "Amount Of Credits: "<<curr->data.AmountOfCreditHours << endl;
        cout << "Year: "<<curr->data.Year <<"\n"<<endl;
        curr = curr->next;
    }
}

//Printing a spesific one
void GetStudentData(string Name) {
    curr = head;
    while (curr != NULL) {
        if (curr->data.Name == Name) {
            cout << "Name: " <<curr->data.Name << endl;
            cout << "Last Name: "<<curr->data.LastName << endl;
            cout << "Home Adress: "<<curr->data.HomeAddress << endl;
            cout << "Major: "<<curr->data.Major << endl;
            cout << "GPA: "<<curr->data.GPA << endl;
            cout << "Amount Of Credits: "<<curr->data.AmountOfCreditHours << endl;
            cout << "Year: "<<curr->data.Year <<"\n"<<endl;
        }
        // Move to the next node in any case
        curr = curr->next;
    }
}

// Count the number of students in the system
int CountStudents() {
    int count = 0;
    curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

void EditStudentData(string Name) {
    curr = head;
    while (curr != NULL) {
        if (curr->data.Name == Name) {
            // Assuming you want to edit all fields, you can modify this based on your requirements
            cout << "Enter new name: ";
            cin >> curr->data.Name;
            cout << "Enter new last name: ";
            cin >> curr->data.LastName;
            cout << "Enter new home address: ";
            cin.ignore(); // Ignore the newline character left in the input stream
            getline(cin, curr->data.HomeAddress);
            cout << "Enter new major: ";
            getline(cin, curr->data.Major);
            cout << "Enter new GPA: ";
            cin >> curr->data.GPA;
            cout << "Enter new amount of credit hours: ";
            cin >> curr->data.AmountOfCreditHours;
            cout << "Enter new year: ";
            cin >> curr->data.Year;
            cout << "Data updated successfully." << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Student with the name: " << Name << " is not found!" << endl;
}

void WriteStudentData() {
    // Writing to a file
    ofstream outFile("testfilestud.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open file for writing!" << endl;
        return;
    }

    // Traverse the linked list and write each student's name to the file
    curr = head;
    while (curr != nullptr) {
        outFile << "Name: " <<curr->data.Name << endl;
        outFile << "Last Name: "<<curr->data.LastName << endl;
        outFile << "Home Adress: "<<curr->data.HomeAddress << endl;
        outFile << "Major: "<<curr->data.Major << endl;
        outFile << "GPA: "<<curr->data.GPA << endl;
        outFile << "Amount Of Credits: "<<curr->data.AmountOfCreditHours << endl;
        outFile << "Year: "<<curr->data.Year <<"\n"<<endl;
        curr = curr->next;
    }

    outFile.close();
}

void WriteStudentDataLifetime() {
    // Writing to a file
    ofstream outFile("testfilestud.txt", ios::app); // Open file in append mode
    if (!outFile.is_open()) {
        cerr << "Failed to open file for writing!" << endl;
        return;
    }

    // Traverse the linked list and write each student's name to the file
    curr = head;
    while (curr != nullptr) {
        outFile << "Name: " <<curr->data.Name << endl;
        outFile << "Last Name: "<<curr->data.LastName << endl;
        outFile << "Home Adress: "<<curr->data.HomeAddress << endl;
        outFile << "Major "<<curr->data.Major << endl;
        outFile << "GPA: "<<curr->data.GPA << endl;
        outFile << "Amount Of Credits: "<<curr->data.AmountOfCreditHours << endl;
        outFile << "Year: "<<curr->data.Year <<"\n"<<endl;
        curr = curr->next;
    }

    outFile.close();
}

void ReadingStudentData() {
    // Reading from the same file
    ifstream inFile("testfilestud.txt");
    if (!inFile.is_open()) {
        cerr << "Failed to open file for reading!" << endl;
        return;
    }
   string content;

    while(getline(inFile, content)) {
        cout << content <<'\n';
        // Print a blank line to separate students
        cout << endl;
    }
    inFile.close();
}
#endif
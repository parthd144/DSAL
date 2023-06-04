#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store student information
struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student information
void addStudent() {
    ofstream file("student.txt", ios::app);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }
    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter division: ";
    getline(cin, student.division);
    cout << "Enter address: ";
    getline(cin, student.address);
    file << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
    file.close();
    cout << "Student information added successfully." << endl;
}

// Function to delete student information
void deleteStudent() {
    ifstream fileIn("student.txt");
    if (!fileIn) {
        cout << "Error opening file." << endl;
        return;
    }
    ofstream fileOut("temp.txt");
    if (!fileOut) {
        cout << "Error opening file." << endl;
        fileIn.close();
        return;
    }
    int rollNumber;
    cout << "Enter roll number of the student to delete: ";
    cin >> rollNumber;
    bool found = false;
    Student student;
    while (fileIn >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            found = true;
            continue;
        }
        fileOut << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
    }
    fileIn.close();
    fileOut.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
    if (found) {
        cout << "Student information deleted successfully." << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

// Function to display information of a particular student
void displayStudent() {
    ifstream file("student.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }
    int rollNumber;
    cout << "Enter roll number of the student to display: ";
    cin >> rollNumber;
    bool found = false;
    Student student;
    while (file >> student.rollNumber >> student.name >> student.division >> student.address) {
        if (student.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }
    file.close();
    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    int choice;
    do {
//        cout << "====================" << endl;
        cout << "Student Information" << endl;
//        cout << "====================" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}

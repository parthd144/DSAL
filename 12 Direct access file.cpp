#include <iostream>
#include <fstream>

using namespace std;

const int MAX_RECORDS = 100;

class Student {
public:
    int rollNumber;
    string name;
    string division;
    string address;

    void display() {
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name : " << name << endl;
        cout << "Division : " << division << endl;
        cout << "Address : " << address << endl;
//        cout << "-----------------------------" << endl;
    }
};

class DirectAccessFile {
private:
    Student records[MAX_RECORDS];

public:
    DirectAccessFile() {
        for (int i = 0; i < MAX_RECORDS; i++) {
            records[i].rollNumber = -1;  // Initialize rollNumber to -1 for empty records
        }
    }

    void insertRecord(Student student) {
        int index = student.rollNumber;
        if (index < 0 || index >= MAX_RECORDS) {
            cout << "Invalid roll number. Record cannot be inserted." << endl;
            return;
        }
        if (records[index].rollNumber != -1) {
            cout << "Record with roll number " << index << " already exists." << endl;
            return;
        }
        records[index] = student;
        cout << "Record inserted successfully." << endl;
    }

    void deleteRecord(int rollNumber) {
        if (rollNumber < 0 || rollNumber >= MAX_RECORDS) {
            cout << "Invalid roll number. Record cannot be deleted." << endl;
            return;
        }
        if (records[rollNumber].rollNumber == -1) {
            cout << "Record with roll number " << rollNumber << " does not exist." << endl;
            return;
        }
        records[rollNumber].rollNumber = -1;  // Mark record as deleted
        cout << "Record deleted successfully." << endl;
    }

    void displayRecord(int rollNumber) {
        if (rollNumber < 0 || rollNumber >= MAX_RECORDS) {
            cout << "Invalid roll number. Record cannot be displayed." << endl;
            return;
        }
        if (records[rollNumber].rollNumber == -1) {
            cout << "Record with roll number " << rollNumber << " does not exist." << endl;
            return;
        }
        cout << "Record details : " << endl;
        records[rollNumber].display();
    }
};

int main() {
    DirectAccessFile file;
    int choice;
    int rollNumber;
    Student student;
    string name, division, address;
    while (true) {
        cout << "_____MENU_____" << endl;
        cout << "\n 1. Insert a record\n 2. Display a record\n 3. Delete a record\n 4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the roll number : ";
                cin >> rollNumber;
                cout << "Enter the name : ";
                cin >> name;
                cout << "Enter the division : ";
                cin >> division;
                cout << "Enter the address : ";
                cin >> address;
//                Student student;
                student.rollNumber = rollNumber;
                student.name = name;
                student.division = division;
                student.address = address;
                file.insertRecord(student);
                break;
            case 3:
                cout << "Enter the roll number to delete : ";
                cin >> rollNumber;
                file.deleteRecord(rollNumber);
                break;
            case 2:
                cout << "Enter the roll number to display : ";
                cin >> rollNumber;
                file.displayRecord(rollNumber);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}


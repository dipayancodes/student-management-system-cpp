#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    string rollNumber;
    string department;
    string email;
};

void addStudent() {
    ofstream outFile("students.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;

    cout << "Enter student details: " << endl;
    cout << "Name: ";
    getline(cin >> ws, student.name);
    cout << "Roll Number: ";
    getline(cin, student.rollNumber);
    cout << "Department: ";
    getline(cin, student.department);
    cout << "Email: ";
    getline(cin, student.email);

    outFile << student.name << "," << student.rollNumber << "," << student.department << "," << student.email << endl;
    outFile.close();

    cout << "Student record added successfully!" << endl;
}

void displayAllStudents() {
    ifstream inFile("students.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;

    cout << "Student records:" << endl;
    while (getline(inFile, line)) {
        Student student;
        size_t pos = line.find(",");
        student.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        student.rollNumber = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(",");
        student.department = line.substr(0, pos);
        line.erase(0, pos + 1);

        student.email = line;

        cout << "Name: " << student.name << endl;
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Department: " << student.department << endl;
        cout << "Email: " << student.email << endl;
        cout << "-----------------------------" << endl;
    }

    inFile.close();
}

int main() {
    int choice;

    do {
        cout << "Student Record Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}


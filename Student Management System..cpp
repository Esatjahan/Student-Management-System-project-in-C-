#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    int roll;
    float cgpa;
    int cid[5];

    void displayInfo() {
        cout << "Details about student:" << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Roll: " << roll << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Course IDs: ";
        for (int i = 0; i < 5; i++) {
            cout << cid[i] << " ";
        }
        cout << endl;
    }

    void addStudent() {
        cout << "Add the Students Details" << endl;
        cout << "-------------------------" << endl;

        cout << "Enter the first name of student: ";
        cin >> firstName;

        cout << "Enter the last name of student: ";
        cin >> lastName;

        cout << "Enter the roll number of student: ";
        cin >> roll;

        cout << "Enter the CGPA of student: ";
        cin >> cgpa;

        cout << "Enter the course ID for each course:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Enter the course ID for course " << i + 1 << ": ";
            cin >> cid[i];
        }
    }
};

class StudentManagementSystem {
private:
    Student *students;
    int maxSize;
    int currentSize;

public:
    StudentManagementSystem() {
        maxSize = 10; 
        currentSize = 0;
        students = new Student[maxSize];
    }

    ~StudentManagementSystem() {
        delete[] students;
    }

    void addStudent() {
        if (currentSize == maxSize) {
            maxSize *= 2;
            Student *temp = new Student[maxSize];
            for (int i = 0; i < currentSize; ++i) {
                temp[i] = students[i];
            }
            delete[] students;
            students = temp;
        }
        students[currentSize].addStudent();
        currentSize++;
        cout << "Student added successfully." << endl;
    }

    void displayAllStudents() {
        cout << "Details of all students:" << endl;
        for (int i = 0; i < currentSize; ++i) {
            cout << "Student " << i + 1 << ":" << endl;
            students[i].displayInfo();
            cout << endl;
        }
    }

    void findStudentInfo() {
        string firstNameToFind;
        cout << "Enter the First Name of the student: ";
        cin >> firstNameToFind;

        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            if (students[i].firstName == firstNameToFind) {
                students[i].displayInfo();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student with name " << firstNameToFind << " not found." << endl;
        }
    }

    void updateStudentInfo() {
        int rollToUpdate;
        cout << "Enter the roll number to update the entry : ";
        cin >> rollToUpdate;

        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            if (students[i].roll == rollToUpdate) {
                students[i].addStudent();
                found = true;
                cout << "Student information updated successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollToUpdate << " not found." << endl;
        }
    }

    void deleteStudent() {
        int rollToDelete;
        cout << "Enter the roll number to delete: ";
        cin >> rollToDelete;

        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            if (students[i].roll == rollToDelete) {
                for (int j = i; j < currentSize - 1; j++) {
                    students[j] = students[j + 1];
                }
                currentSize--;
                found = true;
                cout << "Student with roll number " << rollToDelete << " deleted successfully." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student with roll number " << rollToDelete << " not found." << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    int choice;
    do {
        cout << "\n1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Find Student by First Name\n";
        cout << "4. Update Student Info\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3:
                sms.findStudentInfo();
                break;
            case 4:
                sms.updateStudentInfo();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

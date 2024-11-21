#include <iostream>
#include <fstream>
#include <cstring>

#include "Student.h"
#include "Course.h"

using namespace std;

int main() {
    Course course = initCourse();

    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "File did not open! Program Exiting!!" << endl;
        return 0;
    }

    // Calls readStudent to read from the file
    readStudent(inFile, course);
    inFile.close();

    // Calls printRoster to print the roster
    cout << "Welcome to my Course Roster Program\n" << endl;
    cout << "Here is the course roster: " << endl;
    printRoster(course);

    // Code to drop a student
    char lastname[20];
    cout << "\nEnter the last name of the student to drop: ";
    cin >> lastname;
    dropStudent(lastname, course);
    cout << "\nHere is the course roster after dropping a student: " << endl;
    printRoster(course);

    // Code to find and print the student with the highest GPA
    Student topStudent = findStudentHighestGPA(course);
    cout << "\nThe student with the highest GPA: ";
    printStd(topStudent);

    cout << "\nThank you for using my Student Roster program!!" << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

// Creates a student, initializes it with information, and returns it.
Student initStudent(char *first, char *last, double gpa) {
    Student student;
    strcpy(student.first, first);
    strcpy(student.last, last);
    student.gpa = gpa;
    return student;
}

// Returns the last name of the student in the given char array through the pointer.
void getLastName(char *studentName, Student student) {
    strcpy(studentName, student.last);
}

// Returns the student's GPA.
double getGPA(Student student) {
    return student.gpa;
}

// Prints a single student's information.
void printStd(Student student) {
    cout << student.last << ";" << student.first << ";" << student.gpa << endl;
}
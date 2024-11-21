#include <iostream>
#include <cstring>
#include <fstream>
#include "Course.h"
#include "Student.h"
using namespace std;

// Initializes a course variable and returns it. The array is empty and the number of students is set to 0.
Course initCourse()
{
    Course course;
    course.numStudents = 0;
    return course;
}

// Reads a student from the file and calls addStudent.
void readStudent(ifstream &inFile, Course &course)
{
    char first[20], last[20];
    double gpa;

    // Read each line from the file
    while (true)
    {
        inFile.getline(last, 100, ';');
        if (inFile)
        {
            inFile.getline(first, 100, ';');
            inFile >> gpa;
            inFile.get();
            Student student = initStudent(first, last, gpa);
            addStudent(student, course);
        }else{
            break;
        }
    }
}

// Adds a student to the roster and increments the count.
// The student is added in sorted order by last name.
void addStudent(Student student, Course &course)
{
    int i = course.numStudents - 1;
    // Insert the student in sorted order by last name
    while (i >= 0 && strcmp(course.roster[i].last, student.last) > 0)
    {
        course.roster[i + 1] = course.roster[i]; // Shift elements to the right
        i--;
    }
    course.roster[i + 1] = student; // Place the new student
    course.numStudents++;           // Increment the number of students
}

// Prints the entire course roster.
void printRoster(Course course)
{
    for (int i = 0; i < course.numStudents; i++)
    {
        printStd(course.roster[i]);
    }
}

// Removes a student by last name from the roster.
void dropStudent(char *lastname, Course &course)
{
    for (int i = 0; i < course.numStudents; i++)
    {
        if (strcmp(course.roster[i].last, lastname) == 0)
        {
            // Shift students to the left
            for (int j = i; j < course.numStudents - 1; j++)
            {
                course.roster[j] = course.roster[j + 1];
            }
            course.numStudents--; // Decrement the number of students
            break;
        }
    }
}

// Finds and returns the student with the highest GPA.
Student findStudentHighestGPA(Course course)
{
    Student topStudent = course.roster[0];
    for (int i = 1; i < course.numStudents; i++)
    {
        if (course.roster[i].gpa > topStudent.gpa)
        {
            topStudent = course.roster[i];
        }
    }
    return topStudent;
}
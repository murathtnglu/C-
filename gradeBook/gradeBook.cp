#include <iostream>
#include "gradeBook.hpp"

using namespace std;

GradeBook::GradeBook (string course, string instructor){
    setCourseName(course);
    setInstructorName(instructor);
}

void GradeBook::setCourseName(string name){
    courseName = name;
}

string GradeBook::getCourseName(){
    return courseName;
}

void GradeBook::setInstructorName(string name){
    instructorName = name;
}

string GradeBook::getInstructorName(){
    return instructorName;
}

void GradeBook::displayMessage(){
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    cout << "This course is presented by: " << getInstructorName() << endl;
}

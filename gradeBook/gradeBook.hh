#ifndef gradeBook_hpp
#define gradeBook_hpp

#include <iostream>
#include <string>
using namespace std;

class GradeBook{
public:
    GradeBook(string,string);
    void setCourseName(string);
    string getCourseName();
    void setInstructorName(string);
    string getInstructorName();
    void displayMessage();
    
private:
    string courseName;
    string instructorName;
    
};

#endif /* GradeBook_hpp */

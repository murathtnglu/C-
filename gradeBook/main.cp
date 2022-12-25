#include <iostream>
#include "gradeBook.hpp"

using namespace std;

int main(){
    GradeBook gradeBook("CS101, Introduction to C++ Programming", "Professor Hatunoglu :)");
    
    cout << "gradeBook instructor name is: " << gradeBook.getInstructorName() << endl;
    
    gradeBook.setInstructorName("Assistant Professor Akyol");
    
    cout << "new gradeBook instructor name is: " << gradeBook.getInstructorName() << endl;
    
    gradeBook.displayMessage();
    
    return 1;
}


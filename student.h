#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks;
    char grade;

public:
    void input();
    void display() const;
    int getRollNo() const;
    void saveToFile() const;
};

#endif

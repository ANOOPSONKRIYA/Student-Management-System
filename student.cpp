#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;

void Student::input() {
    cout<<"Enter your roll number: ";
    cin>>rollNo;

    cin.ignore();  // VERY IMPORTANT
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    //simple grading logic
    if (marks>=90)
    {
        grade = 'A';
    } else if (marks>=80)
    {
        grade = 'B';
    } else if (marks>=70)
    {
        grade = 'C';
    } else if (marks>=60)
    {
        grade = 'D';
    } else
    {
        grade = 'F';
    }    
}

void Student::display() const {
    cout << "-----------------------" << endl;
    cout << "Student Details -" << endl;
    cout << "Roll No : " << rollNo << endl;
    cout << "Name    : " << name << endl;
    cout << "Marks  : " << marks << endl;
    cout << "Grade  : " << grade << endl;
    cout << "-----------------------" << endl;
}

int Student::getRollNo() const {
    return rollNo;
}

void Student::saveToFile() const {
    ofstream fout("data.txt", ios::app);
    if (!fout)
    {
        cout<<"Error opening file!"<<endl;
        return; // no value
    }
    fout << rollNo << "|"<<name<<"|"<<marks<<"|"<<grade<<endl;
    fout.close();
}

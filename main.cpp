#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"

using namespace std;

void searchStudentByRoll(){
    ifstream fin("data.txt");

    if (!fin)
    {
        cout<<"File Not Found!"<<endl;
        return;
    }
    
    int searchRoll;
    cout<<"Enter Roll Number to Search: ";
    cin>>searchRoll;

    string line;
    bool found = false;

    while (getline(fin,line)){
        stringstream ss(line);
        string rollStr, name, marksStr, gradeStr;

        getline(ss, rollStr, '|');
        getline(ss, name, '|');
        getline(ss, marksStr, '|');
        getline(ss, gradeStr, '|');

        int roll = stoi(rollStr);

        if (roll = searchRoll)
        {
            Student s;
            s.setData(roll,name,stoi(marksStr), gradeStr[0]);
            s.display();
            found = true;
            break;
        }        
    }

    if (!found)
    {
        cout<< "Student with Roll No "<<searchRoll<<" Not Found in Data"<<endl;
        fin.close();
    }   
}

void displayAllStudents(){
    ifstream fin("data.txt");

    if (!fin)
    {
        cout<<"o records found!"<<endl;
        return;
    }
    
    string line;
    while (getline(fin,line)){
        stringstream ss(line);
        string rollStr, name, marksStr, gradeStr;

        getline(ss, rollStr, '|');
        getline(ss, name, '|');
        getline(ss, marksStr, '|');
        getline(ss, gradeStr, '|');

        Student s;
        s.setData(
            stoi(rollStr),name,stoi(marksStr),gradeStr[0]
        );

        s.display();
    }

    fin.close();
    
}

int main() {
    Student s;

    // s.input();
    // s.saveToFile();/

    // displayAllStudents();

    searchStudentByRoll();

    return 0;
}

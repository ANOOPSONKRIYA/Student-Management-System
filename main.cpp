#include <iostream>
#include <fstream>
#include <sstream>
#include "student.h"

using namespace std;

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

    displayAllStudents();

    return 0;
}

#include <iostream>
#include "student.h"
using namespace std;

int main() {
    Student s;

    s.input();
    s.saveToFile();

    cout << "\n StudentData saved to file successfully!" << endl;

    return 0;
}

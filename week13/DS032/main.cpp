#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
    Stack<string> nameStack(100);
    double maxGPA = 0.0;

    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "No File." << endl;
        return 1;
    }

    string name;
    double gpa;
    while (file >> gpa >> name) {
        if (gpa > maxGPA) {
            while (!nameStack.isEmpty()) {
                nameStack.pop();
            }
            nameStack.push(name);
            maxGPA = gpa;
        } else if (gpa == maxGPA) {
            nameStack.push(name);
        }
    }

    cout << "Top GPA: " << maxGPA << endl;
    while (!nameStack.isEmpty()) {
        cout << nameStack.pop() << endl;
    }

    file.close();
    return 0;
}

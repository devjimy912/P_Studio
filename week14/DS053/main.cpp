#include <fstream>
#include "MyCircularStringQueue.h"

using namespace std;

int main() {
    MyCircularStringQueue<string> que;
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
            while (!que.isEmpty()) {
                que.dequeue();
            }
            que.enqueue(name);
            maxGPA = gpa;
        } else if (gpa == maxGPA) {
            que.enqueue(name);
        }
    }

    cout << "Top GPA: " << maxGPA << endl;
    while (!que.isEmpty()) {
        cout << que.Front() <<" "<< maxGPA << endl;
        que.dequeue();
    }

    file.close();
    return 0;
}

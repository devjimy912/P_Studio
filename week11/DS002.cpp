#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x1,y1;
    double x2,y2;
    double distance;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    distance = sqrt(pow((x1-x2),2)+pow((y1-y2),2));

    cout << distance << endl;

    return 0;
}
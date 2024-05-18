#include <iostream>
//for git
using namespace std;

int main(){
    int height, weight;
    double bmi;

    cin >> height;
    cin >> weight;

    bmi = weight / (height*height*0.0001);

    if(bmi >= 25){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
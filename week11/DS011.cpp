#include <iostream>

using namespace std;

int main(){
    int size;
    int sum = 0;
    int maximum = 0;
    cin >> size;

    int* array = new int[size];

    for(int i=0; i<size; i++){
        cin >> array[i];
        sum += array[i];
        if(maximum == 0 || maximum < array[i]){
            maximum = array[i];
        }
    }

    cout << sum << " " << maximum << endl;

    delete[] array;
    return 0;
}
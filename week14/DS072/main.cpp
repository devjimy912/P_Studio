#include "InsertionSort.h"

using namespace std;

int main(){
    //array size
    int size;
    cin>>size;
    int list[size];
    //data
    for(int i=0; i<size; i++){
        cin>>list[i];
    }

    // size = 5;

    // int list[] = {64, 25, 12, 22, 11};

    print(list, size);

    cout<<"sorting start"<<endl;

    insertionSort(list, size);

    cout<<"========="<<endl;

    print(list, size);
    
    return 0;
}
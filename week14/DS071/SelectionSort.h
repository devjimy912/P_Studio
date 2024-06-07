#include <iostream>

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        std::cout << "[" << arr[i] << "] " ;
    std::cout << std::endl;
}

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

//순서. 오름차순이나 내림차순 중 하나를 정한다.
//오름차순의 경우
//배열 내에서 가장 작은 것을 찾는다.
//0번 인덱스와 교체한다.
//0번을 제하고 가장 작은 것을 찾는다.
//1번과 교체한다.
//이걸 마지막 인덱스까지 하면 된다.

/*
void selectionSort(int* arr, int n){
    std::cout<<"call"<<std::endl;
    int index = 0;
    int temp;
    int min, minIndex;
    std::cout<<"setting finish"<<std::endl;
    for(int j=0; j<n; j++){
        std::cout<<"lab : "<<j<<std::endl;
        //fix under..
        //find minmum
        min = arr[index];
        for(int i=1; i<n; i++){
            if(arr[i]<min){
                min = arr[i];
                minIndex = i;
            }
        }
        //change
        temp = arr[index];
        arr[index] = min;
        arr[minIndex] = temp;
        index++;
    #ifdef DEBUGMODE
        print(arr, n);
    #endif
    }
    return;
}
*/

void selectionSort(int *arr, int n){
    int min_i = 0;

    for(int i = 0; i < n-1; i++){
        min_i = i;
        for(int j = i+1; j < n; j++){
            if(arr[min_i] > arr[j]) min_i = j;
        }
        if(i != min_i) swap(arr[i], arr[min_i]);
#ifdef DEBUGMODE
    print(arr, n);
#endif
    }
}
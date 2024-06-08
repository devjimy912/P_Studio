#include <iostream>

void print(const int* arr, const int size){
    for(int i=0; i<size; i++){
        std::cout<<"["<<arr[i]<<"]";
    }
    std::cout<<std::endl;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int* list, int left, int right, int size) {
    int pivot, i, j;
    if (left < right) {
        i = left; // left is the first index of the left sublist.     
        j = right+1; // right is the last element index of the right sublist.
        pivot = list[left];
        do {
            do i++; while(i <= right && list[i] < pivot);
            do j--; while(j  > left  && list[j] > pivot);
            if(i<j)
                swap(list[i], list[j]);
        } while (i<j);     
        swap(list[left], list[j]);
#ifdef DEBUGMODE
    print(list, size);
#endif
        quickSort(list, left, j-1, size);
        quickSort(list, j+1, right, size);
    }
}
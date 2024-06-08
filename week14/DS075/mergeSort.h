#include <iostream>

void print(const int* arr, const int size){
    for(int i=0; i<size; i++){
        std::cout<<"["<<arr[i]<<"]";
    }
    std::cout<<std::endl;
}

void merge(int list[], int sorted[], int i, int m, int n){
	int j, k, t;
	j = m + 1; // the first element of the second sorted list 
	k = i;
	while(i <= m && j <= n){
	   if(list[i] < list[j]) sorted[k++] = list[i++];
	   else sorted[k++] = list[j++];
	}
	if(i > m){	                  // All elements in left list are copied
	   for(t = j ; t <= n ; t++)  // copy remained elements in right list
		 sorted[k++] = list[t];  //sorted[k+t-j] = list[t];
	} else {	                  // There are remained elements in left list
	   for(t = i; t <= m; t++)    // copy remained elements in left list
		 sorted[k++] = list[t];  //sorted[k+t-i] = list[t];
	}
}
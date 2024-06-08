#include <iostream>

void print(const int* arr, const int size){
    for(int i=0; i<size; i++){
        std::cout<<"["<<arr[i]<<"]";
    }
    std::cout<<std::endl;
}

void merge(int* list, int* sorted, int i, int m, int n){
	int j, k, t;
	j = m + 1; // the first element of the second sorted list 
	k = i;

	while(i <= m && j <= n){
	   if(list[i] < list[j]) sorted[k++] = list[i++];
	   else sorted[k++] = list[j++];
	}
   	// one of sorted lists completed the traversal. So do the rest of traversal of another.  
	if(i > m)	   // All elements in left list are copied
	   while(j<=n) sorted[k++] = list[j++]; // remained elements in right
	else 	   // There are remained elements in left list
	   while(i<=m) sorted[k++] = list[i++];
}

void mergeSort(int* list, int* sorted, int low, int high, int size){
   	if (low < high){
       	int mid = (low+high)/2;
       	mergeSort(list, sorted, low, mid, size);
       	mergeSort(list, sorted, mid+1, high, size);
    	merge(list, sorted, low, mid, high);
   	}
#ifdef DEBUGMODE
	print(sorted, size);
#endif
}
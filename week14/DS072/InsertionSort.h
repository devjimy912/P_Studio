#include <iostream>

void print(const int* arr, const int size){
    for(int i=0; i<size; i++){
        std::cout<<"["<<arr[i]<<"]";
    }
    std::cout<<std::endl;
}

void insertionSort(int* arr, const int size){
    //배열을 포인터로 받고 그 크기를 받는다.
    //따로 구하기 귀찮음. size()매번쓰기도 길어지니.
    //앞에서부터 배열을 한번 돈다.
    //정렬된 부분과 비교하면서 정렬.
    //방식
    //선택된 인덱스의 값을 임시로 저장.
    //앞에서부터 비교하는데
    //오름차순이므로 자신보다 값이 커지면 그자리에서 멈춘다.
    //해당 인덱스 기억하고
    //마지막 정렬된 부분부터 한칸씩 뒤로 넘김.
    //그렇게 생긴 빈부분에 아까 임시저장해둔 값을 넣는다.
    int temp;
    int iter;
    //1번부터 시작하는 이유는 0번 인덱스는 비교할 대상이 없기 때문이다.
    //need fix
    for(int i=1; i<size; i++){
        //값 임시저장
        temp = arr[i];
        // std::cout<<"temp : "<<temp<<std::endl;
        //자리 찾기
        for(iter=0; iter<i; iter++){
            if(arr[iter] > temp){
                // std::cout<<"iter : "<<iter<<std::endl;
                break;
            }
        }
        //정렬 시작.
        for(int j=i; j>iter; j--){
            arr[j] = arr[j-1];
        }
        //삽입
        arr[iter] = temp;
#ifdef DEBUGMODE
    print(arr,size);
#endif
    }
}
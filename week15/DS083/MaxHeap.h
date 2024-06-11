#ifndef MAXHEAP_H
#define MAXHEAP_H
#define _DEBUG

class MaxHeap {
    private:
        int *list;
        int maxSize;
        int last;

    public:
        void printArray();
        MaxHeap(const int &size);
        void insert(const int& data);
        int findParent(const int& index);
        int extract(); // same as delete
        void swap(int& dataA, int& dataB);
        bool isEmpty() const;
        bool isFull() const;

};

void MaxHeap::printArray(){
    std::cout << "==> Heap : ";
    for (int i = 0; i < maxSize; ++i)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

MaxHeap::MaxHeap(const int &size){
    this->list = new T[size];
    this->maxSize = size;
    this->last = -1;
}

void MaxHeap::insert(const int& data){
    
    // cout<<"Method call"<<endl;
    if(isFull()){
        std::cout<<"Heap already full"<<std::endl;
        return;
    }
    //일단 값을 넣어
    this->last++;
    // cout<<"last++"<<endl;
    this->list[this->last] = data;
    // cout<<"Insert data"<<endl;
    //그리고 값을 비교한다.
    int child = this->last;
    int parent = findParent(child);
    
    //while문 수정 필요.
    while(1){
        // cout<<this->list[parent]<<" swap "<<this->list[child]<<endl;
        swap(this->list[parent], this->list[child]);
        
        child = parent;
        parent = findParent(child);
        // cout<<curr<<endl;
        if(parent < 1){
            break;
        }
    }
    // cout<<"End While"<<endl;
    //마지막. 0번 인덱스와 비교
    swap(this->list[parent], this->list[child]);
    // cout<<"0to0"<<endl;
}

int MaxHeap::findParent(const int& index){
    if (index == 0) {
        return 0; // 루트 노드의 부모는 없음
    }
    if(index%2 == 1){
        return (index-1)/2;
    }else{
        return (index-2)/2;
    }
}

int MaxHeap::extract(){// same as delete
    //만약 비었다면 빈 값보내기
    if(isEmpty()){
        std::cout<<"Heap is Empty"<<std::endl;
        return T();
    }
    //일단 값 저장
    int temp = this->list[0];
    //마지막 값을 최상위로 보냄
    this->list[0] = this->list[this->last];
    this->last--;
    //이제 리스트 전체를 스왚으로 헤짚으면 됨.
    int num = 0;
    while(num*2+2 <= this->last){
        swap(this->list[num], this->list[num*2+1]);
        swap(this->list[num], this->list[num*2+2]);
        num++;
    }

    if(num*2+1 == this->last){
        swap(this->list[num*2+1], this->list[this->last]);
    }

    return temp;
}

void MaxHeap::swap(int& dataA, int& dataB){
    if(dataA < dataB){
        int dummy = dataA;
        dataA = dataB;
        dataB = dummy;
    }
}

bool MaxHeap::isEmpty() const {
    if(this->last == -1){
        return true;
    }else{
        return false;
    }
}

bool MaxHeap::isFull() const {
    if(this->last +1 == this->maxSize){
        return true;
    }else{
        return false;
    }
}

#endif
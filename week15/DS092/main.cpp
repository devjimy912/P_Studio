#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> maxHeap;

    int count;
    int n;
    std::cin>>count>>n;
    
    // 요소 추가
    int temp;
    for(int i=0; i<count; i++){
        std::cin>>temp;
        maxHeap.push(temp);
    }

    // 요소 제거 및 출력 (내림차순으로 출력됨)
    // while (!maxHeap.empty()) {
    //     std::cout << maxHeap.top() << " ";
    //     maxHeap.pop();
    // }
    for(int i=1; i<n; i++) {
        maxHeap.pop();
    }
    std::cout<<maxHeap.top()<<std::endl;

    return 0;
}

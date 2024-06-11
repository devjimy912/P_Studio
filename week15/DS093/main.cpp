#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <set>

// ASCII 값의 합을 계산하는 함수
int asciiSum(const std::string& str);

// Min-Heap 비교 함수 객체
//need fix - 사전식은 ascii 합 아님..
//사전식은 글자 하나하나 비교하는거
//일이 좀 추가됬네..
struct CompareMin {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return asciiSum(lhs) > asciiSum(rhs);
    }
};

int main() {
    std::ifstream inputFile("data.txt"); // 입력 파일을 열기

    if (!inputFile.is_open()) { // 파일 열기에 실패한 경우
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::priority_queue<std::string, std::vector<std::string>, CompareMin> minHeap;

    std::set<std::string> uniqueValues; // 중복값을 걸러내기 위한 보조 컨테이너

    std::string data;
    std::getline(inputFile, data); //첫줄은 크기. 근데 여기 힙에 이게 필요한가..?
    while (std::getline(inputFile, data)) { // 파일로부터 한 줄씩 읽기
        // 요소 추가
        if(uniqueValues.find(data) == uniqueValues.end()) { // 중복되지 않은 값인 경우에만 처리
            minHeap.push(data);
            uniqueValues.insert(data);
        }
    }

    inputFile.close(); // 파일 닫기

    // 요소 제거 및 출력
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << "\n";
        minHeap.pop();
    }
    std::cout<<std::endl;

    return 0;
}

int asciiSum(const std::string& str) {
    int sum = 0;
    for (char ch : str) {
        sum += static_cast<int>(ch);
    }
    return sum;
}
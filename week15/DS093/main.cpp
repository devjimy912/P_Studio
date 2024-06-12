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
        //asciiSum을 바꿔야함.
        // return asciiSum(lhs) > asciiSum(rhs);
        //먼저 문자열의 길이로 비교한다.
        //큰 쪽이 true, 작은 쪽이 false인데 그냥 > 하나면 될듯.
        //같으면 한 글자씩 아스키값 비교.
        //이건 for문으로
        if(lhs.length() != rhs.length()){
            return lhs.length() > rhs.length();
        }else{
            for(int i=0; i<lhs.length(); i++){
                if(lhs[i] == rhs[i]){
                    continue;
                }
                return static_cast<int>(lhs[i]) > static_cast<int>(rhs[i]);
            }
        }
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

//이 친구를 전체합 비교가 아닌 개별순차 비교로 바꾸면 됨.
//나오는 경우가 같다, 크다, 작다
//아니지 같다는 없음. 넣기 전에 거르므로.
//그러면 크다, 작다인데
//불 리턴이면 얘 없이 오퍼레이터 안에서 바로 하면 되지 않나..?
/*int asciiSum(const std::string& str) {
    int sum = 0;
    for (char ch : str) {
        sum += static_cast<int>(ch);
    }
    return sum;
}*/
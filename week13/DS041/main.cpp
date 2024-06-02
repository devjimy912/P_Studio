#include "stackIntList.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main() {
    MyStackIntList list = MyStackIntList();

    string str;

    while(1){
        getline(cin, str);
        vector<string> words;
        string word;
        istringstream iss(str);
        while (iss >> word) {
            words.push_back(word);
        }
        if(word[0] == "push"){//push
            list.push(word[1]);
        }else if(word[0] == "pop"){//pop
            list.pop();
        }else if(word[0] == "peek"){//top, 아니 이거 원래 top인데
        //입력 예시에 peek 적어놓고 출력이 top이랑 같아
        //일단 입력 예시 따라 갑니다.
            cout << list.top() << endl;
        }else if(word[0] == "print"){//printAll
            list.printAll();
        }else if(word[0] == "clear"){//initialize
            list.initialize();
        }else if(word[0] == "q"){//quit
            list.~MyStackIntList();
            cout << "Bye!"<< endl;
            break;
        }
    }

    return 0;
}
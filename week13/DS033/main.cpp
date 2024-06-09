#include <iostream>
#include "CouponStack.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int size;
    cin >> size;
    CouponStack cs(10);

    string str;

    cin.ignore();
    while (1){
        getline(cin, str);

        vector<string> words;
        string word;
        istringstream iss(str);

        while (iss >> word) {
            words.push_back(word);
        }

        if(words[0] == "+"){ //push
            //coupon을 파라미터로 받아서 여기서 생성해줘야 함.
            coupon item;
            item.number = words[1];
            item.name = words[2];
            cs.push(item);
        }else if(words[0] == "-"){ //pop
            cout<<cs.pop()<<endl;
        }else if(words[0] == "q"){ //exit
            cs.~CouponStack();
            break;
        }else{
            cout << "Command : + : push (int), - : pop, q : exit" << endl;
        }
    }

    return 0;
}
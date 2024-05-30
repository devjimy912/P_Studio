#include <iostream>
#include <sstream>
#include "Stack.h"
#include <string>
#include <vector>

using namespace std;

int main(){
    int num;
    string str;
    cin >> num;

    Stack<int> stack(num);

    cin.ignore();
    while (1){
        getline(cin, str);

        vector<string> words;
        string word;
        istringstream iss(str);
        while (iss >> word) {
            words.push_back(word);
        }
        if(words[0] == "push"){
            stack.push(stoi(words[1]));
        }else if(words[0] == "pop"){
            stack.pop();
        }else if(words[0] == "print"){
            stack.print();
            break;
        }else{
            cout << "Command : push (int), pop, print" << endl;
        }
    }

    return 0;
}
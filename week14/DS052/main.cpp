#include "MyCircularQueue.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
cd "/Users/jeonjimyeong/Developer/P_Studio/week14/DS052/" && g++ main.cppMyCircularQueue.cpp -o main && "/Users/jeonjimyeong/Developer/P_Studio/week14/DS052/"main
*/

int main(){
    int num;
    string str;
    cin >> num;

    MyCircularQueue que(num);

    int n;

    cin.ignore();
    while (1){
        getline(cin, str);

        vector<string> words;
        string word;
        istringstream iss(str);

        while (iss >> word) {
            words.push_back(word);
        }

        if(words[0] == "en"){ //enqueue
            //need fix - finish
            que.enqueue(stoi(words[1]));
        }else if(words[0] == "de"){ //dequeue
            que.dequeue();
        }else if(words[0] == "front"){ //Front, dequeue, isEmpty -1
            n = que.isEmpty() ? -1 : que.Front().num;
            cout<<"=> "<< n <<endl;
            que.dequeue();
        }else if(words[0] == "rear"){ //Rear, isEmpty -1
            n = que.isEmpty() ? -1 : que.Rear().num;
            cout<<"=> "<< n <<endl;
        }else if(words[0] == "size"){ //size
            cout<<"=> "<<que.size()<<endl;
        }else if(words[0] == "empty"){ //isEmpty
            n = que.isEmpty() ? 1 : 0;
            cout<<"=> "<< n <<endl;
        }else if(words[0] == "print"){ //print
            //need fix - finish
            que.print();
        }else if(words[0] == "q"){ //exit
            cout<<"bye!"<<endl;
            break;
        }else{//print command list
            cout << "en : enqueue" << endl;
            cout << "de : dequeue" << endl;
            cout << "front : Front, dequeue, isEmpty -1" << endl;
            cout << "rear : Rear, isEmpty -1" << endl;
            cout << "size : size" << endl;
            cout << "empty : isEmpty" << endl;
            cout << "print : print" << endl;
            cout << "q : exit" << endl;
        }
    }
}
#include <iostream>

using namespace std;

void ltrim(string& str);
void rtrim(string& str);
int lastWordSize(string str);

int main(){
    string str;

    getline(cin, str);

    ltrim(str);
    rtrim(str);
    
    // cout << str << endl;
    cout << lastWordSize(str) << endl;

    return 0;
}

int lastWordSize(string str){
    int size;
    int start;
    for(int i=str.length(); i>0; i--){
        if(str[i] == ' ' || str[i] == '\t'){
            start = i;
            break;
        }
    }
    size = str.length() - start - 1;
    return size;
}

void rtrim(string& str){
    for(int i=str.length()-1; i > -1; i--){
        if(str[i] == '\t' || str[i] == ' '){
            str.erase(i,1);
        }
        if(isalnum(str[i])){
            break;
        }
    }
}

void ltrim(string& str){
    for(int i=0; i<str.length(); i++){
        if(str[i] == '\t' || str[i] == ' '){
            str.erase(i,1);
        }
        if(isalnum(str[i])){
            break;
        }
        i--;
    }
}
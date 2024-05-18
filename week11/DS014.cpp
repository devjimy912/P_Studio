#include <iostream>

using namespace std;

void ltrim(string& str);
void rtrim(string& str);

int main(){
    string str;

    getline(cin, str);

    // cout << str << endl;

    ltrim(str);
    rtrim(str);
    

    cout << str << endl;


    return 0;
}

void ltrim(string& str){
    // cout<<"ltrim called"<<endl;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '\t' || str[i] == ' '){
            str.erase(i,1);
        }
        if(isalnum(str[i])){
            
            break;
        }
        i--;
    }
    // cout<<"ltrim end"<<endl;
}

void rtrim(string& str){
    // cout<<"rtrim called"<<endl;
    for(int i=str.length()-1; i > -1; i--){
        if(str[i] == '\t' || str[i] == ' '){
            str.erase(i,1);
        }
        if(isalnum(str[i])){
            break;
        }
    }
    // cout<<"rtrim end"<<endl;
}
#include <iostream>

using namespace std;

typedef struct{
    string name;
    int price;
    string madeby;
}product;

bool check(product a, product b);
string toUpper(string str);

int main(){
    product control;
    product experimental;
    cin >> control.name >> control.price >> control.madeby;
    cin >> experimental.name >> experimental.price >> experimental.madeby;

    cout << control.name << " and " << experimental.name << " is ";
    if(!check(control, experimental)){
        cout << "not ";
    }
    cout << "equal." << endl;

    return 0;
}

bool check(product a, product b){
    bool equal = true;

    //toUpper
    toUpper(a.name);
    toUpper(a.madeby);
    toUpper(b.name);
    toUpper(b.madeby);

    // not equal
    if(a.name != b.name || a.price != b.price || a.madeby != b.madeby){
        equal = false;
    }

    return equal;
}

string toUpper(string str){
    for(int i=0; i<str.length(); i++){
        if(islower(str[i])){
            str[i] -= 32;
        }
    }
    return str;
}
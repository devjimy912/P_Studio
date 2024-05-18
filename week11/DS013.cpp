#include <iostream>

using namespace std;

struct Menu{
    string name;
    int price;
};

struct Cafe{
    string name;
    int menuCount;
    Menu* menuList;
};

void AddCafe(Cafe& cafe);
void AddMenu(Menu& menu);
void displayMenus(Cafe& cafe);
void printMenu(Menu& menu);

int main(){
    Cafe cafe;
    AddCafe(cafe);
    cafe.menuList = new Menu[cafe.menuCount];
    //input menu info.
    for(int i=0; i<cafe.menuCount; i++){
        AddMenu(cafe.menuList[i]);
    }

    displayMenus(cafe);

    return 0;
}

void AddCafe(Cafe& cafe){
    getline(cin, cafe.name);
    cin >> cafe.menuCount;
}

void AddMenu(Menu& menu){
    cin >> menu.name;
    cin >> menu.price;
}

void displayMenus(Cafe& cafe){
    cout << "===== " << cafe.name << " =====" << endl;
    for(int i=0; i<cafe.menuCount; i++){
        printMenu(cafe.menuList[i]);
    }
    cout << "==================" << endl;
}

void printMenu(Menu& menu){
    cout << menu.name << " " << menu.price << endl;
}
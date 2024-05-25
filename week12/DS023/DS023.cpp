#include <iostream>

using namespace std;

class Product{
    public:
        string name;
        int price;
        int discountRate;
        string madeBy;
        string size;
        Product();
        void inputProductInfo();
        void printProductInfo();
        int discountCalculater();
};

Product* Add();
void printAll(Product* arr, int num);

int main(){
    int menu;
    bool dummy = true;
    int count = 0;
    Product* array = new Product[10];


    while(dummy){
        cout << "1. Add 2. List 3. Quit > ";
        cin >> menu;
        switch(menu){
            case 1:
                array[count] = *Add();
                count++;
                break;
            case 2:
                printAll(array, count);
                break;
            default:
                dummy = false;
                break;
        }
    }

    return 0;
}

Product* Add(){
    Product* p = new Product();
    p->inputProductInfo();
    return p;
}

void printAll(Product* arr, int num){
    for(int i=0; i<num; i++){
        arr[i].printProductInfo();
    }
}

Product::Product(){}

void Product::inputProductInfo(){
    cin.ignore();
    getline(cin, name);
    cin >> price >> discountRate >> size >> madeBy;
}

void Product::printProductInfo(){
    cout << discountCalculater() <<" ("<< discountRate <<"%) "<< name <<" "<< size <<" "<< madeBy <<endl;
}

int Product::discountCalculater(){
    int money;
    money = price*(100-discountRate)/100;
    return money;
}

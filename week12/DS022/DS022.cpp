#include <iostream>

using namespace std;

class ESG{
    private:
        string name;
        int LC;
        int RC;
    public:
        ESG();
        ESG(string name,int lc, int rc);
        string getName(){ return name; };
        void setName(string n){ name=n; };
        int getLC(){ return LC; };
        void setLC(int lc){ LC = lc; };
        int getRC(){ return RC; };
        void setRC(int rc){ RC = rc; };
        void printResult();
        string check(int score);
};

int main(){
    ESG esg;
    string name;
    int lc,rc;
    //이거 세터 외부가 아니라 그냥 따로 메소드 만들어서 cin으로 받는 걸 만들까..

    //이름 받기
    getline(cin, name);
    esg.setName(name);

    do{
        cout << "LC> ";
        cin >> lc;
    }while(lc<0 || lc> 495);
    esg.setLC(lc);

    do{
        cout << "RC> ";
        cin >> rc;
    }while(rc<0 || rc> 495);
    esg.setRC(rc);

    esg.printResult();

    return 0;
}

ESG::ESG(){}

ESG::ESG(string name, int lc, int rc){
    this->name = name;
    this->LC = lc;
    this->RC = rc;
}

void ESG::printResult(){
    cout << "["<<name<<"]"<<endl;
    cout << "LC - " << LC << check(LC) << endl;
    cout << "RC - " << RC << check(RC) << endl;
    cout << "Total - " << LC+RC << endl;
}

string ESG::check(int score){
    if(score < 350){
        return "Fail";
    }else{
        return "Pass";
    }
}

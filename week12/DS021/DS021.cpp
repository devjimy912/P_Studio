#include <iostream>

using namespace std;

class Student{
    private:
        double getAvg() const;
    public:
        string name;
        string sid;
        int* score;
        void print() const;
};

int main(){
    Student student;
    student.score = new int[3];

    cin >> student.sid >> student.score[0] >> student.score[1] >> student.score[2];

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, student.name);

    student.print();

    return 0;
}

double Student::getAvg() const{
    return (score[0]+score[1]+score[2])/3.0;
}

void Student::print() const{
    cout << fixed;
    cout.precision(1);
    cout<<"["<<sid<<"] "<<name<<endl;
    cout<<"The Average Score is "<<getAvg()<<endl;
}

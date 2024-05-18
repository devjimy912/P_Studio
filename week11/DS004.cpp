#include <iostream>

using namespace std;

#define CHECK(n) (n<70) ? "Fail" : "Pass"

typedef struct{
    int kor, eng, math;
    int total;
    double average;
}st_score;

int main(){
    st_score score;

    cin >> score.kor >> score.eng >> score.math;

    score.total = score.kor + score.eng + score.math;

    score.average = score.total / 3.0;

    cout << score.total << " " << score.average << endl;
    string str = CHECK(score.kor);
    cout << "Korean - " << str << endl;
    str = CHECK(score.eng);
    cout << "English - " << str<< endl;
    str = CHECK(score.math);
    cout << "Math - " << str<< endl;

    return 0;
}
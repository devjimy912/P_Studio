#include <iostream>

using namespace std;

int main(){
    int day, month;
    int day_count;

    cin >> month >> day;

    day_count = 0;

    switch (month)
    {
    case 12:
        day_count += 30;
    case 11:
        day_count += 31;
    case 10:
        day_count += 30;
    case 9:
        day_count += 31;
    case 8:
        day_count += 31;
    case 7:
        day_count += 30;
    case 6:
        day_count += 31;
    case 5:
        day_count += 30;
    case 4:
        day_count += 31;
    case 3:
        day_count += 28;
    case 2:
        day_count += 31;
    default:
        day_count += day;
        cout << day_count << endl;
        break;
    }

    return 0;
}
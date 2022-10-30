#include "Date.h"
#include "Part_1.h"
#include "IError.h"

void check(int a) {
    if (cin.fail()) {
        cin.clear();
        a = 0;
        cin.ignore();
        throw IncorrectInput();
    }
}



int main()//тесты
{

    menu_patr_1();

    /*Date a(2022,Oct,30,30,54,21);
    Date b(2022, Oct, 30);
    Date c(30, 54, 21);
    Date d;
    
    cout << "Dates" << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d.toString() << endl;
    
    cout << "Add" << endl;

    cout << b.addYears(5) << endl;
    cout << c.addMinutes(12) << endl;

    cout << "Intervals" << endl;

    cout << a.getIntevals(a) << endl;
    cout << b.getIntevals(a) << endl;
    cout << c.getIntevals(a) << endl;
    cout << d.getIntevals(a) << endl;

    string s = "2020 year 28 Jun 13:43:00 asdasdasdasd";*/
}
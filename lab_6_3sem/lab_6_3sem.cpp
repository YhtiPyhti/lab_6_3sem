#include "Date.h"
#include "Part_1.h"
#include "IError.h"

int main()
{

    //menu_patr_1();

    Date a(2022,Oct,30,30,54,21);
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
    cout << endl;

    try {
        string s;
        cout << "Input your text with date (Month, number, year, hours, min, sec your text): ";
        getline(cin,s);

        DateInterval red;

       cout << red.formatDate(s);
    }
    catch (IncorrectInput& e) {
        e.print();
        main();
    }
}
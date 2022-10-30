#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "IError.h"

DateInterval Date::getIntevals(const Date& another) const {
    int year = this->year - another.year;
    int month = this->month - another.month;
    int day = this->day - another.day;
    int hour = this->hour - another.hour;
    int min = this->min - another.min;
    int sec = this->sec - another.sec;
    return DateInterval(Year(year), Month_enum(month), Day(day), Hour(hour), Min(min), Sec(sec));
}
Date::Date() {
    time_t now = time(0);
    tm* dt = localtime(&now);
    year = 1900 + dt->tm_year;
    month = 1 + dt->tm_mon;
    day = dt->tm_wday;
    hour = dt->tm_hour;
    min = dt->tm_min;
    sec = dt->tm_sec;
}
Date::Date(Year a, Month_enum b, Day c, Hour d, Min f, Sec e) {

    sec = e.sec % 60;
    (e.sec / 60 > 0) ? count++ : count;

    min = (f.min + count) % 60;
    (f.min + count / 60 > 0) ? count++ : count;
    (count > 1) ? count-- : count;

    hour = (d.hour + count) % 24;
    (d.hour + count / 24 > 0) ? count++ : count;
    (count > 1) ? count-- : count;

    day = c.day;
    month = b;

    if (month % 2 == 1 || month == Aug && day / 31 > 0) {
        day %= 32;
        month++;
        day++;
    }
    else if (month == Feb) {
        (year % 4 == 0) ? day %= 29 : day %= 30;
        month++;
        day++;
    }
    else if (month % 2 == 1 && day / 30 > 0) {
        day %= 31;
        month++;
        day++;
    }
    else {
        day = (count + day);
    }

    if (month / 12 > 0) {
        month %= 12;
        year++;
    }

    year += a.year % 10000;
}
Date::Date(unsigned int year, Month_enum m, unsigned int day) {
    this->year = year % 10000;
    month = m;
    this->day = day;
    if (month % 2 == 1 || month == Aug && day / 31 > 0) {
        this->day %= 32;
        month++;
        this->day++;
    }
    else if (month == Feb) {
        (year % 4 == 0) ? this->day %= 29 : this->day %= 30;
        month++;
        this->day++;
    }
    else if (month % 2 == 1 && day / 30 > 0) {
        this->day %= 31;
        month++;
        this->day++;
    }

    if (month / 12 > 0) {
        month %= 12;
        year++;
    }
}
Date::Date(unsigned int hrs, unsigned int mnts, unsigned int seconds) {
    time_t now = time(0);
    tm* dt = localtime(&now);
    year = 1900 + dt->tm_year;
    month = 1 + dt->tm_mon;
    day = dt->tm_wday;

    sec = seconds % 60;
    (seconds / 60 > 0) ? count++ : count;

    min = (mnts + count) % 60;
    (mnts + count / 60 > 0) ? count++ : count;
    count--;

    hour = (hrs + count) % 24;
    (hrs + count / 24 > 0) ? count++ : count;
    count--;
}
Date::Date(const Date& a) {
    year = a.year;
    month = a.month;
    day = a.day;
    hour = a.hour;
    min = a.min;
    sec = a.sec;
}

Date Date::addYears(int a) {
    Date newDate;

    newDate.year = (this->year + a) % 10000;

    return newDate;
}
Date Date::addMonths(int a) {
    Date newDate;

    newDate.month = (this->month + a) % 13;
    (newDate.month == 0) ? newDate.month++ : newDate.month;

    return newDate;
}
Date Date::addDays(int a) {
    Date newDate;

    newDate.day = (this->day + a) % 31;
    (newDate.day == 0) ? newDate.day++ : newDate.day;
    return newDate;
}
Date Date::addHours(int a) {
    Date newDate;

    newDate.hour = (this->hour + a) % 24;

    return newDate;
}
Date Date::addMinutes(int a) {
    Date newDate;

    newDate.min = (this->min + a) % 60;

    return newDate;
}
Date Date::addSeconds(int a) {
    Date newDate;

    newDate.sec = (this->sec + a) % 60;

    return newDate;
}

string Date::toString() const {
    stringstream ss;
    ss << year << "-" << arr[month - 1] << "-" << day << "  " << hour << "::" << min << "::" << sec;
    return ss.str();
}


DateInterval::DateInterval() {
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    min = 0;
    sec = 0;
}
DateInterval::DateInterval(Year a, Month_enum b, Day c, Hour d, Min f, Sec e) {

    sec = e.sec % 60;
    (e.sec / 60 > 0) ? count++ : count;

    min = (f.min + count) % 60;
    (f.min + count / 60 > 0) ? count++ : count;
    (count > 1) ? count-- : count;

    hour = (d.hour + count) % 24;
    (d.hour + count / 24 > 0) ? count++ : count;
    (count > 1) ? count-- : count;

    day = c.day;
    month = b;

    if (month % 2 == 1 || month == Aug && day / 31 > 0) {
        day %= 32;
        month++;
        day++;
    }
    else if (month == Feb) {
        (year % 4 == 0) ? day %= 29 : day %= 30;
        month++;
        day++;
    }
    else if (month % 2 == 1 && day / 30 > 0) {
        day %= 31;
        month++;
        day++;
    }
    else {
        day = (count + day);
    }

    if (month / 12 > 0) {
        month %= 12;
        year++;
    }

    year += a.year % 10000;
}

DateInterval::DateInterval(int year, Month_enum m, int day) {
    this->year = year % 10000;
    month = m;
    this->day = day;
    if (month % 2 == 1 || month == Aug && day / 31 > 0) {
        this->day %= 32;
        month++;
        this->day++;
    }
    else if (month == Feb) {
        (year % 4 == 0) ? this->day %= 29 : this->day %= 30;
        month++;
        this->day++;
    }
    else if (month % 2 == 1 && day / 30 > 0) {
        this->day %= 31;
        month++;
        this->day++;
    }

    if (month / 12 > 0) {
        month %= 12;
        year++;
    }
}

DateInterval::DateInterval(unsigned int hrs, unsigned int mnts, unsigned int seconds) {
    year = 0;
    month = 0;
    day = 0;
    sec = seconds % 60;
    (seconds / 60 > 0) ? count++ : count;

    min = (mnts + count) % 60;
    (mnts + count / 60 > 0) ? count++ : count;
    count--;

    hour = (hrs + count) % 24;
    (hrs + count / 24 > 0) ? count++ : count;
    count--;
}
DateInterval::DateInterval(const DateInterval& a) {
    year = a.year;
    month = a.month;
    day = a.day;
    hour = a.hour;
    min = a.min;
    sec = a.sec;
}
//Monday, June 15,2009 1:45:30 PM xcvzxc 32 qwe x23 2q3 aasd
string DateInterval::formatDate(string format) {
    string s;
    stringstream ss;
    int a = 0, k = 0;
    int arr_num[7];
    bool end = false;
    for (size_t i = 0; i < format.size(); i++)
    {
        for (size_t j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (format[i] == arr[j][0] && format[i + 1] == arr[j][1] && format[i + 2] == arr[j][2]) {
                arr_num[k] = j + 1;
                k++;
            }
        }

        if (!end && format[i] >= 48 && format[i] <= 57) {
            a *= 10;
            a += (format[i] - 48);
        }
        else if (!end && (format[i] == ',' || format[i] == ' ' || format[i] == ':') && a != 0) {
            arr_num[k] = a;
            a = 0;
            k++;
        }
        else if (!end && (format[i] == 'P' || format[i] == 'A') && format[i + 1] == 'M') {
            arr_num[k] = format[i];
            end = true;
        }
        else if (end) {
            s = format.substr(i + 1, format.size());
            break;
        }
    }

    if (k < 6) throw IncorrectInput();

    if (arr_num[6] == 80) {
        arr_num[3] += 12;
        arr_num[3] %= 24;
    }

    ss << "Date: " << arr_num[2] << "/" << arr_num[0] << "/" << arr_num[1] << " " << arr_num[3] << ":" << arr_num[4] << ":" << arr_num[5] << "\nText:" << s;
    return ss.str();
}
#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

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
    string arr[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sem","Oct","Nov","Dec" };
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

string DateInterval::formatDate(string format) {
    string s;
    for (size_t i = 0; i < format.size(); i++)
    {
        if (format[i] == ' ') {

        }
        else s += format[i];
    }
    return s;
}
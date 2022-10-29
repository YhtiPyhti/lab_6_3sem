#pragma once
#include "Fraction.h"
enum Month_enum
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sem,
    Oct,
    Nov,
    Dec
};

struct Year {
    int year;
    Year(int a) {
        year = a;
    }
};
struct Day {
    int day;
    Day(int a) {
        day = a;
    }
};
struct Hour {
    int hour;
    Hour(int a) {
        hour = a;
    }
};
struct Min {
    int min;
    Min(int a) {
        min = a;
    }
};
struct Sec {
    int sec;
    Sec(int a) {
        sec = a;
    }
};

class DateInterval {
public:

    DateInterval();

    DateInterval(Year a, Month_enum b, Day c, Hour d, Min f, Sec e);

    DateInterval(int year, Month_enum m, int day);

    DateInterval(unsigned int hrs, unsigned int mnts, unsigned int seconds);

    DateInterval(const DateInterval& a);

    int get_Year() {
        return year;
    }
    int get_Month() {
        return month;
    }
    int get_Day() {
        return day;
    }
    int get_Hour() {
        return hour;
    }
    int get_Min() {
        return min;
    }
    int get_Sec() {
        return sec;
    }

    string formatDate(string format);

    friend ostream& operator<<(ostream& os, const DateInterval& a) {
        os << "Interval: " << a.year << "/" << a.month << "/" << a.day << "  " << a.hour << ":" << a.min << ":" << a.sec;
        return os;
    }
    friend istream& operator>>(istream& is, DateInterval& a) {
        is >> a.year >> a.month >> a.day >> a.hour >> a.min >> a.sec;
        return is;
    }

protected:
    int count = 0, year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;

};

class Date {
public:
    Date();
    Date(Year a, Month_enum b, Day c, Hour d, Min f, Sec e);
    Date(unsigned int year, Month_enum m, unsigned int day);
    Date(unsigned int hrs, unsigned int mnts, unsigned int seconds);
    Date(const Date& a);

    Date addYears(int a);
    Date addMonths(int a);
    Date addDays(int a);
    Date addHours(int a);
    Date addMinutes(int a);
    Date addSeconds(int a);

    const int get_Year() {
        return year;
    }
    const int get_Month() {
        return month;
    }
    const int get_Day() {
        return day;
    }
    const int get_Hour() {
        return hour;
    }
    const int get_Min() {
        return min;
    }
    const int get_Sec() {
        return sec;
    }

    string toString() const;

    friend ostream& operator<<(ostream& os, const Date& a) {
        os << "Data now: " << a.year << "/" << a.month << "/" << a.day << "  " << a.hour << ":" << a.min << ":" << a.sec;
        return os;
    }

    friend istream& operator>>(istream& is, Date& a) {
        is >> a.year >> a.month >> a.day >> a.hour >> a.min >> a.sec;
        return is;
    }

    DateInterval getIntevals(const Date& another) const;

private:
    int count = 0, year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;
};



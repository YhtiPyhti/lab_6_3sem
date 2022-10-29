#pragma once
#include <iostream>
#include <chrono>
#include <sstream>
using namespace std;

struct Numerator {
    int num;
    Numerator(const int& a) {
        num = a;
    }
};

struct Denominator {
    int den;
    Denominator(const int& a) {
        den = a;
    }
};

class Fraction {
public:
    Fraction();

    Fraction(Numerator a, Denominator b);

    friend ostream& operator<<(ostream& os, const Fraction& a) {
        os << a.num << " / " << a.den;
        return os;
    }

    friend istream& operator>>(istream& is,Fraction& a) {
        
        cout << "Numerator : ";
        is >> a.num;

        cout << "Denominator : ";
        is >> a.den;

        return is;
    }

    Fraction operator+(const Fraction& number1);

    Fraction operator-(const Fraction& number1);

    Fraction operator/(Fraction number1);

    Fraction operator*(const Fraction& number1);

    Fraction pow(const Fraction& number1, int a);

    bool operator<(const Fraction& number1);

    bool operator>(const Fraction& number1);

    bool operator==(const Fraction& number1);

    bool operator<=(const Fraction& number1);

    bool operator>=(const Fraction& number1);

    bool operator!=(const Fraction& number1);

    int get_num();

    int get_den();

    string get_log();

    void set(const Numerator& a, const Denominator& b);

private:
    int num, den;
    string log;
    int nod(int a, int b);
};

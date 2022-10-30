#include "Fraction.h"
#include "IError.h"
Fraction::Fraction() {
    log += "CREATE OBJECT\n";
    num = 0;
    den = 1;
}

Fraction::Fraction(Numerator a, Denominator b) {
    if (b.den == 0) {
        throw DivisionByZero();
    }

    num = a.num / abs(nod(a.num, b.den));
    den = b.den / abs(nod(a.num, b.den));

    if (den < 0 && num > 0) {
        den *= -1;
        num *= -1;
    }
    else if (den < 0 && num < 0) {
        den *= -1;
        num *= -1;
    }

    log += "CREATE OBJECT\n";
}

Fraction Fraction::operator+(const Fraction& number1) {
    log += "ADD OBJECT\n";
    if (number1.den == this->den) {
        return Fraction(Numerator(this->num + number1.num), Denominator(this->den));
    }
    else {
        int sum_den = number1.den * this->den;
        int sum_num = number1.num * this->den + this->num * number1.den;
        return Fraction(Numerator(sum_num), Denominator(sum_den));
    }
}

Fraction Fraction::operator-(const Fraction& number1) {
    log += "SUBTRACT OBJECT\n";
    if (number1.den == this->den) {
        return Fraction(Numerator(this->num - number1.num), Denominator(number1.den));
    }
    else {
        int sum_den = number1.den * this->den;
        int sum_num = this->num * number1.den - number1.num * this->den;
        return Fraction(Numerator(sum_num), Denominator(sum_den));
    }
}

Fraction Fraction::operator/(Fraction number1) {
    swap(number1.num, number1.den);
    log += "DIVISION OBJECT\n";
    return Fraction(number1.num * this->num, number1.den * this->den);
}

Fraction Fraction::operator*(const Fraction& number1) {
    log += "MULTIPLICATION OBJECT\n";
    return Fraction(number1.num * this->num, number1.den * this->den);
}

Fraction Fraction::pow(const Fraction& number1, int a) {
    int num_degree = number1.num, den_degree = number1.den;
    bool invert = false;
    if (a < 0) {
        a *= -1;
        invert = true;
    }
    while (a != 1) {
        num_degree *= number1.num;
        den_degree *= number1.den;
        a--;
    }
    if (invert)swap(num_degree, den_degree);
    log += "DEGREE OPERATOR\n";
    return Fraction(num_degree, den_degree);
}

bool Fraction::operator<(const Fraction& number1) {
    log += "LESS OPERATOR\n";
    if (number1.den == this->den) {
        return this->num < number1.num;
    }
    else return this->num * number1.den < number1.num* this->den;
}

bool Fraction::operator>(const Fraction& number1) {
    log += "LESS OPERATOR\n";
    if (number1.den == this->den) {
        return this->num > number1.num;
    }
    else return this->num * number1.den > number1.num * this->den;
}

bool Fraction::operator==(const Fraction& number1) {
    log += "EQUALS OPERATOR\n";
    if (number1.den == this->den) {
        return this->num == number1.num;
    }
    else return this->num * number1.den == number1.num * this->den;
}

bool Fraction::operator<=(const Fraction& number1) {
    log += "EQUALS OR LESS OPERATOR\n";
    if (number1.den == this->den) {
        return this->num <= number1.num;
    }
    else return this->num * number1.den <= number1.num * this->den;
}

bool Fraction::operator>=(const Fraction& number1) {
    log += "EQUALS OR MORE OPERATOR\n";
    if (number1.den == this->den) {
        return this->num >= number1.num;
    }
    else return this->num * number1.den >= number1.num * this->den;
}

bool Fraction::operator!=(const Fraction& number1) {
    log += "NOT EQUALS OPERATOR\n";
    if (number1.den == this->den) {
        return this->num != number1.num;
    }
    else return this->num * number1.den != number1.num * this->den;
}

int Fraction::get_num() {
    log += "GET NUMERATOR VALUES\n";
    return num;
}

int Fraction::get_den() {
    log += "GET DENOMINATOR VALUES\n";
    return den;
}

string Fraction::get_log() {
    log += "GET LOG VALUES\n";
    return log;
}

void Fraction::set(const Numerator& a, const Denominator& b) {
    if (b.den == 0) {
        throw DivisionByZero();
    }
    log += "SET VALUES\n";
    num = a.num;
    den = b.den;

}

int Fraction::nod(int a, int b)
{
    int t;
    if (a < b) { t = a; a = b; b = t; }
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
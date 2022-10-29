#pragma once
#include <vector>
#include "Fraction.h"

enum instraction {
    OUTPUT = 1,
    INPUT,
    ADD,
    SUB,
    MAXIMAZE,
    MORE,
    LESS,
    EQUAL,
    NEQUAL,
    MEQUAL,
    LEQUAL,
    LOG,
    EXIT
};

void output(const vector<Fraction>& many_number);

void check();

int check_input_1_num(const vector<Fraction>& many_number);

int check_input_2_num(const vector<Fraction>& many_number);

void menu_patr_1();
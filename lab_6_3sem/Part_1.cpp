#include "Part_1.h"
#include "IError.h"
void output(const vector<Fraction>& many_number) {
    int j = 0;
    for (auto i : many_number) {
        cout  << j << ") " << i << endl;
        j++;
    }
}

void func_err(int a) {
    if (cin.fail()) {
        cin.clear();
        throw IncorrectInputCritical();
    }
}

void check_input_num(const int& k, const vector<Fraction>& many_number) {
    func_err(k);
    if (k >= many_number.size()) {
        throw IncorrectInput();
    }
}

void menu_patr_1() {
    int choise = 0;
    vector<Fraction> many_number;
    try {
        Fraction number(Numerator(7), Denominator(23));
        many_number.push_back(number);

        number.set(Numerator(3), Denominator(23));
        many_number.push_back(number);
        cout << "Enter your own values (1) or use the program (2)?\n";
        cin >> choise;
        func_err(choise);
        if (choise != 1 && choise != 2) {
            choise = 0;
            throw IncorrectInput();
        }


        if (choise == 1) {
            cout << "How many?\n";
            choise = 0;

            cin >> choise;
            func_err(choise);

            while (choise)
            {
                int num, dec;
                cout << "Numerator: ";
                cin >> num;
                cout << "Denominator: ";
                cin >> dec;
                number.set(num, dec);
                many_number.push_back(number);
                choise--;
            }
        }

        while (true) {
            int k, m;

            cout << "\nWhat kind operation would you like?\n"
                << "1) Output (text)\n"
                << "2) Input (values)\n"
                << "3) Add (+)\n"
                << "4) Submition (-)\n"
                << "5) maximize (^)\n"
                << "6) Compare for more (>)\n"
                << "7) Compare by less (<)\n"
                << "8) Compare equal (==)\n"
                << "9) Compare NOT equal (!=)\n"
                << "10) Compare on more or equal (>=)\n"
                << "11) Compare on less or equal (<=)\n"
                << "12) Input log\n"
                << "13) Exit\n";

            choise = 0;

            cin >> choise;
            func_err(choise);


            switch (choise)
            {
            case OUTPUT:
                output(many_number);
                break;
            case INPUT:
                cout << "How many: ";
                choise = 0;
                cin >> choise;
                func_err(choise);

                while (choise)
                {
                    int num, dec;
                    cout << "Numerator: ";
                    cin >> num;
                    cout << "Denominator: ";
                    cin >> dec;
                    number.set(num, dec);
                    many_number.push_back(number);
                    choise--;
                }
                break;

            case ADD:

                output(many_number);
                cin >> k;
                check_input_num(k, many_number);
                cin >> m;
                check_input_num(m, many_number);

                number = many_number[k] + many_number[m];
                cout << number;
                many_number.push_back(number);
                break;

            case SUB:

                output(many_number);
                cin >> k;
                check_input_num(k, many_number);
                cin >> m;
                check_input_num(m, many_number);

                number = many_number[k] - many_number[m];
                cout << number;
                many_number.push_back(number);
                break;
            case MAXIMAZE:

                output(many_number);

                cout << "What?\nInput number : ";
                k = 0;
                m = 0;
                cin >> k;
                func_err(k);

                if (k - 1 >= many_number.size()) {
                    throw IncorrectInput();
                }

                cout << "Degree : ";
                cin >> m;
                func_err(m);

                number = number.pow(many_number[k - 1], m);
                cout << number;
                many_number.push_back(number);
                break;


            case MORE:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);

                if (many_number[k] > many_number[m]) {
                    cout << many_number[k] << " number more, then " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number less, then " << many_number[m] << endl;

                break;
            case LESS:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);
                if (many_number[k] < many_number[m]) {
                    cout << many_number[k] << " number more, then " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number less, then " << many_number[m] << endl;
                break;

            case EQUAL:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);
                if (many_number[k] == many_number[m]) {
                    cout << many_number[k] << " number equal number " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number not equal number " << many_number[m] << endl;

                break;


            case NEQUAL:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);
                if (many_number[k] != many_number[m]) {
                    cout << many_number[k] << " number equal number " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number not equal number " << many_number[m] << endl;

                break;


            case MEQUAL:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);

                if (many_number[k] >= many_number[m]) {
                    cout << many_number[k] << " number more or equal, then " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number less or equal, then " << many_number[m] << endl;
                break;

            case LEQUAL:

                output(many_number);
                cout << "Input first number: ";
                cin >> k;
                check_input_num(k, many_number);


                cout << "Input second number: ";
                cin >> m;
                check_input_num(m, many_number);

                if (many_number[k] <= many_number[m]) {
                    cout << many_number[k] << " number more or equal, then " << many_number[m] << endl;
                }
                else cout << many_number[k] << " number less or equal, then " << many_number[m] << endl;
                break;
            case LOG:

                for (size_t i = 0; i < many_number.size(); i++)
                {
                    cout << "Number " << i + 1 << ") " << many_number[i] << "\n" << many_number[i].get_log() << endl;
                }
                break;

            case EXIT:
                cout << "Bay!";
                exit(1);
            default:
                throw IncorrectInput();
            }
        }
    }
    catch (IncorrectInputCritical& e) {
        e.print();
        exit(0);
    }
    catch (IncorrectInput& e) {
        e.print();
        choise = 0;
        menu_patr_1();
    }
    catch (DivisionByZero& e) {
        e.print();
        menu_patr_1();
    }
}